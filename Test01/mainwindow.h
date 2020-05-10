#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "workerthread.h"
#include "myimage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void init();

private slots:
    void createThreadBtnSlot();
    void closeThreadBtnSlot();

    void recevieMsg(MyImage &s);

private:
    Ui::MainWindow *ui;

    WorkerThread *thrPro1;
    WorkerThread *thrPro2;
};
#endif // MAINWINDOW_H
