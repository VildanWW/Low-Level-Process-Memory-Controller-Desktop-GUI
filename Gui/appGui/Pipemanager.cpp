#include "Pipemanager.h"
#include <QDebug>

PipeManager::PipeManager(QObject *parent) : QObject{parent} {}

bool PipeManager::ConnectToDll() {
    if (hPipe != INVALID_HANDLE_VALUE) {
        CloseHandle(hPipe);
        hPipe = INVALID_HANDLE_VALUE;
    }

    hPipe = CreateFileA(
        "\\\\.\\pipe\\CS16CheatPipe",
        GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        qDebug() << "Don't to connect Pipe DLL! Code error:" << GetLastError();
        return false;
    }

    qDebug() << "Successfully connecting for Dll";
    return true;
}

void PipeManager::DisconnectFromDll() {}

void PipeManager::SendCommand(int functionId, int state) {}

