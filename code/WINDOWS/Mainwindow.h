#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../COMMON/COMMON.h"
#include "../COMMON/etlbase.h"
#include "sinks/MainWindowCommandSink.h"
#include "sinks/MainWindowPropertySink.h"

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

    void set_MoveCommand(const std::shared_ptr<ICommandBase>& cmd) noexcept;
    void set_SkipCommand(const std::shared_ptr<ICommandBase>& cmd) noexcept;
    std::shared_ptr<IPropertyNotification> get_PropertySink() noexcept;
    std::shared_ptr<ICommandNotification> get_CommandSink() noexcept;

    void set_ViewMap(int map[MAXN][MAXN]);
    void set_Level(std::shared_ptr<int> round);
    void set_Step(std::shared_ptr<int> step);
    void set_Orientation(std::shared_ptr<direction> d);

    void popsuccess();

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
    int viewMap[MAXN][MAXN];

    std::shared_ptr<ICommandBase>m_cmdMove;
    std::shared_ptr<ICommandBase>m_cmdSkip;
    std::shared_ptr<MainWindowPropertySink> m_spPropertySink;
    std::shared_ptr<MainWindowCommandSink>  m_spCommandSink;

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
