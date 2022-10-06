#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <guithread.h>

enum class progressBarState{incremental=0,decremental=1};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setTextValue();
    void test();
private slots:

private:
    Ui::MainWindow *ui;
    progressBarState state;

    GuiThread *t1 = new GuiThread;
    GuiThread *t2 = new GuiThread;
    GuiThread *t3 = new GuiThread;
};
#endif // MAINWINDOW_H
