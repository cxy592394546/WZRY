#ifndef HANDLEEVENT_H_
#define HANDLEEVENT_H_

#include<list>
#include"cocos2d.h"
#include"json/reader.h"
#include"json/value.h"
#include<iostream>
#include<functional>

#define SEL_EVENTFUNC(func) static_cast<SEL_EventFunc>(&func)
#define LL long long int

typedef void (cocos2d::CCObject::*SEL_EventFunc)(Json::Value&);
typedef struct _Event {
	cocos2d::CCObject* handler;
	SEL_EventFunc func;
}EventHandler;

EventHandler handler(cocos2d::CCObject* CCObject, SEL_EventFunc func);

class SlotListener
{
public:
	SlotListener() {}
	virtual ~SlotListener() {}
	virtual void removeSlot(const LL& slotId) = 0;
};

class Slot
{
public:
	Slot(SlotListener* listener, const EventHandler& evh, const bool& once = false);
	Slot(SlotListener* listener, const std::function<void(Json::Value&)>& func, const bool& once = false);
	virtual ~Slot() {}
	virtual void dispatch(Json::Value& message);
	bool operator==(const Slot& slot);
	LL getId() const;
	void remove();
private:
	LL id;
	bool flag = false;
	EventHandler evh;
	std::function<void(Json::Value&)> func;
	bool once;
	SlotListener* listener;
	static LL count;
};


class Signal :public SlotListener
{
public:
	Signal();
	virtual ~Signal();
	virtual void removeSlot(const LL& slotId);
	Slot* add(const EventHandler& handler);
	Slot* add(const std::function<void(Json::Value&)>&);
	Slot* addOnce(const EventHandler& handler);
	Slot* addOnce(const std::function<void(Json::Value&)>& func);
	void dispatch(Json::Value & message);
private:
	std::list<Slot*> m_slots;
};

#endif // !__SIGNAL_H__

