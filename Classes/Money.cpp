#include "Money.h"
#include"Tower.h"
#include"EnemySoldier.h"

bool Money::init() {
	setMoney(0);
	struct timeval now;
	gettimeofday(&now, NULL);
	this->timeNum = 0;    //计时从0开始
	this->schedule(schedule_selector(Money::TimeReward),1.0f);
	return true;
}



void Money::TimeReward(float TimeRewardMoney) {
	timeRewardMoney = timeNum;
}

void Money::moneyPlus(int warReward) {
	_money += warReward;
}
