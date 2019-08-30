#ifndef NETGAME_H
#define NETGAME_H

#include"Board.h"
#include<QTcpServer>
#include<QTcpSocket>

/*无服务器 每个程序都可以作为服务器*/
class NetGame:public Board
{
    Q_OBJECT
public:
    explicit NetGame(bool server, QWidget *parent = 0);

    bool _bServer;
    QTcpServer* _server;
    QTcpSocket* _socket;

    void click(int id,int row,int col);
signals:

public slots:
    void slotNewConnection();
    void slotDataArrive();
};

#endif // NETGAME_H
