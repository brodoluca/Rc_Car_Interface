#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

#include <QString>
#include <QUdpSocket>
#include <QDataStream>
#include <QTimer>

//class QTcpServer;

class localserver : public QTcpServer{


    Q_OBJECT

public slots:
    void newConnection();


public:

    //int right = 0;
   // int left = 0;
   // int center = 0;
   // int car = 0;
    void readyRead();
    QUdpSocket *socket;
     explicit localserver(QObject *parent=nullptr);

   // localserver();
    QTcpServer *server;



    void sendInformation(char data);

    //useless, very bad coding
    void go_forward(char forw);
    void go_backward(char back);
    void automatic_driving(char choice);
    void manual_mode(char choice);
    void direction_pad(char direction);
    void go_certain(char direction);
    void stream_camera(char camera);
    char get_center();

signals:
        void statusChanged(bool status);
private:

    QByteArray dataBuffer_;

    QHostAddress host;
    quint16 port;
    int number_x;
    char* Data_received;
    QTimer *timeoutTimer;
    bool status;


    QByteArray Data;
    QByteArray direction;


    void clearBuffer();
    size_t availableSlots();
    bool isFull();


};

#endif // LOCALSERVER_H
