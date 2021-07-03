#include "mainscene.h"
#include "ui_mainscene.h"
#include "QPainter"
#include "QPushButton"
#include <QTimer>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    setFixedSize(320,588);
    setWindowIcon(QIcon("C:/Users/86182/Desktop/1.jpg"));
    setWindowTitle("乐趣弹球");
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //新游戏按钮
    QPushButton * btn = new QPushButton("新游戏",this);
    btn->resize(200,50);
    btn->move(60,300);

    //实例化选择关卡场景
    chooseScene=new ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        chooseScene->hide();
        this->show(); //重新显示主场景
    });


    connect(btn,&QPushButton::clicked,[=](){
        //进入到选择关卡场景
        QTimer::singleShot(300,this,[=](){
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });

    });

    //继续游戏按钮
    QPushButton * btn1 = new QPushButton("继续游戏",this);
    btn1->resize(200,50);
    btn1->move(60,380);

    //规则介绍按钮
    QPushButton * btn2 = new QPushButton("规则介绍",this);
    btn2->resize(200,50);
    btn2->move(60,460);
}

//背景图片、标题图片
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("C:/Users/86182/Desktop/2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load("C:/Users/86182/Desktop/3.jpg");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(15,80,pix);
}
MainScene::~MainScene()
{
    delete ui;
}

