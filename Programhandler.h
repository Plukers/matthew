#ifndef PROGRAMHANDLERSTATIC_H
#define PROGRAMHANDLERSTATIC_H

#include <QObject>
#include <QString>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <unordered_map>

class ProgramHandler
{
public:
	static int initializePrograms();
	static std::shared_ptr<QOpenGLShaderProgram> getProgram(QString programName);


private:
	ProgramHandler(){};
	static int addProgram(QString programName, QString vertexPath, QString fragmentPath);
	static int addProgram(QString programName, QString computePath);
	static int addProgram(QString programName, QString vertexPath, QString fragmentPath,
				   QString tesselationEvaluationPath, QString tesselationControlPath,
				   QString geometryPath);



};

#endif // PROGRAMHANDLERSTATIC_H
