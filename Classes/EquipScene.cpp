#include"EquipScene.h"
#include"GameScene.h"
USING_NS_CC;
#include<vector>
#include<utility>
std::vector<std::pair<int, int> > equipButtonPosition = { std::pair<int, int>(325,570),std::pair<int, int>(560,570),std::pair<int, int>(805,570),\
std::pair<int, int>(1060, 570), std::pair<int, int>(325, 425), std::pair<int, int>(570, 425), std::pair<int, int>(805, 425),\
std::pair<int, int>(1060, 425), std::pair<int, int>(325, 270), std::pair<int, int>(570, 270), std::pair<int, int>(810, 270),\
std::pair<int, int>(1060, 270), std::pair<int, int>(330, 120), std::pair<int, int>(575, 120), std::pair<int, int>(818, 120),\
std::pair<int, int>(1062, 120) };
enum EquipemntTag_c {
	weapon_1 = 0, weapon_2, weapon_3, weapon_4, armor_1, armor_2, armor_3, armor_4, accessory_1, accessory_2, accessory_3, \
	accessory_4, shoes_1, shoes_2, shoes_3, shoes_4
};
std::vector<int> equipmentTag_c = { weapon_1,weapon_2,weapon_3,weapon_4,armor_1,armor_2,armor_3,armor_4,accessory_1,accessory_2,accessory_3,\
accessory_4,shoes_1,shoes_2,shoes_3,shoes_4 }£»
std::vector<MenuItemToggle*> menuVector(16);
EquipScene* EquipScene::createScene()
{
	return EquipScene::create();
}
bool EquipScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite *equipbg = Sprite::create("equipground.png");
	equipbg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	addChild(equipbg);
	for (int i = 0; i < 16; ++i)
	{
		if (equipmentBoughtList[i] == 0)
		{
			auto state1 = MenuItemImage::create("storebutton/unbuy.png", "storebutton/unbuy.png");
			auto state2 = MenuItemImage::create("storebutton/unbuy.png", "storebutton/unbuy.png");
			menuVector[i] = MenuItemToggle::createWithCallback(CC_CALLBACK_1(EquipScene::equipCallback_s, this), state1, state2, NULL);
		}
		else
			if (equipmentBoughtList[i] == 1)
			{
				auto state1 = MenuItemImage::create("storebutton/equip.png", "storebutton/equip.png");
				auto state2 = MenuItemImage::create("storebutton/equipped.png", "storebutton/equipped.png");
				if (equipmentEquippedList[i] == 0)
				{
					menuVector[i] = MenuItemToggle::createWithCallback(CC_CALLBACK_1(EquipScene::equipCallback, this), state1, state2, NULL);
				}
				else
					if (equipmentEquippedList[i] == 1)
					{
						menuVector[i] = MenuItemToggle::createWithCallback(CC_CALLBACK_1(EquipScene::equipCallbackEquipped, this), state2, state1, NULL);
					}
			}
		menuVector[i]->setTag(equipmentTag_c[i]);
		menuVector[i]->setPosition(Vec2(equipButtonPosition[i].first, equipButtonPosition[i].second));
	}
	MenuItemImage *equipReturn = MenuItemImage::create("storereturn.png", "storereturn.png", CC_CALLBACK_1(EquipScene::equipReturnCallback, this));
	equipReturn->setPosition(Vec2(640, 55));

	Menu *mu = Menu::create(menuVector[0], menuVector[1], menuVector[2], menuVector[3], menuVector[4], menuVector[5], menuVector[6],\
	menuVector[7], menuVector[8], menuVector[9], menuVector[10], menuVector[11], menuVector[12], menuVector[13], menuVector[14],\
	menuVector[15], equipReturn, NULL);
	mu->setPosition(Vec2::ZERO);
	equipbg->addChild(mu);
	return true;
}
void EquipScene::equipReturnCallback(Ref* pSender)
{
	this->removeFromParent();
}
void EquipScene::equipCallbackEquipped(Ref* pSender)
{
	MenuItemToggle* equipButton = (MenuItemToggle*)pSender;
	int tag = equipButton->getTag();
	if (equipButton->getSelectedIndex() == 1)
	{
		equipmentEquippedList[tag] = 0;
		switch (tag)
		{
		case 0:
			clientPlayer->bonusAttack = ((clientPlayer->bonusAttack - 10) > 0 ? (clientPlayer->bonusAttack - 10) : 0);
			break;
		case 1:
			clientPlayer->bonusAttack = ((clientPlayer->bonusAttack - 25) > 0 ? (clientPlayer->bonusAttack - 25) : 0);
			break;
		case 2:
			clientPlayer->bonusAttack = ((clientPlayer->bonusAttack - 50) > 0 ? (clientPlayer->bonusAttack - 50) : 0);
			break;
		case 3:
			clientPlayer->bonusAttack = ((clientPlayer->bonusAttack - 80) > 0 ? (clientPlayer->bonusAttack - 80) : 0);
			break;
		case 4:
			clientPlayer->bonusDefend = ((clientPlayer->bonusDefend - 10) > 0 ? (clientPlayer->bonusDefend - 10) : 0);
			break;
		case 5:
			clientPlayer->bonusDefend = ((clientPlayer->bonusDefend - 25) > 0 ? (clientPlayer->bonusDefend - 25) : 0);
			break;
		case 6:
			clientPlayer->bonusDefend = ((clientPlayer->bonusDefend - 50) > 0 ? (clientPlayer->bonusDefend - 50) : 0);
			break;
		case 7:
			clientPlayer->bonusDefend = ((clientPlayer->bonusDefend - 80) > 0 ? (clientPlayer->bonusDefend - 80) : 0);
			break;
		case 8:
			clientPlayer->bonusBlood = ((clientPlayer->bonusBlood - 50) > 0 ? (clientPlayer->bonusBlood - 50) : 0);
			clientPlayer->equipbonusBlood(clientPlayer->bonusBlood);
			break;
		case 9:
			clientPlayer->bonusBlood = ((clientPlayer->bonusBlood - 100) > 0 ? (clientPlayer->bonusBlood - 100) : 0);
			clientPlayer->equipbonusBlood(clientPlayer->bonusBlood);
			break;
		case 10:
			clientPlayer->bonusBlood = ((clientPlayer->bonusBlood - 150) > 0 ? (clientPlayer->bonusBlood - 150) : 0);
			clientPlayer->equipbonusBlood(clientPlayer->bonusBlood);
			break;
		case 11:
			clientPlayer->bonusBlood = ((clientPlayer->bonusBlood - 200) > 0 ? (clientPlayer->bonusBlood - 200) : 0);
			clientPlayer->equipbonusBlood(clientPlayer->bonusBlood);
			break;
		case 12:
			clientPlayer->bonusSpeed = ((clientPlayer->bonusSpeed - 5) > 0 ? (clientPlayer->bonusSpeed - 5) : 0);
			break;
		case 13:
			clientPlayer->bonusSpeed = ((clientPlayer->bonusSpeed - 15) > 0 ? (clientPlayer->bonusSpeed - 15) : 0);
			break;
		case 14:
			clientPlayer->bonusSpeed = ((clientPlayer->bonusSpeed - 25) > 0 ? (clientPlayer->bonusSpeed - 25) : 0);
			break;
		case 15:
			clientPlayer->bonusSpeed = ((clientPlayer->bonusSpeed - 50) > 0 ? (clientPlayer->bonusSpeed - 50) : 0);
			break;
		}
	}		
}
