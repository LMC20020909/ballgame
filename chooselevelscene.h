#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
signals:
    //自定义信号，告诉主场景返回
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
