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

    connect(ui->createThreadBtn, SIGNAL(clicked(bool)),this,SLOT(createThreadBtnSlot()));
    connect(ui->closeThreadBtn, SIGNAL(clicked(bool)),this,SLOT(closeThreadBtnSlot()));

    if(thrPro1 != nullptr && thrPro2 != nullptr)
    {
        qRegisterMetaType<MyImage>("MyImage");
        qRegisterMetaType<MyImage>("MyImage&");
        connect(thrPro1, SIGNAL(sendMsg(MyImage&)), this, SLOT(recevieMsg(MyImage&)));
        connect(thrPro2, SIGNAL(sendMsg(MyImage&)), this, SLOT(recevieMsg(MyImage&)));
        connect(thrPro1, &WorkerThread::finished, thrPro1, &QObject::deleteLater);
        connect(thrPro2, &WorkerThread::finished, thrPro2, &QObject::deleteLater);
    }
}

void MainWindow::createThreadBtnSlot()
{
    if(thrPro1 != nullptr && thrPro2 != nullptr)
    {
        thrPro1->setProperty("SThrNo", QVariant(1));
        thrPro2->setProperty("SThrNo", QVariant(2));
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

void MainWindow::recevieMsg(MyImage &s)
{
    //qDebug() << tr("receive data %u ") << &s;
    //qDebug() << tr("receive img %p ") << &img;

}
