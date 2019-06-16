#pragma once
#ifndef __GAMESCENES_SCENE_H__
#define __GAMESCENES_SCENE_H__
#define GameSceneNodeTagStatusBarScore				303

#include "cocos2d.h"
#include "SimpleAudioEngine.h"


class GameScenes : public cocos2d::Layer
{
public:
	cocos2d::TMXTiledMap* _tileMap;
	
	cocos2d::Sprite *_player;
	cocos2d::Sprite *_soldier1;
	cocos2d::Sprite *_soldier2;
	cocos2d::Sprite *_soldier3;
	cocos2d::Sprite *_enemy1;
	cocos2d::Sprite *_enemy2;
	cocos2d::Sprite *_enemy3;
	cocos2d::Sprite *_monsterRed;
	cocos2d::Sprite *_monsterBlue;
	cocos2d::Sprite *_monsterRuler;
	cocos2d::Sprite *_tower1;
	cocos2d::Sprite *_tower2;
	int enemyHP1= 60;
	int enemyHP2 = 60;
	int enemyHP3 = 60;
	int towerHP2 = 100;
	int monsterRedHP = 220;
	int monsterBlueHP = 220;
	int monsterRulerHP = 220;
	int soldierHP1 = 60;
	int soldierHP2 = 60;
	int soldierHP3 = 60;
	int towerHP1 = 100;
	int heroHP = 120;
	int money = 0;
	int heroAttack = 10;
	int enemyAttack = 5;
	int soldierAttack = 5;
	int towerAttack = 10;
	
	static cocos2d::Scene* createScene();

	
	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);//按下键盘处理函数
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode,cocos2d:: Event *event);//松开键盘判断函数
	void setPlayerPosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
	void setViewpointCenter(cocos2d::Vec2 position);
	//static MenuItemImage*create(const std::string&normalImage, const std::string&selectedImage, const std::string&disabledImage, const ccMenuCallback&callback);
	void menuItem1Callback(cocos2d::Ref*pSender);
	void GameScenes::updateStatusBarMoney();
	void GameScenes::towerAI(cocos2d::Event *event);
	void GameScenes::enemyAI(cocos2d::Event *event);
	void GameScenes::soldierAI(cocos2d::Event *event);
	// implement the "static create()" method manually
	CREATE_FUNC(GameScenes);
};

#endif // __GAMESCENES_SCENE_H__

