#pragma once

#include"cocos2d.h"
#include"Tower.h"
#include"EnemySoldier.h"

USING_NS_CC;

class Money
{
public:
	//ÉèÖÃ½ðÇ®Êý
	void setMoney(int MoneyNow) { _money = MoneyNow; }
	int getMoney() { return _money; }

	void schedule(SEL_SCHEDULE selector, float interval);

	void moneyPlus(int warReward);
private:
	int _money;

	int timeNum;

	int timeRewardMoney;

	void DeathReward(int deathRewardMoney);
	void TimeReward(float dt);
	void KillHeroReward(int killRewardMoney);
	
	virtual bool init();
};

