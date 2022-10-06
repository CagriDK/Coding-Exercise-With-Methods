#ifndef GUITHREAD_H
#define GUITHREAD_H

#include<QDebug>
#include <QThread>
#include <QTimer>

class GuiThread : public QThread
{
    Q_OBJECT
public:
    GuiThread();

signals:
    void valueChanged();

public slots:
    void stop();
protected:
    QTimer timer;
    bool mstop;
    void run();
};


#endif // GUITHREAD_H
