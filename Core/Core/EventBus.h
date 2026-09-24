#pragma once
#include <functional>
#include <unordered_map>

typedef size_t EventToken;

class EventBus {
private:
	inline static EventToken nextToken = 0;
public:
	typedef std::function<unsigned int(char, unsigned int)> MoveCallback;
	inline static std::unordered_map<EventToken, MoveCallback> moveList;

	static EventToken SubscribeMove(MoveCallback callback);

	static void UnsubscribeMove(EventToken token);

	typedef std::function<bool(const char*, int, const unsigned char*)> ScreenCallback;
	inline static std::unordered_map<EventToken, ScreenCallback> screenList;

	static EventToken SubscribeScreen(ScreenCallback callback);

	static void UnsubscribeScreen(EventToken token);
};

