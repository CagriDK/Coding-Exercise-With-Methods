#pragma once

#include "guithread.h"
#include "QTimer"
#include <QTime>
#include <QCoreApplication>

GuiThread::GuiThread():mstop(false)
{
//    qDebug()<<currentThread();
//    qDebug()<<currentThreadId();
}

void GuiThread::stop()
{
    mstop=true;
}

void delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void GuiThread::run()
{
    qDebug()<<currentThread();
    qDebug()<<currentThreadId();
    while(1){
        delay(10);
        emit valueChanged();
    }

}


