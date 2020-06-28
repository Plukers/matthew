#include <QApplication>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
      QApplication::translate("window_title", "Matthew - Material Viewer"));

    return a.exec();
}
