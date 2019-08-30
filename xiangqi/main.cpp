#include "SingleGame.h"
#include <QApplication>
#include"NetGame.h"
#include<QMessageBox>

int main(int argc, char *argv[])
{
    //抽象了QT的应用程序
    QApplication app(argc, argv);
    QMessageBox::StandardButton ret;

    ret=QMessageBox::question(NULL,"Server or client","作为服务器启动");
    bool bServer=false;
    if(ret==QMessageBox::Yes)
    {
        bServer=true;
    }
    NetGame board(bServer);
    board.show();

    //进入消息循环
    return app.exec();
}
