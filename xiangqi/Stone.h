#pragma execution_character_set("utf-8") //解决中文乱码问题
#ifndef STONE_H
#define STONE_H
#include<QString>

class Stone
{
public:

    enum TYPE{CHE, MA, PAO, BING, JIANG, SHI, XIANG};


    int _row; //行
    int _col; //列
    TYPE _type; //旗的种类
    int _id; //棋编号
    int _dead; //是否死亡
    int _red;  //棋的颜色 红还是黑

    //初始化棋子
    void init(int id)
    {
        struct{
            int row,col;
            Stone::TYPE type;
        }pos[16]={
        {0,0,Stone::CHE},
        {0,1,Stone::MA},
        {0,2,Stone::XIANG},
        {0,3,Stone::SHI},
        {0,4,Stone::JIANG},
        {0,5,Stone::SHI},
        {0,6,Stone::XIANG},
        {0,7,Stone::MA},
        {0,8,Stone::CHE},

        {2,1,Stone::PAO},
        {2,7,Stone::PAO},
        {3,0,Stone::BING},
        {3,2,Stone::BING},
        {3,4,Stone::BING},
        {3,6,Stone::BING},
        {3,8,Stone::BING}
        };

        _id=id;
        _dead=false;
        _red=id<16;//1是红 0是黑

        if(id<16)
        {
            _row=pos[id].row;
            _col=pos[id].col;
            _type=pos[id].type;
        }
        else
        {
            _row=9-pos[id-16].row;
            _col=8-pos[id-16].col;
            _type=pos[id-16].type;
        }
    }

    //根据象棋的类型返回名字
    QString getText()
    {
        switch(this->_type)
        {
        case CHE:
            return "车";
        case MA:
            return "马";
        case BING:
            return "兵";
        case JIANG:
            return "将";
        case PAO:
            return "炮";
        case SHI:
            return "士";
        case XIANG:
            return "相";
        }
       return "错误";
    }

    void rotate();
};

#endif // STONE_H
