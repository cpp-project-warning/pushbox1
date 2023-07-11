
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../VIEWMODEL/ViewModel.h"
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGUI/QPainter>
#include <QtCore/QString>

#include <string>
#include <map>
#include <set>
#include <vector>

//extern const int mapSize = 20;  // 地图大小


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
    void LoadGame();

    direction getMovedir();
    int getRoundchange();
    void setviewMap(int map[MAXN][MAXN]);
    void resetMove();
    void resetRoundchange();
    void setRound(std::shared_ptr<int> round);

private slots:
    void onNextBtnClicked();
    void onRestartBtnClicked();
    void onPreBtnClicked();

private:

    void keyPressEvent(QKeyEvent* e);

    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsView* view = new QGraphicsView(scene, this);


    void setDirection(direction d = Down);

    bool isSuccessful();
    void checkGame();
    

    int round;
    int step;
    const QString title = "推箱子游戏";
    direction move = Nomove;
    int roundchange = 2;
    int viewMap[MAXN][MAXN];
    int box_num;


    QGraphicsPixmapItem* mapItem[20][20];
    QGraphicsPixmapItem* wallItem[20][20];
    QGraphicsPixmapItem* playerItem;
    QGraphicsPixmapItem* boxItem[10];
    QGraphicsPixmapItem* aimItem[10];

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
