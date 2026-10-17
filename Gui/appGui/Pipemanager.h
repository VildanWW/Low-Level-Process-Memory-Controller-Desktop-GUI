#ifndef PIPEMANAGER_H
#define PIPEMANAGER_H

#include <QObject>
#include <memory.h>
#include <Windows.h>

class PipeManager : public QObject {
    Q_OBJECT
public:
    explicit PipeManager(QObject *parent = nullptr);

    Q_INVOKABLE bool ConnectToDll();
    Q_INVOKABLE void DisconnectFromDll();
    Q_INVOKABLE void SendCommand(int functionId, int state);

    ~PipeManager();
private:
    HANDLE hPipe = INVALID_HANDLE_VALUE;
signals:
};

#endif // PIPEMANAGER_H
