#pragma once

#include"cocos2d.h"
#include "Tower.h"

#define HP_0 800
#define HP_1 1500
#define HP_2 2500
#define DAMAGE_0 40
#define DAMAGE_1 80
#define DAMAGE_2 120
#define ATTACK_RADIUS 90

USING_NS_CC;

class EnemySoldier
{
public:
	//攻击范围
	int getAttackRadius() { return attackRadius; }
	void setAttackRadius(float radius) { attackRadius = radius; }
	//攻击速度
	int getAttackInterval() { return attackSpeed; }
	void setAttackInterval(int attackInterval) { attackSpeed = attackInterval; }

	//血量
	float SoldierBlood;

	bool death();

	void attackTarget();

private:
	enum SoldierType
	{
	Infantry = 0,Adviser,sower
	};

	int SoldierType;

	float damage;
	float attackRadius;
	int attackSpeed;

	int deathRewardMoney;	//打死奖励金币数量
	int deathRewardExp;		//打死奖励经验的数量

	void minusBlood(int damageNum);

	bool init();

	Rect* attackRect;

	bool checkInTower();
	void attackTower();

	bool Moving;
	bool Attacking;

	Tower* enemyTower;
	Vec2 pos1;
};

