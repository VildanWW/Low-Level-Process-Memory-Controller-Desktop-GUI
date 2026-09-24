#include "pch.h"
#include "EventBus.h"

EventToken EventBus::SubscribeMove(MoveCallback callback) {
    moveList[nextToken] = callback;
    return nextToken++;
}

void EventBus::UnsubscribeMove(EventToken token) {
    moveList.erase(token);
}

EventToken EventBus::SubscribeScreen(ScreenCallback callback) {
    screenList[nextToken] = callback;
    return nextToken++;
}

void EventBus::UnsubscribeScreen(EventToken token) {
    screenList.erase(token);
}