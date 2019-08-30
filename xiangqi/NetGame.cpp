#include "NetGame.h"


/*
 * 1.执红方还是执黑方，这个信息由服务器发出，客户端接受
 * 第一个字节固定是1，第二个字节是1，或者0,1表示接收方走红棋，0表示走黑棋
 * 2.发送点击信息
 * 第一个字节固定位2，第二个字节是row，第三个字节是col，第四个点击的棋子id
*/
NetGame::NetGame(bool server, QWidget *parent) : Board(parent)
{
    _server = NULL;
    _socket = NULL;
    _bServer = server;

    if(_bServer)
    {
        _server = new QTcpServer(this);
        _server->listen(QHostAddress::Any, 9999);
        connect(_server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
    }
    else
    {
        _socket = new QTcpSocket(this);
        _socket->connectToHost(QHostAddress("127.0.0.1"), 9999);
        connect(_socket, SIGNAL(readyRead()), this, SLOT(slotDataArrive()));
    }
}

void NetGame::click(int id,int row,int col)
{
    if(_selectid==-1&&id!=-1)
    {
        if(_s[id]._red!=_bSide)
        {
            return;
        }
    }
    Board::click(id,row,col);
    /* 发送给对方 */
    char buf[4];
    buf[0]=2;
    buf[1]=9-row;
    buf[2]=8-col;
    buf[3]=id;
    _socket->write(buf,4);
}
void NetGame::slotNewConnection()
{
    if(_socket) return;

    //返回tcpsocket,这个socket就是要链接的socket
    _socket=_server->nextPendingConnection();
     connect(_socket, SIGNAL(readyRead()), this, SLOT(slotDataArrive()));
    /* 给对方发送数据 */
    char buf[2];
    buf[0]=1;
    buf[1]=0;
    _socket->write(buf,2);
    init(buf[1]==0);
}

void NetGame::slotDataArrive()
{
    QByteArray ba=_socket->readAll();
    char cmd=ba[0];
    if(cmd==1)
    {
        //初始化
        char data=ba[1];
        init(data==1);
    }
    else if(cmd==2)
    {
        int row=ba[1];
        int col=ba[2];
        int id=ba[3];
        Board::click(id,row,col);
    }
}

