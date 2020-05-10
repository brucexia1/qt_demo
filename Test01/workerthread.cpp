#include <QDebug>

#include "workerthread.h"

WorkerThread::WorkerThread()
{
    isStop = false;
}

void WorkerThread::closeThread()
{
    isStop = true;
}

void WorkerThread::run()
{
    uint64_t loop = 0;
    MyImage *img = new MyImage;
    img->setSthrNo((uint8_t)this->property("SThrNo").toUInt());

    setPriority(QThread::TimeCriticalPriority);

    while(1)
    {
        loop++;
        if(isStop) {
            qDebug() << tr("stop ThreadId() ") << QThread::currentThreadId();
            qDebug() << tr("loop ") << loop;
            return;
        }
        if(loop %10000 == 0 ) sleep(1);
        //sleep(1);

        //qDebug() << tr("send img ") << &img;
        emit sendMsg(*img);
    }

    delete img;
    //this->exec();
}
