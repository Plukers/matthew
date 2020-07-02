#include <QApplication>
#include <QtWidgets/QWidget>
#include <QGridLayout>

#include <memory>

#include "RenderWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    auto layout{std::make_unique<QGridLayout>()};

    auto renderWidget{std::make_unique<RenderWidget>()};
    layout->addWidget(renderWidget.release());

    QWidget window;
    window.resize(320, 240);
    window.setWindowTitle(
      QApplication::translate("window_title", "Matthew - Material Viewer"));
    window.setLayout(layout.release());
    window.show();
    return a.exec();
}
