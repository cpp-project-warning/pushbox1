#include "Mainwindow.h"

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

    round = 1;
    step = 0;
    setWindowTitle(title);
    setFixedSize(560, 720);

    roundLabel = new QLabel(this);
    stepLabel = new QLabel(this);
    roundLabel->setGeometry(0, 580, 100, 50);
    stepLabel->setGeometry(150, 580, 100, 50);
    roundLabel->setText(QString("第" + QString::number(round) + "关"));
    stepLabel->setText(QString("移动次数：" + step));

    nextBtn = new QPushButton(QString("下一关"), this);
    restartBtn = new QPushButton(QString("重新开始"), this);
    preBtn = new QPushButton(QString("上一关"), this);
    nextBtn->setGeometry(0, 650, 100, 50);
    restartBtn->setGeometry(150, 650, 100, 50);
    preBtn->setGeometry(300, 650, 100, 50);
    connect(nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));
    connect(restartBtn, SIGNAL(clicked()), this, SLOT(onRestartBtnClicked()));
    connect(preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));

    show();
}

void MainWindow::draw() {
    roundLabel->setText(QString("第" + QString::number(round) + "关"));
    stepLabel->setText(QString("移动次数：" + QString::number(step)));
    update();
}

direction MainWindow::getMovedir() {
    direction d = move;
    move = Nomove;
    return d;
}
int MainWindow::getRoundchange() {
    int t = roundchange;
    roundchange = 2;
    return t;
}

void MainWindow::setviewMap(int ** map) {
    viewMap = map;
}

void MainWindow::setRound(std::shared_ptr<int> round) {
    this->round = *round;
}
void MainWindow::setStep(std::shared_ptr<int> step) {
    this->step = *step;
}

void MainWindow::setIfsuccess(std::shared_ptr<bool> dosuccess) {
    if (*dosuccess) {

    }
}

void MainWindow::setDirection(std::shared_ptr<direction> d) {
    if (*d == Up)
        playerPixmap = upPixmap;
    else if (*d == Down)
        playerPixmap = downPixmap;
    else if (*d == Left)
        playerPixmap = leftPixmap;
    else if (*d == Right)
        playerPixmap = rightPixmap;
    else
        playerPixmap = downPixmap;
}

MainWindow::~MainWindow() {
    delete preBtn;
    delete restartBtn;
    delete nextBtn;
    delete roundLabel;
    delete stepLabel;
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    //painter.drawRect(QRect(0, 0, 560, 560));
    for (int i = 0; i < MAXN; i++) {
        for(int j=0; j<MAXN; j++) {
            painter.drawPixmap(i * 35, j * 35, 35, 35, blockPixmap);
            if (viewMap[i][j] == 2) {  
                painter.drawPixmap(i * 35+2, j * 35+3, 30, 30, aimPixmap);
            }
		}
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (viewMap[i][j] == 1) {  
                painter.drawPixmap(i * 35, j * 35 - 11, 35, 46, wallPixmap);
            }
            else if(viewMap[i][j] == 3) {  
				painter.drawPixmap(i * 35, j * 35 - 10, 35, 55, boxPixmap);
			}
			else if (viewMap[i][j] == 4) {  
				painter.drawPixmap(i * 35 - 7, j * 35 -27, 50, 62, playerPixmap);
			}
        }
    }
}



void MainWindow::keyPressEvent(QKeyEvent* e) {
    switch (e->key()) 
    {
    case Qt::Key_W:
        move = Up;
        break;
    case Qt::Key_A:
        move = Left;
        break;
    case Qt::Key_S:
        move = Down;
        break;
    case Qt::Key_D:
        move = Right;
        break;
    case Qt::Key_Up:
        move = Up;
        break;
    case Qt::Key_Left:
        move = Left;
        break;
    case Qt::Key_Down:
        move = Down;
        break;
    case Qt::Key_Right:
        move = Right;
        break;
    default:
        break;
    }
}

void MainWindow::onNextBtnClicked(){
    roundchange = 1;
}

void MainWindow::onRestartBtnClicked() {
    roundchange = 0;
}


void MainWindow::onPreBtnClicked() {
    roundchange = -1;
}


