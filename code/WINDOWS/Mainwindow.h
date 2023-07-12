#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../COMMON/COMMON.h"

#include <QtWidgets/QMainWindow>   // 主窗口类
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>  // 场景类
#include <QtWidgets/QGraphicsView>  // 视图类
#include <QtGUI/QPixmap>  // 图片类
#include <QtWidgets/QGraphicsPixmapItem>  // 图片项类
#include <QtGUI/QKeyEvent>  // 键盘事件类
#include <QtWidgets/QPushButton>  // 按钮类
#include <QtWidgets/QLabel>  // 标签类
#include <QtWidgets/QMessageBox>  // 消息框类
#include <QtGUI/QPainter>
#include <QtCore/QString>
#include <QtCore/QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
    void draw();
    

    direction getMovedir();
    int getRoundchange();
    void setviewMap(int **map);
    void setRound(std::shared_ptr<int> round);
    void setStep(std::shared_ptr<int> step);
    void setIfsuccess(std::shared_ptr<bool> dosuccess);
    void setDirection(std::shared_ptr<direction> d);

private slots:
    void onNextBtnClicked();
    void onRestartBtnClicked();
    void onPreBtnClicked();

private:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent* e);
    
    int round;
    int step;
    const QString title = "推箱子游戏";
    direction move = Nomove;
    int roundchange = 2;
    int** viewMap;

    QPixmap wallPixmap;
    QPixmap aimPixmap;
    QPixmap blockPixmap;
    QPixmap boxPixmap;
    QPixmap upPixmap;
    QPixmap downPixmap;
    QPixmap rightPixmap;
    QPixmap leftPixmap;
    QPixmap playerPixmap;

    QLabel* roundLabel;
    QLabel* stepLabel;

    QPushButton* nextBtn;
    QPushButton* restartBtn;
    QPushButton* preBtn;
};


#endif
