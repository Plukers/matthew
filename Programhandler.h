#ifndef PROGRAMHANDLER_H
#define PROGRAMHANDLER_H

#include <QObject>
#include <QString>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <unordered_map>

class ProgramHandler
{
public:
	ProgramHandler();
	~ProgramHandler();

	int initializePrograms();
	std::shared_ptr<QOpenGLShaderProgram> bindProgram(QString programName);

private:
	int addProgram(QString programName, QString vertexPath, QString fragmentPath);
	int addProgram(QString programName, QString computePath);
	int addProgram(QString programName, QString vertexPath, QString fragmentPath,
				   QString tesselationEvaluationPath, QString tesselationControlPath,
				   QString geometryPath);


	/*
	 *
typedef std::map<std::string, MyObj*> MyMap;
typedef std::pair<std::string, MyObj*> MyPair;
	 * */
	typedef std::map<QString, std::unique_ptr<QOpenGLShader>> ShaderMap;
	typedef std::pair<QString, std::unique_ptr<QOpenGLShader>> ShaderPair;
	ShaderMap shaders;

	typedef std::map<QString, std::shared_ptr<QOpenGLShaderProgram>> ProgramMap;
	typedef std::pair<QString, std::shared_ptr<QOpenGLShaderProgram>> ProgramPair;
	ProgramMap programs;
};

#endif // PROGRAMHANDLER_H
