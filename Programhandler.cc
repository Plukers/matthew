#include "Programhandler.h"

static std::map<QString, std::unique_ptr<QOpenGLShader>> shaders;
static std::map<int, std::shared_ptr<QOpenGLShaderProgram>> programs;
static bool initialized = false;

enum CompileError {
	noError = 0,
	shaderCompileError,
	vertexError,
	fragmentError,
	tesselationComputeError,
	tesselationEvalError,
	geometryError,
	computeError
};


// *****************************************************************************
int ProgramHandler::initializePrograms()
// *****************************************************************************
{
	if(initialized){
		return noError;
	}

	int err = noError;
	// Insert programs here! And make enum in header!
	err += ProgramHandler::addProgram(simpleProgram, "assets/shaders/simple.vs", "assets/shaders/simple.fs");
	err += ProgramHandler::addProgram(colorProgram, "assets/shaders/color.vs", "assets/shaders/color.fs");

	if(err == noError){
		qDebug() << "shaders compiled successfully!";
	}

	initialized = true;
	return err;
}

// *****************************************************************************
ProgramHandler::~ProgramHandler()
// *****************************************************************************
{
	// delete programs first
	programs.clear();
	shaders.clear();
}

// *****************************************************************************
std::shared_ptr<QOpenGLShaderProgram> ProgramHandler::getProgram(Programs programName)
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
int ProgramHandler::addProgram(Programs programName, QString vertexPath, QString fragmentPath)
// *****************************************************************************
{

	// use shared pointer for program because when later called it must be returned
	auto program = std::make_shared<QOpenGLShaderProgram>();

	addShader(program, vertexPath, QOpenGLShader::Vertex);
	addShader(program, fragmentPath, QOpenGLShader::Fragment);

	program->link();
	programs[programName] = program;
	return 0;
}

int ProgramHandler::addShader(std::shared_ptr<QOpenGLShaderProgram> program, QString shaderPath, QOpenGLShader::ShaderTypeBit shaderType)
{
	if(auto it = shaders.find(shaderPath); it != shaders.end()){
		program->addShader(it->second.get());
	}else{
		auto shader = std::make_unique<QOpenGLShader>(shaderType);
		if(!shader->compileSourceFile(shaderPath)){
			qDebug() << "shader failed to compile!";
			qDebug() << shader->log();
			return shaderCompileError;
		}
		program->addShader(shader.get());
		shaders[shaderPath] = std::move(shader);
	}
}


