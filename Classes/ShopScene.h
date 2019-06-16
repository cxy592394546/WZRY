#pragma once
#ifndef __SHOPCENE_H__
#define __SHOPSCENE_H__

#include "cocos2d.h"
#include"GameScenes.h"
class ShopScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();


	void menuOkCallback(cocos2d::Ref*pSender);

	CREATE_FUNC(ShopScene);
};
#endif // __HELPSCENE_H__
