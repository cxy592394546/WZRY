#include "GameScenes.h"

USING_NS_CC;

Scene* GameScenes::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScenes::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


bool GameScenes::init()
{
	
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("map/Map.tmx");
	addChild(_tileMap, 0, 100);

	_player = Sprite::create("Soldier&Hero/H00001.png");
	_player->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(_player, 2, 200);
	_enemy1 = Sprite::create("Soldier&Hero/S10001.png");
	_enemy1->setPosition(800,800);
	addChild(_enemy1, 2, 200);
	_enemy2 = Sprite::create("Soldier&Hero/S10002.png");
	_enemy2->setPosition(840, 840);
	addChild(_enemy2, 2, 200);
	_enemy3 = Sprite::create("Soldier&Hero/S10003.png");
	_enemy3->setPosition(880, 880);
	addChild(_enemy3, 2, 200);
	_soldier1 = Sprite::create("Soldier&Hero/S00001.png");
	_soldier1->setPosition(200, 200);
	addChild(_soldier1, 2, 200);
	_soldier2 = Sprite::create("Soldier&Hero/S00002.png");
	_soldier2->setPosition(240, 240);
	addChild(_soldier2, 2, 200);
	_soldier3 = Sprite::create("Soldier&Hero/S00003.png");
	_soldier3->setPosition(280, 280);
	addChild(_soldier3, 2, 200);
	_tower1 = Sprite::create("map/Tower1.png");
	_tower1->setPosition(1000, 1000);
	addChild(_tower1, 2, 200);
	_tower2 = Sprite::create("map/Tower1.png");
	_tower2->setPosition(130,140);
	addChild(_tower2, 2, 200);
	setViewpointCenter(_player->getPosition());

	

	setTouchEnabled(true);
	
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	return true;
}

bool GameScenes::onTouchBegan(Touch* touch, Event* event)
{
	log("onTouchBegan");
	return true;
}

void GameScenes::onTouchMoved(Touch *touch, Event *event)
{
	log("onTouchMoved");
}

void GameScenes::onTouchEnded(Touch *touch, Event *event)
{
	log("onTouchEnded");
	
	Vec2 touchLocation = touch->getLocation();
	
	touchLocation = this->convertToNodeSpace(touchLocation);

	Vec2 playerPos = _player->getPosition();
	Vec2 diff = touchLocation - playerPos;

	if (abs(diff.x) > abs(diff.y)) {
		if (diff.x > 0) {
			playerPos.x += _tileMap->getTileSize().width;
			_player->runAction(FlipX::create(false));
		}
		else {
			playerPos.x -= _tileMap->getTileSize().width;
			_player->runAction(FlipX::create(true));
		}
	}
	else {
		if (diff.y > 0) {
			playerPos.y += _tileMap->getTileSize().height;
		}
		else {
			playerPos.y -= _tileMap->getTileSize().height;
		}
	}
	this->setPlayerPosition(playerPos);
}

void GameScenes::setPlayerPosition(Vec2 position)
{
	
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	
	_player->setPosition(position);
	
	this->setViewpointCenter(_player->getPosition());
}

Vec2 GameScenes::tileCoordFromPosition(Vec2 pos)
{
	int x = pos.x / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - pos.y) / _tileMap->getTileSize().height;
	return Vec2(x, y);
}

void GameScenes::setViewpointCenter(Vec2 position)
{
	log("setViewpointCenter");

	log("position (%f ,%f) ", position.x, position.y);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);
	
	x = MIN(x, (_tileMap->getMapSize().width * _tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height)
		- visibleSize.height / 2);

	
	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	
	Vec2 pointB = Vec2(x, y);
	log("Ä¿±êÎ»ÖÃ (%f ,%f) ", pointB.x, pointB.y);

	
	Vec2 offset = pointA - pointB;
	log("offset (%f ,%f) ", offset.x, offset.y);
	this->setPosition(offset);

}
