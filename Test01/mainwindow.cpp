#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    thrPro1 = new WorkerThread();
    thrPro2 = new WorkerThread();
    m_thr1Msg = 0;
    m_thr2Msg = 0;

    connect(ui->createThreadBtn, SIGNAL(clicked(bool)),this,SLOT(createThreadBtnSlot()));
    connect(ui->closeThreadBtn, SIGNAL(clicked(bool)),this,SLOT(closeThreadBtnSlot()));
    connect(ui->actionStat, SIGNAL(triggered(bool)), this, SLOT(showStatSlot()));

    if(thrPro1 != nullptr && thrPro2 != nullptr)
    {
        qRegisterMetaType<MyImage>("MyImage");
        qRegisterMetaType<MyImage>("MyImage&");
        connect(thrPro1, SIGNAL(sendMsg(MyImage)), this, SLOT(recevieMsg(MyImage)));
        connect(thrPro2, SIGNAL(sendMsg(MyImage)), this, SLOT(recevieMsg(MyImage)));
        connect(thrPro1, &WorkerThread::finished, thrPro1, &QObject::deleteLater);
        connect(thrPro2, &WorkerThread::finished, thrPro2, &QObject::deleteLater);
    }
}

void MainWindow::createThreadBtnSlot()
{
    if(thrPro1 != nullptr && thrPro2 != nullptr)
    {
        thrPro1->setProperty("SThrNo", QVariant(WORK_STHR1));
        thrPro2->setProperty("SThrNo", QVariant(WORK_STHR2));
        thrPro1->start();
        thrPro2->start();
    }
}

void MainWindow::closeThreadBtnSlot()
{
    if(thrPro1 != nullptr && thrPro2 != nullptr)
    {
        thrPro1->closeThread();
        thrPro2->closeThread();
        thrPro1->wait();
        thrPro2->wait();
    }
}

void MainWindow::showStatSlot()
{
    qDebug() << tr("thr      1       2 ");
    qDebug() << tr("thr    ") << m_thr1Msg << "    " << m_thr2Msg;
}

void MainWindow::recevieMsg(MyImage img)
{
    switch(img.getSthrNo())
    {
        case WORK_STHR1: {
            m_thr1Msg++;
        }
        break;
        case WORK_STHR2: {
            m_thr2Msg++;
        }
        break;
        default: {
            qDebug() << tr("receive img ") << &img << "Sthr" << img.getSthrNo();
        }
        break;
    }
}
