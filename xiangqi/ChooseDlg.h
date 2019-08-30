#pragma execution_character_set("utf-8") //解决中文乱码问题
#ifndef ChooseDlg_H
#define ChooseDlg_H

#include <QDialog>
#include <QPushButton>

class ChooseDlg : public QDialog
{
    Q_OBJECT
public:
    explicit ChooseDlg(QWidget *parent = 0);

    QPushButton* _buttons[4];
    int _selected;
signals:

public slots:
    void slotClicked();
};

#endif // ChooseDlg_H
