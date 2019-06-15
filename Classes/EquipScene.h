#pragma once
#ifndef __EQUIP_SCENE_H__
#define __EQUIP_SCENE_H__
#include "cocos2d.h"
#include"ui/UIRadioButton.h"
class EquipScene :public cocos2d::Layer
{
public:
	static EquipScene* createScene();
	virtual bool init();
	void equipReturnCallback(Ref* pSender);
	void equipCallback(Ref* pSender);
	void equipCallbackEquipped(Ref* pSender);
	void equipCallback_s(Ref* pSender);
	CREATE_FUNC(EquipScene);
};
#endif
