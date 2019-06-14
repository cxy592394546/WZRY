#include "EnemySoldier.h"

bool EnemySoldier::init() {
	if (SoldierType == 0) {
		//³õÊ¼ÑªÁ¿
		SoldierBlood = HP_0;
		//ËÀÍö½±Àø
		deathRewardMoney = 30;
		deathRewardExp = 20;
		//ÉËº¦
		damage = DAMAGE_0;
	}
	else if (SoldierType == 1)
	{
		//³õÊ¼ÑªÁ¿
		SoldierBlood = HP_1;
		//ËÀÍö½±Àø
		deathRewardMoney = 45;
		deathRewardExp = 30;
		//ÉËº¦
		damage = DAMAGE_1;
	}
	else if (SoldierType == 2)
	{
		//³õÊ¼ÑªÁ¿
		SoldierBlood = HP_2;
		//ËÀÍö½±Àø
		deathRewardMoney = 75;
		deathRewardExp = 50;
		//ÉËº¦
		damage = DAMAGE_2;
	}
	else
		return false;

	//¹¥»÷·¶Î§
	attackRadius = ATTACK_RADIUS;
	//¹¥ËÙ
	attackSpeed = ATTACK_SPEED;

	return true;
}

bool EnemySoldier::checkInTower() {
	Vec2 pos1 = this->enemyTower->getPosition();
	if (attackRect->containsPoint(pos1)) {	
		return true;
	}

	return false;
}

void EnemySoldier::attackTower() {
	if (checkInTower) {
		Animation* animation = Animation::create();
		__String* frameName;
		switch (SoldierType) {
		case 1:
			Tower::minusBlood(DAMAGE_0);
			break;
		case 2:
			Tower::minusBlood(DAMAGE_1);
			break;
		case 3:
			Tower::minusBlood(DAMAGE_2);
			break;
		}
		animation->setDelayPerUnit(0.2f);
		animation->setRestoreOriginalFrame(true);
	}
}

void EnemySoldier::minusBlood(int damageNum) {
	if (SoldierBlood - damageNum >= 0) {//ÊÜµ½¹¥»÷
		SoldierBlood -= damageNum;
	}
	else {//ÑªÁ¿Îª0
		SoldierBlood = 0;
		Moving = false;
		Attacking = false;
		Money::moneyPlus(deathRewardMoney);
	}
}