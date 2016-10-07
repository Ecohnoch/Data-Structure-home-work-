#include <QGuiApplication>
#include <QQuickView>
#include "robotfile.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    qmlRegisterSingletonType<RobotFile>("File", 1, 0, "File", &RobotFile::qmlSingleton);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
