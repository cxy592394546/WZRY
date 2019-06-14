#pragma once
#ifndef __GAMESCENES_SCENE_H__
#define __GAMESCENES_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"


class GameScenes : public cocos2d::Layer
{
	cocos2d::TMXTiledMap* _tileMap;
	
	cocos2d::Sprite *_player;
	cocos2d::Sprite *_soldier1;
	cocos2d::Sprite *_soldier2;
	cocos2d::Sprite *_soldier3;
	cocos2d::Sprite *_enemy1;
	cocos2d::Sprite *_enemy2;
	cocos2d::Sprite *_enemy3;
	cocos2d::Sprite *_tower1;
	cocos2d::Sprite *_tower2;
public:
	
	static cocos2d::Scene* createScene();

	
	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	void setPlayerPosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
	void setViewpointCenter(cocos2d::Vec2 position);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScenes);
};

#endif // __GAMESCENES_SCENE_H__

