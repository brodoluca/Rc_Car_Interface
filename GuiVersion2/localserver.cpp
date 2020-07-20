#include <QTcpServer>
#include <QDebug>
#include <QTextStream>
#include <QUdpSocket>
#include "localserver.h"



localserver::localserver(QObject *parent):QTcpServer(parent){

   socket = new QUdpSocket();

    /*RASPBERRY BACKUP*/
   //host = "192.168.178.27";
  // port = 7654;


   host = "172.31.12.84";
   port = 7654;
   dataBuffer_.resize(64);


}



void localserver:: sendInformation(char data){
    if(dataBuffer_.size() == 64)
          dataBuffer_.clear();
    else
          dataBuffer_.append(data);


    Data.append(data);
    socket->writeDatagram(Data, host, port);
    Data.clear();
};



bool localserver::isFull(){
    return (dataBuffer_.size() == 64);
}


void localserver:: go_forward(char forw){
    Data.append(forw);
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
     socket->writeDatagram(Data, host , port );
     Data.clear();
}
void localserver::automatic_driving(char choice){
    Data.append(choice);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}

void localserver::go_backward(char back){
    Data.append(back);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}
void localserver::manual_mode(char choice){
    Data.append(choice);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}

void localserver::direction_pad(char direction){
    Data.append(direction);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}
void localserver::go_certain(char direction){
    Data.append(direction);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}


void localserver::stream_camera(char camera){
    Data.append(camera);
    socket->writeDatagram(Data,host, port);
    Data.clear();
}

void localserver::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    char buf[] ={"FORWARD"};
    socket->write(buf);

}



char localserver::get_center(){
    char buf;
    socket->readDatagram(&buf, port);
    return buf;


}




void localserver::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}
