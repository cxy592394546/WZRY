#include "Tower.h"

void Tower::initTower(){
	//¹¥»÷·¶Î§
	attackRadius = ATTACK_RADIUS;
	//¹¥ËÙ
	attackSpeed = ATTACK_SPEED;
	//³õÊ¼ÑªÁ¿
	originBlood = HP;
	towerHP = originBlood;
	//ËÀÍö½±Àø
	deathRewardMoney = 120;
	deathRewardExp = 100;

}

void Tower::minusBlood(int damageNum){
	if (towerHP - damageNum >= 0) {//ÊÜµ½¹¥»÷
		towerHP -= damageNum;
	}
	else {//ÑªÁ¿Îª0
		towerHP = 0;
		Money::moneyPlus(deathRewardMoney);
	}
}

bool Tower::destoryed() {//±»´Ý»Ù
	if (towerHP == 0)
		damage = 0;
	return true;
}