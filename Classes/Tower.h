#pragma once

#include<string>
#include"cocos2d.h"

USING_NS_CC;
using namespace std;

#define ATTACK_RADIUS 90
#define ATK_DAMAGE 250
#define HP 8000
#define ATTACK_SPEED 100

class Tower
{
public:
	//ÕóÓª
	void setColor(int color) { _color = color; }
	int getColor() { return _color; }
	//¹¥»÷·¶Î§
	void setAttackRadius(float radius) { attackRadius = radius; }
	int getAttackRadius() { return attackRadius; }
	//¹¥»÷ËÙ¶È
	void setAttackInterval(int attackInterval) { attackSpeed = attackInterval; }
	int getAttackInterval() { return attackSpeed; }
	float towerHP;

	void initTower();

	float be_attacked(float damage);
	bool destoryed();

private:
	int _color;
	float damage = ATK_DAMAGE;
	float attackRadius;

	float originBlood = HP;

	int deathRewardMoney;
	int deathRewardExp;
	int attackSpeed = ATTACK_SPEED;

	void minusBlood(int damageNum, Node* attacker);

	void initTower();
};

