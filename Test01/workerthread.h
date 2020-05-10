#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>

#include "myimage.h"

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread();
    void closeThread();

protected:
    virtual void run();

signals:
    void sendMsg(MyImage &s);

private:
    volatile bool isStop;
};

#endif // WORKERTHREAD_H
