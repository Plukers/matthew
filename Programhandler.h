#ifndef PROGRAMHANDLERSTATIC_H
#define PROGRAMHANDLERSTATIC_H

#include <QString>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class ProgramHandler
{

public:
	enum Programs{
		simpleProgram,
		colorProgram
	};

	static int initializePrograms();
	static std::shared_ptr<QOpenGLShaderProgram> getProgram(Programs programName);
	~ProgramHandler();

private:
	ProgramHandler(){};
	static int addProgram(Programs programName, QString vertexPath, QString fragmentPath);
	static int addProgram(Programs programName, QString computePath);
	static int addProgram(Programs programName, QString vertexPath, QString fragmentPath,
				   QString tesselationEvaluationPath, QString tesselationControlPath,
				   QString geometryPath);
	static int addShader(std::shared_ptr<QOpenGLShaderProgram> program, QString shaderPath, QOpenGLShader::ShaderTypeBit shaderType);



};

#endif // PROGRAMHANDLERSTATIC_H
