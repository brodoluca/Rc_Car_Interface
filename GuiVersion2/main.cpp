#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QImage>
#include <QtGui>
#include <QLabel>
#include <QQuickImageProvider>

#include "backend.h"
#include "localserver.h"
#include "thread.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>


#include <opencv2/opencv.hpp>


//using namespace cv;






int main(int argc, char *argv[])
{

    QGuiApplication a(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<backend>("com.company.backendfirst", 1, 0, "BackEnd");

    //qmlRegisterType<thread>("com.company.local", 1, 0, "Local");
   // backend* myNew = new backend();
 thread mythread;
    engine.rootContext()->setContextProperty("backend",mythread.back);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    mythread.start();

    return a.exec();
}
