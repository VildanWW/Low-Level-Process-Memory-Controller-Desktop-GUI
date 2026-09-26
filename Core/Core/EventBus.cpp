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


EventToken EventBus::SubscribeGlBegin(GlBeginCallback callback) {
    glBeginList[nextToken] = callback;
    return nextToken++;
}

void EventBus::UnsubscribeGlBegin(EventToken token) {
    glBeginList.erase(token);
}

EventToken EventBus::SubscribeGlVertex3F(GlVertex3F callback) {
    glVertex3FList[nextToken] = callback;
    return nextToken++;
}

void EventBus::UnsubscribeGlVertex3F(EventToken token) {
    glVertex3FList.erase(token);
}
