#include "Mainwindow.h"
extern int roundNum;
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , blockPixmap("D:\\pushbox\\code\\img\\block.png")
    , boxPixmap("D:\\pushbox\\code\\img\\box.png")
    , wallPixmap("D:\\pushbox\\code\\img\\wall.png")
    , aimPixmap("D:\\pushbox\\code\\img\\ball.png")
    , upPixmap("D:\\pushbox\\code\\img\\up.png")
    , downPixmap("D:\\pushbox\\code\\img\\down.png")
    , rightPixmap("D:\\pushbox\\code\\img\\right.png")
    , leftPixmap("D:\\pushbox\\code\\img\\left.png")
{

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, 700, 700);
    view->setFixedSize(700, 700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFrameStyle(0);
    view->setSceneRect(0, 0, 700, 700);
    setFixedSize(750, 800);

    round = 1;
    step = 0;
    roundLabel = new QLabel(this);
    //roundLabel->setAlignment(Qt::AlignCenter);
    stepLabel = new QLabel(this);
    
    this->setWindowTitle(title);
    setDirection(Down);
    LoadGame();

    nextBtn = new QPushButton(QString("下一关"), this);
    restartBtn = new QPushButton(QString("重新开始"), this);
    preBtn = new QPushButton(QString("上一关"), this);

    connect(nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));
    connect(restartBtn, SIGNAL(clicked()), this, SLOT(onRestartBtnClicked()));
    connect(preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(preBtn);
    buttonLayout->addWidget(restartBtn);
    buttonLayout->addWidget(nextBtn);

    QHBoxLayout* textLayout = new QHBoxLayout;
    textLayout->addWidget(roundLabel);
    textLayout->addWidget(stepLabel);

    // 创建垂直布局，将游戏界面和按钮放置在其中
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addLayout(textLayout);
    mainLayout->addLayout(buttonLayout);

    // 设置布局为MainWindow的中心部件
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    show();



}


void MainWindow::LoadGame() {
    int aimiter = 0; 
    int boxiter = 0;
    scene->clear();
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            mapItem[i][j] = new QGraphicsPixmapItem(blockPixmap);
            mapItem[i][j]->setZValue(0);
            mapItem[i][j]->setPos(i * 35, j * 35);
            scene->addItem(mapItem[i][j]);
            if (viewMap[i][j] == 1)  // 该位置有墙
            {
                wallItem[i][j] = new QGraphicsPixmapItem(wallPixmap);
                wallItem[i][j]->setZValue(1);
                wallItem[i][j]->setPos(i * 35, j * 35-11);
                scene->addItem(wallItem[i][j]);
            }
            if (viewMap[i][j] == 2) {  // 该位置有目标
                aimItem[aimiter] = new QGraphicsPixmapItem(aimPixmap);
                aimItem[aimiter]->setZValue(1);
				aimItem[aimiter]->setPos(i * 35+2, j * 35+3);
				scene->addItem(aimItem[aimiter]);
				aimiter++;
            }
            if (viewMap[i][j] == 3) {  // 该位置有box
                boxItem[boxiter] = new QGraphicsPixmapItem(boxPixmap);
                boxItem[boxiter]->setZValue(1);
                boxItem[boxiter]->setPos(i * 35, j * 35-10);
                scene->addItem(boxItem[boxiter]);
                aimiter++;
            }
            if(viewMap[i][j] == 4) {  // 该位置有人
				playerItem = new QGraphicsPixmapItem(playerPixmap);
				playerItem->setZValue(1);
				playerItem->setPos(i * 35-7, j * 35-30);
				scene->addItem(playerItem);
			}
        }
    }
    roundLabel->setText(QString("第" + QString::number(round) + "关"));
    stepLabel->setText(QString("移动次数："+step));
    repaint();
}

bool MainWindow::isSuccessful() {
    if (1) {
        return true;
    }
	else {
		return false;
	}
}

void MainWindow::checkGame() {
    if (isSuccessful()) {
        QMessageBox::information(this, tr("Congratulations"), tr("You have completed this level!"));
        if(round<roundNum)
            round++;
        else
            round = 1;
    }
    LoadGame();
}
/*
void MainWindow::setviewMap() {
    int**wall = vm->get_wall();
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            ((int *)viewMap)[i*MAXN+j] = wall[i][j];
        }
    }
    std::set<Box> box = vm->get_all_box();
    //box_num = box.size();
    for (auto it = box.begin(); it != box.end(); it++) {
		viewMap[it->get_position().x][it->get_position().y] += 4;
	}
	std::set<position> aim = vm->get_destination();
    for (auto it = aim.begin(); it != aim.end(); it++) {
		viewMap[it->x][it->y] += 2;
	}
    Player player = vm->get_player();
	viewMap[player.get_position().x][player.get_position().y] += 8;
}
*/

void MainWindow::setviewMap(int  map[MAXN][MAXN]) {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            viewMap[i][j] = map[i][j];
        }
    }
}
void MainWindow::resetMove() {
	move = Nomove;
    step++;
    LoadGame();
}
void MainWindow::setRound(std::shared_ptr<int> round) {
    this->round = *round;
}
direction MainWindow::getMovedir() {
    return move;
}
int MainWindow::getRoundchange() {
    return roundchange;
}
void MainWindow::resetRoundchange() {
	roundchange = 2;
    step = 0;
    LoadGame();
}

MainWindow::~MainWindow() {
    delete preBtn;
    delete restartBtn;
    delete nextBtn;
    delete roundLabel;
    delete stepLabel;
}


void MainWindow::keyPressEvent(QKeyEvent* e) {
    switch (e->key()) 
    {
    case Qt::Key_W:
        move = Up;
        setDirection(Up);
        break;
    case Qt::Key_A:
        move = Left;
        setDirection(Left);
        break;
    case Qt::Key_S:
        move = Down;
        setDirection(Down);
        break;
    case Qt::Key_D:
        move = Right;
        setDirection(Right);
        break;
    case Qt::Key_Up:
        move = Up;
        setDirection(Up);
        break;
    case Qt::Key_Left:
        move = Left;
        setDirection(Left);
        break;
    case Qt::Key_Down:
        move = Down;
        setDirection(Down);
        break;
    case Qt::Key_Right:
        move = Right;
        setDirection(Right);
        break;
    default:
        break;
    }
}

void MainWindow::onNextBtnClicked(){
    setDirection();
    roundchange = 1;
}

void MainWindow::onRestartBtnClicked() {
    setDirection();
    roundchange = 0;
}


void MainWindow::onPreBtnClicked() {
    setDirection();
    roundchange = -1;
}

void MainWindow::setDirection(direction d ) {
    if(d == Up)
		playerPixmap = upPixmap;
	else if(d == Down)
		playerPixmap = downPixmap;
	else if(d == Left)
		playerPixmap = leftPixmap;
	else if(d == Right)
		playerPixmap = rightPixmap;
	else
		playerPixmap = downPixmap;
}
