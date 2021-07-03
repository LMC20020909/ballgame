#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("选择关卡");
    setFixedSize(320,588);
    setWindowIcon(QIcon("C:/Users/86182/Desktop/1.jpg"));

    //创建菜单栏
    QMenuBar * bar =menuBar();
    setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("设置");

    QAction * quitAction = startMenu->addAction("退出");
    QAction * volumeAction = startMenu->addAction("音量");
    connect(quitAction,&QAction::triggered,[=](){
            this->close();
    });

    //返回按钮
    QPushButton * btn = new QPushButton("Back",this);
    btn->resize(100,25);
    btn->move(this->width()-btn->width(),this->height()-btn->height());
    connect(btn,&QPushButton::clicked,[=](){
        //延时返回
        QTimer::singleShot(300,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    for(int i=0;i<12;i++)
    {
        QPushButton * menuBtn = new QPushButton;
        menuBtn->resize(50,50);
        menuBtn->setParent(this);
        menuBtn->move(60 + i%3 * 80 , 180 + i/3 * 80);
        menuBtn->setText(QString::number(i+1));
    }
}

//背景图片、标题图片
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/Users/86182/Desktop/2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load("C:/Users/86182/Desktop/3.jpg");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap((this->width() - pix.width() )*0.5,30,pix.width(),pix.height(),pix);
}
