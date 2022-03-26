#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "semaphorcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<SemaphorController>("com.example.semaphorecontroller", 1, 0, "SemaphoreController");

    engine.load(QUrl("qrc:/main.qml"));

    if(engine.rootObjects().isEmpty()){
        return -1;
    }
    return app.exec();
}
