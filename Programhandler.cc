#include "Programhandler.h"

static std::map<QString, std::unique_ptr<QOpenGLShader>> shaders;
static std::map<QString, std::shared_ptr<QOpenGLShaderProgram>> programs;

// *****************************************************************************
int ProgramHandler::initializePrograms()
// *****************************************************************************
{
	int err=0;
	// Insert programs here!
	err += ProgramHandler::addProgram("simpleProgram", "assets/shader/simple.vs", "assets/shader/simple.fs");
	err += ProgramHandler::addProgram("colorProgram", "assets/shaders/color.vs", "assets/shaders/color.fs");

	if(err == 0){
		qDebug() << "shaders compiled successfully!";
	}

	return err;
}


// *****************************************************************************
std::shared_ptr<QOpenGLShaderProgram> ProgramHandler::getProgram(QString programName)
// *****************************************************************************
{
	auto program = programs[programName];
	if(program == 0){
		qDebug() << "program not found!";
		return nullptr;
	}

	return program;

}

// *****************************************************************************
int ProgramHandler::addProgram(QString programName, QString vertexPath, QString fragmentPath)
// *****************************************************************************
{

	// use shared pointer for program because when later binded it must be returned
	auto program = std::make_shared<QOpenGLShaderProgram>();


	if(auto it = shaders.find(vertexPath); it != shaders.end()){
		program->addShader(it->second.get());
	}else{
		auto vs = std::make_unique<QOpenGLShader>(QOpenGLShader::Vertex);
		if(!vs->compileSourceFile(vertexPath)){
			qDebug() << "vertex shader failed to compile!";
			qDebug() << vs->log();
			return 1;
		}
		program->addShader(vs.get());
		shaders[vertexPath] = std::move(vs);
	}

	if(auto it = shaders.find(fragmentPath); it != shaders.end()){
		program->addShader(it->second.get());
	}else{
		auto fs = std::make_unique<QOpenGLShader>(QOpenGLShader::Fragment);
		if(!fs->compileSourceFile(fragmentPath)){
			qDebug() << "fragment shader failed to compile!";
			qDebug() << fs->log();
			return 2;
		}
		program->addShader(fs.get());
		shaders[fragmentPath] = std::move(fs);
	}

	program->link();
	programs[programName] = program;
	return 0;
}

