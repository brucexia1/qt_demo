#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdint.h>
#include <QMainWindow>

#include "workerthread.h"
#include "myimage.h"

#define WORK_STHR1    (1)
#define WORK_STHR2    (2)


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
    void showStatSlot();

    void recevieMsg(MyImage img);

private:
    Ui::MainWindow *ui;

    WorkerThread *thrPro1;
    WorkerThread *thrPro2;
    uint64_t m_thr1Msg;
    uint64_t m_thr2Msg;

};
#endif // MAINWINDOW_H
