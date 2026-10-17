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

void PipeManager::DisconnectFromDll() {
    if (hPipe != INVALID_HANDLE_VALUE) {
        CloseHandle(hPipe);
        hPipe = INVALID_HANDLE_VALUE;
        qDebug() << "Disconnected from DLL pipe.";
    }
}

void PipeManager::SendCommand(int functionId, int state) {
    if (!ConnectToDll()) {
        qDebug() << "Failed to send command: No connection to DLL";
        return;
    }

    unsigned char buffer[2]; // Two elements
    buffer[0] = static_cast<unsigned char>(functionId);
    buffer[1] = static_cast<unsigned char>(state);

    DWORD bytesWritten = 0;

    bool success = WriteFile(
        hPipe,
        buffer,
        sizeof(buffer),
        &bytesWritten,
        NULL
    );

    if (!success || bytesWritten!=2) {
        qDebug() << "WriteFile failed! Error:"<<GetLastError();
    }
    else {
        qDebug() << "Successfully sent to DLL -> Function ID:"<<functionId<<"State"<<state;
    }
    DisconnectFromDll();
}

PipeManager::~PipeManager() {
    DisconnectFromDll();
}

