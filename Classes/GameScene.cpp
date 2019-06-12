#include"GameScene.h"
USING_NS_CC;
cocos2d::Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	_tileMap = TMXTiledMap::create("map/Map.tmx");
	_tileMap->setAnchorPoint(Vec2(0, 0));			
	_tileMap->setPosition(Vec2(0, 0));				
	this->addChild(_tileMap,10);
    Sprite*hero = Sprite::create("hero.png");
	addChild(hero, 100);
	/*Vec2 vPos = hero->getPosition();
	float x = MAX(vPos.x, visibleSize.width / 2);
	float y = MAX(vPos.x, visibleSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width * _tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height)
		- visibleSize.height / 2);
	Vec2 destPos = Vec2(x, y);
	Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	Vec2 viewPos = centerPos - destPos;
	this->setPosition(viewPos);*/

	

	/*setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	return (true);*/
		auto listener1 = EventListenerTouchOneByOne::create();
		listener1->setSwallowTouches(true);

		//通过 lambda 表达式 直接实现触摸事件的回掉方法
		listener1->onTouchBegan = [](Touch* touch, Event* event) {
			auto target = static_cast<Sprite*>(event->getCurrentTarget());

			Point locationInNode = target->convertToNodeSpace(touch->getLocation());
			Size s = target->getContentSize();
			Rect rect = Rect(0, 0, s.width, s.height);

			if (rect.containsPoint(locationInNode))
			{
				log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
				target->setOpacity(180);//点击的时候精灵颜色变暗，255为最大值，0最小
				return true;
			}
			return false;
		};



		listener1->onTouchMoved = [](Touch* touch, Event* event) {
			auto target = static_cast<Sprite*>(event->getCurrentTarget());
			target->setPosition(target->getPosition() + touch->getDelta());
		};

		listener1->onTouchEnded = [=](Touch* touch, Event* event) {
			auto target = static_cast<Sprite*>(event->getCurrentTarget());
			log("sprite onTouchesEnded.. ");
			target->setOpacity(255);//手势松开时使精灵恢复原来的颜色
		};


		//将触摸事件绑定到精灵身上
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, hero);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), hero);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), hero);

		return true;
};
void GameScene::setViewpointCenter(Vec2 position)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float x = MAX(position.x, visibleSize.width / 2);
	float y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width * _tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height)
		- visibleSize.height / 2);
	Vec2 destPos = Vec2(x, y);
	Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	Vec2 viewPos = centerPos - destPos;
	this->setPosition(viewPos);


}

/*void GameScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}*/
/*void GameScene::onEnter()
{
	Layer::onEnter();
	log("GameScene onEnter");
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	EventDispatcher*eventDispatcher = Director::getInstance()->getEventDispatcher();
	//eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
bool GameScene::onTouchBegan(Touch *touch, Event *event)
 {
	  
	/*auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	log("onTouchBegan");
	return true;
	 }
 
void GameScene::onTouchMoved(Touch *touch, Event *event)
{
	   
	log("onTouchMoved");
	/*auto target = static_cast<Sprite*>(event->getCurrentTarget());
	target->setPosition(target->getPosition() + touch->getDelta());
	Vec2 touchLocation = touch->getLocation();
	Vec2 playerPos = hero->getPosition();
	Vec2 diff = touchLocation - playerPos;
	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			playerPos.x += _tileMap->getTileSize().width;
			hero->runAction(FlipX::create(false));
		}
		else
		{
			playerPos.x -= _tileMap->getTileSize().width;
			hero->runAction(FlipX::create(true));
		}
	}
	else
	{
		if (diff.y > 0)
		{
			playerPos.y += _tileMap->getTileSize().height;
		}
		else
		{
			playerPos.y -= _tileMap->getTileSize().height;
		}
	}
	hero->setPosition(playerPos);
	}
void GameScene::onTouchEnded(Touch*touch, Event*event)
{
	log("onTouchEnded");
	
}
void GameScene::onExit()
{
	Layer::onExit();
	log("GameScene onExit");
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}*/
