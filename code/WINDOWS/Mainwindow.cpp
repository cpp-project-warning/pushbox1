#include "Mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , blockPixmap("./img/block.png")
    , boxPixmap("./img/box.png")
    , wallPixmap("./img/wall.png")
    , aimPixmap("./img/ball.png")
    , upPixmap("./img/up.png")
    , downPixmap("./img/down.png")
    , rightPixmap("./img/right.png")
    , leftPixmap("./img/left.png")
    , m_spCommandSink(std::make_shared<MainWindowCommandSink>(this))
    , m_spPropertySink(std::make_shared<MainWindowPropertySink>(this))
{
    setWindowTitle(title);
    setFixedSize(560, 700);

    roundLabel.setParent(this);
    stepLabel.setParent(this);
    roundLabel.setGeometry(30, 570, 120, 50);
    stepLabel.setGeometry(220, 570, 120, 50);
    roundLabel.setAlignment(Qt::AlignCenter);
    stepLabel.setAlignment(Qt::AlignCenter);

    nextBtn.setParent(this);
    nextBtn.setText(QString("下一关"));
    restartBtn.setParent(this);
    restartBtn.setText(QString("重新开始"));
    preBtn.setParent(this);
    preBtn.setText(QString("上一关"));
    preBtn.setGeometry(30, 630, 120, 50);
    restartBtn.setGeometry(220, 630, 120, 50);
    nextBtn.setGeometry(410, 630, 120, 50);
    connect(&nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));
    connect(&restartBtn, SIGNAL(clicked()), this, SLOT(onRestartBtnClicked()));
    connect(&preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));
}

void MainWindow::draw() {
    roundLabel.setText(QString("第" + QString::number(level) + "关"));
    stepLabel.setText(QString("移动次数：" + QString::number(*step)));
    show();
    update();
}


void MainWindow::set_MoveCommand(const std::shared_ptr<ICommandBase>& cmd) noexcept {
    m_cmdMove = cmd;
}
void MainWindow::set_SkipCommand(const std::shared_ptr<ICommandBase>& cmd) noexcept {
    m_cmdSkip = cmd;
}

std::shared_ptr<IPropertyNotification> MainWindow::get_PropertySink() noexcept
{
    return std::static_pointer_cast<IPropertyNotification>(m_spPropertySink);
}
std::shared_ptr<ICommandNotification> MainWindow::get_CommandSink() noexcept
{
    return std::static_pointer_cast<ICommandNotification>(m_spCommandSink);
}



void MainWindow::set_ViewMap(std::shared_ptr<int[]> ViewMap) {

    this->viewMap = ViewMap;
}
/*
void MainWindow::set_Level(std::shared_ptr<int> round) {
    this->round = round;
}*/
void MainWindow::set_Step(std::shared_ptr<int> step) {
    this->step = step;
}

void MainWindow::popsuccess() {
    QMessageBox::information(this, "Congratulations!", "恭喜过关！");
    m_cmdSkip->SetParameter(1);
    m_cmdSkip->Exec();
    update();
}

void MainWindow::set_Orientation(std::shared_ptr<direction> d) {
    this->dir = d;
}

MainWindow::~MainWindow() {
}

void MainWindow::paintEvent(QPaintEvent*) {
    roundLabel.setText(QString("第" + QString::number(level) + "关"));
    stepLabel.setText(QString("移动次数：" + QString::number(*step)));
    if (*dir == Up)
        playerPixmap = upPixmap;
    else if (*dir == Down)
        playerPixmap = downPixmap;
    else if (*dir == Left)
        playerPixmap = leftPixmap;
    else if (*dir == Right)
        playerPixmap = rightPixmap;
    else
        playerPixmap = downPixmap;

    QPainter painter(this);
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            painter.drawPixmap(i * 35, j * 35, 35, 35, blockPixmap);
            if ((viewMap)[i * MAXN + j] == 2) {
                painter.drawPixmap(i * 35 + 2, j * 35 + 3, 30, 30, aimPixmap);
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (viewMap[i * MAXN + j] == 1) {
                painter.drawPixmap(i * 35, j * 35 - 11, 35, 46, wallPixmap);
            }
            else if (viewMap[i * MAXN + j] == 3) {
                painter.drawPixmap(i * 35, j * 35 - 10, 35, 45, boxPixmap);
            }
            else if (viewMap[i * MAXN + j] == 4) {
                painter.drawPixmap(i * 35 - 7, j * 35 - 27, 50, 62, playerPixmap);
            }
        }
    }
}



void MainWindow::keyPressEvent(QKeyEvent* e) {
    switch (e->key())
    {
    case Qt::Key_W:
        m_cmdMove->SetParameter(Up);
        m_cmdMove->Exec();
        break;
    case Qt::Key_A:
        m_cmdMove->SetParameter(Left);
        m_cmdMove->Exec();
        break;
    case Qt::Key_S:
        m_cmdMove->SetParameter(Down);
        m_cmdMove->Exec();
        break;
    case Qt::Key_D:
        m_cmdMove->SetParameter(Right);
        m_cmdMove->Exec();
        break;
    case Qt::Key_Up:
        m_cmdMove->SetParameter(Up);
        m_cmdMove->Exec();
        break;
    case Qt::Key_Left:
        m_cmdMove->SetParameter(Left);
        m_cmdMove->Exec();
        break;
    case Qt::Key_Down:
        m_cmdMove->SetParameter(Down);
        m_cmdMove->Exec();
        break;
    case Qt::Key_Right:
        m_cmdMove->SetParameter(Right);
        m_cmdMove->Exec();
        break;
    default:
        break;
    }

}

void MainWindow::onNextBtnClicked() {
    m_cmdSkip->SetParameter(1);
    m_cmdSkip->Exec();

}

void MainWindow::onRestartBtnClicked() {
    m_cmdSkip->SetParameter(0);
    m_cmdSkip->Exec();

}

void MainWindow::onPreBtnClicked() {
    m_cmdSkip->SetParameter(-1);
    m_cmdSkip->Exec();

}

