#include <QCoreApplication>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
      QCoreApplication::translate("title", "Matthew - Material Viewer"));

    return a.exec();
}
