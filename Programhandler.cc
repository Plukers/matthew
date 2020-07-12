#include "Programhandler.h"
#include <iostream>
#include <iterator>

// *****************************************************************************
ProgramHandler::ProgramHandler()
// *****************************************************************************
{

}

// *****************************************************************************
ProgramHandler::~ProgramHandler()
// *****************************************************************************
{
	// destroy programs before shaders because programs have pointers to shaders
	programs.clear();
	shaders.clear();


}

// *****************************************************************************
int ProgramHandler::initializePrograms()
// *****************************************************************************
{
	int err=0;
	// Insert programs here!
	// err = ProgramHandler::addProgram("simpleProgram", "shader/simple.vs", "shader/simple.fs");
	err += ProgramHandler::addProgram("colorProgram", "assets/shaders/color.vs", "assets/shaders/color.fs");

	if(err == 0){
		std::cout << "shaders compiled successfully!" << std::endl;
	}

	return err;
}

// *****************************************************************************
std::shared_ptr<QOpenGLShaderProgram> ProgramHandler::bindProgram(QString programName)
// *****************************************************************************
{
	auto program = programs[programName];
	if(program == 0){
		std::cout << "program not found!" << std::endl;
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
