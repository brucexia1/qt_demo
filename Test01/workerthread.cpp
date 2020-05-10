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
    MyImage img;

    setPriority(QThread::TimeCriticalPriority);

    while(1)
    {
        loop++;
        if(isStop) {
            qDebug() << tr("stop ThreadId() ") << QThread::currentThreadId();
            qDebug() << tr("loop %u ") << loop;
            return;
        }

        //qDebug() << tr("send img %p ") << &img;
        emit sendMsg(img);
        //sleep(1);
    }
    //this->exec();
}
