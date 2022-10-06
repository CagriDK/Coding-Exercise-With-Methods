#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , state(progressBarState::incremental)
{
    //qDebug()<<"Ana izlek Id : "<<QThread::currentThreadId();

    t1->start();
    t2->start();
    t3->start();

    ui->setupUi(this);
    connect(t1,&GuiThread::valueChanged,this,&MainWindow::setTextValue);
}


MainWindow::~MainWindow()
{
    t1->terminate();
    delete t1;
    delete ui;
}

void MainWindow::setTextValue()
{
    if(ui->progressBar->value() == 100){
         state=progressBarState::decremental;
    }

    if(ui->progressBar->value() == 0){
        state=progressBarState::incremental;
    }

    if(state == progressBarState::incremental){
        ui->progressBar->setValue(ui->progressBar->value()+1);
    }

    else if(state == progressBarState::decremental){
        ui->progressBar->setValue(ui->progressBar->value()-1);
    }

    QString Value=QString::number(ui->progressBar->value());
    ui->lineEdit->setText(Value);
}

void MainWindow::test()
{

}
