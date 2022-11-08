#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mLayout = new QVBoxLayout;
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);

    ui->scrollArea->setLayout(mLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCamStart_clicked()
{
    mCamera->start();
}

void MainWindow::on_btnCamStop_clicked()
{
    mCamera->stop();
}
