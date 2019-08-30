#include "CtrlPanel.h"
#include <QGridLayout>
#include <QVBoxLayout>
CtrlPanel::CtrlPanel(QWidget *parent) : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout(this);//布局管理器
    QVBoxLayout* vLay = new QVBoxLayout;
    grid->setColumnStretch(0, 1);////设置列比例系数
    grid->setColumnStretch(2, 1);
    grid->setRowStretch(0, 1);////设置行比例系数
    grid->setRowStretch(2, 1);
    grid->addLayout(vLay, 1, 1);

    vLay->addWidget(this->_back = new QPushButton("Back"));
    connect(this->_back, SIGNAL(clicked()), this, SIGNAL(sigBack()));
}


