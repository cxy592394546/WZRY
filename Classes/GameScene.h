#pragma once
#include"cocos2d.h"
USING_NS_CC;
class GameScene : public Layer
{
public:
	TMXTiledMap * _tileMap;
	cocos2d::Sprite*hero;
	static cocos2d::Scene* createScene();
	virtual bool init();
	void setViewpointCenter(Vec2 position);
	//void menuCloseCallback(cocos2d::Ref* pSender);
	/*virtual bool onTouchBegan(Touch *touch, Event *unused_event);
  virtual void onTouchMoved(Touch *touch, Event *unused_event);
  virtual void onTouchEnded(Touch *touch, Event *unused_event);
  virtual void onEnter();
  virtual void onExit();*/
	CREATE_FUNC(GameScene);
};
