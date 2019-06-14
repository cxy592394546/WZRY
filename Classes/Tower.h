#pragma once

#include"cocos2d.h"
#include"EnemySoldier.h"
#include"Money.h"

USING_NS_CC;

#define ATTACK_RADIUS 90
#define ATK_DAMAGE 250
#define HP 8000
#define ATTACK_SPEED 100

class Tower
{
public:
	//阵营
	void setColor(int color) { _color = color; }
	int getColor() { return _color; }
	//攻击范围
	void setAttackRadius(float radius) { attackRadius = radius; }
	int getAttackRadius() { return attackRadius; }
	//攻击速度
	void setAttackInterval(int attackInterval) { attackSpeed = attackInterval; }
	int getAttackInterval() { return attackSpeed; }
	//当前生命
	float& towerHP;
	static void minusBlood(int damageNum);

	//是否存在
	bool destoryed();
	

private:
	int _color;
	float damage = ATK_DAMAGE;
	float attackRadius;

	float originBlood = HP;

	int& deathRewardMoney;
	int deathRewardExp;
	int attackSpeed = ATTACK_SPEED;

	void initTower();
};

