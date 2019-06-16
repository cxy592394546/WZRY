#include "GameScenes.h"
#include"cocos2d.h"
#include"ShopScene.h"
#include"GameOver.h"
USING_NS_CC;

Scene* GameScenes::createScene()
{
	
	auto scene = Scene::create();


	auto layer = GameScenes::create();

	scene->addChild(layer);

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
	
	/*MenuItemImage*shopMenuItem = MenuItemImage::create("shopscene-up.png","shopscene-down.png",CC_CALLBACK_1(GameScenes::menuItem1CallBack,this));
	
	*/
	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(43);
	MenuItemFont*item1 = MenuItemFont::create("SHOP", CC_CALLBACK_1(GameScenes::menuItem1Callback, this));
	
	Menu*mn = Menu::create( item1, NULL);
	mn->setPosition(1200,1000);
	this->addChild(mn,1);
	_tileMap = TMXTiledMap::create("map/Map.tmx");
	addChild(_tileMap, 0, 100);
	_player = Sprite::create("Soldier&Hero/H00003.png");
	_player->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(_player, 2, 200);
	_monsterRed = Sprite::create("redbuff.jpg");
	_monsterRed->setPosition(300,800);
	addChild(_monsterRed, 2, 200);
	_monsterBlue = Sprite::create("bluebuff.jpg");
	_monsterBlue->setPosition(800,300);
	addChild(_monsterBlue, 2, 200);
	_monsterRuler = Sprite::create("boss.jpg");
	_monsterRuler->setPosition(200,1000);
	addChild(_monsterRuler, 2, 200);
	_enemy1 = Sprite::create("Soldier&Hero/S10001.png");
	_enemy1->setPosition(800,800);
	addChild(_enemy1, 2, 200);
	FiniteTimeAction*ab0 = (FiniteTimeAction*)_enemy1->runAction(MoveTo::create(130, Vec2(300,300)));
	FiniteTimeAction*ab1 = (FiniteTimeAction*)_enemy1->runAction(MoveTo::create(130, Vec2(800,800)));
	_enemy1->runAction(Sequence::create(ab0, ab1, ab0,ab1,ab0,ab1 ,ab0,ab1,ab0,ab1,ab0,ab1,NULL));
	_enemy2 = Sprite::create("Soldier&Hero/S10002.png");
	_enemy2->setPosition(840, 840);
	addChild(_enemy2, 2, 200);
	FiniteTimeAction*ab00 = (FiniteTimeAction*)_enemy2->runAction(MoveTo::create(130, Vec2(250,400)));
	FiniteTimeAction*ab11 = (FiniteTimeAction*)_enemy2->runAction(MoveTo::create(130, Vec2(840, 840)));
	_enemy2->runAction(Sequence::create(ab00, ab11, ab00, ab11, ab00, ab11, ab00, ab11, ab00, ab11, ab00, ab11, NULL));
	_enemy3 = Sprite::create("Soldier&Hero/S10003.png");
	_enemy3->setPosition(880, 880);
	addChild(_enemy3, 2, 200);
	FiniteTimeAction*ab000 = (FiniteTimeAction*)_enemy3->runAction(MoveTo::create(130, Vec2(400,250)));
	FiniteTimeAction*ab111 = (FiniteTimeAction*)_enemy3->runAction(MoveTo::create(130, Vec2(880, 880)));
	_enemy3->runAction(Sequence::create(ab000, ab111, ab000, ab111, ab000, ab111, ab000, ab111, ab000, ab111, ab000, ab111, NULL));
	Sprite *_soldier1 = Sprite::create("Soldier&Hero/S00001.png");
	_soldier1->setPosition(200, 200);
	addChild(_soldier1, 2, 200);
	FiniteTimeAction*ac2 = (FiniteTimeAction*)_soldier1->runAction(MoveTo::create(130, Vec2(700, 900)));
	FiniteTimeAction*ac3 = (FiniteTimeAction*)_soldier1->runAction(MoveTo::create(130, Vec2(200,200)));
	_soldier1->runAction(Sequence::create(ac2, ac3, ac2,ac3, ac2, ac3, ac2, ac3, ac2, ac3, ac2, ac3, ac2, ac3, ac2, ac3, NULL));
	_soldier2 = Sprite::create("Soldier&Hero/S00002.png");
	_soldier2->setPosition(240, 240);
	addChild(_soldier2, 2, 200);
	FiniteTimeAction*ac4 = (FiniteTimeAction*)_soldier2->runAction(MoveTo::create(130, Vec2(900,700)));
	FiniteTimeAction*ac5 = (FiniteTimeAction*)_soldier2->runAction(MoveTo::create(130, Vec2(240, 240)));
	_soldier2->runAction(Sequence::create(ac4, ac5, ac4, ac5, ac4, ac5, ac4, ac5, ac4, ac5, ac4, ac5, ac4, ac5, ac4, ac5, NULL));
	_soldier3 = Sprite::create("Soldier&Hero/S00003.png");
	_soldier3->setPosition(280, 280);
	addChild(_soldier3, 2, 200);
	FiniteTimeAction*ac0 = (FiniteTimeAction*)_soldier3->runAction(MoveTo::create(130, Vec2(850,850)));
	FiniteTimeAction*ac1 = (FiniteTimeAction*)_soldier3->runAction(MoveTo::create(130, Vec2(280, 280)));
	_soldier3->runAction(Sequence::create(ac0, ac1,  ac0,ac1, ac0, ac1, ac0, ac1, ac0, ac1, ac0, ac1, ac0, ac1, ac0, ac1, NULL));
	_tower1 = Sprite::create("map/Tower1.png");
	_tower1->setPosition(1000, 1000);
	addChild(_tower1, 2, 200);
	_tower2 = Sprite::create("map/Tower1.png");
	_tower2->setPosition(130,140);
	addChild(_tower2, 2, 200);
	setViewpointCenter(_player->getPosition());
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScenes::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScenes::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	setTouchEnabled(true);
	
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	return true;
}
void GameScenes::updateStatusBarMoney()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	__String * score = __String::createWithFormat("%d", this->money);
	auto lblScore = Label::createWithTTF(score->getCString(), "fonts/hanyi.ttf", 18);
	lblScore->setPosition(1100,1000);
	this->addChild(lblScore, 1);

}

void GameScenes::menuItem1Callback(Ref*pSender)
{
	auto sc = ShopScene::createScene();
	Director::getInstance()->pushScene(sc);
}
void GameScenes::keyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		log(" w is keyPressed ");
		enemyHP1 -= heroAttack;
		monsterRedHP -= heroAttack;
		money += 50;
		if (enemyHP1 <= 0)
		{
			_enemy1->setVisible(false);
		}
		if (monsterRedHP<= 0)
		{
			_monsterRed->setVisible(false);
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		log(" q is keyPressed ");
		enemyHP2 -= heroAttack;
		monsterBlueHP -= heroAttack;
		money += 50;
		if (enemyHP2 <= 0)
		{
			_enemy2->setVisible(false);
		}
		if (monsterBlueHP <= 0)
		{
			_monsterBlue->setVisible(false);
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_E)
	{
		log(" e is keyPressed ");
		enemyHP3 -= heroAttack;
		monsterRulerHP -= heroAttack;
		money += 50;
		if (enemyHP3 <= 0)
		{
			_enemy3->setVisible(false);
		}
		if (monsterRulerHP <= 0)
		{
			_monsterRuler->setVisible(false);
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S)
	{
		log(" s is keyPressed ");
		towerHP2 -= heroAttack;
		money += 100;
		if (towerHP2 <= 0)
		{
			_tower1->setVisible(false);
			auto scene = GameOver::createScene();
			Director::getInstance()->pushScene(scene);
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_L)
	{
		log(" l is keyPressed ");
		heroAttack += 5;

	}
	if (keyCode == EventKeyboard::KeyCode::KEY_P)
	{
		log(" p is keyPressed ");
		heroAttack += 10;

	}
	if (keyCode == EventKeyboard::KeyCode::KEY_M)
	{
		log(" m is keyPressed ");
		heroAttack += 15;

	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto label1 = Label::createWithSystemFont("level1", "Arial", 30);
	label1->setPosition(Vec2(1200,900));
	this->addChild(label1, 1);
	if (money > 100)
	{
		
		auto label2 = Label::createWithSystemFont("level2", "Arial", 30);
		label2->setPosition(Vec2(1200,850));
		this->addChild(label2, 1);
	}
	if (money > 250)
	{

		auto label3 = Label::createWithSystemFont("level3", "Arial", 30);
		label3->setPosition(Vec2(1200, 800));
		this->addChild(label3, 1);
	}
	if (money > 400)
	{

		auto label2 = Label::createWithSystemFont("level4", "Arial", 30);
		label2->setPosition(Vec2(1200, 750));
		this->addChild(label2, 1);
	}
	if (money > 550)
	{

		auto label2 = Label::createWithSystemFont("level5", "Arial", 30);
		label2->setPosition(Vec2(1200, 700));
		this->addChild(label2, 1);
	}
	if (money > 700)
	{

		auto label2 = Label::createWithSystemFont("level6", "Arial", 30);
		label2->setPosition(Vec2(1200, 650));
		this->addChild(label2, 1);
	}
	if (money > 850)
	{

		auto label2 = Label::createWithSystemFont("level7", "Arial", 30);
		label2->setPosition(Vec2(1200, 600));
		this->addChild(label2, 1);
	}

}
void GameScenes::towerAI(Event *event)
{
	Vec2 playerPos = _player->getPosition();
	Vec2 towerPos = _tower1->getPosition();
	Vec2 diff = towerPos - playerPos;
	if (diff.x < 150&&diff.y<150)
	{
		heroHP -= towerAttack;
	}
	if (diff.x < 110 && diff.y < 110)
	{
		heroHP -= towerAttack*3/2;
	}
	if (diff.x < 90 && diff.y < 90)
	{
		heroHP -= towerAttack*2;
	}
	if (heroHP < 0)
	{
		_player->setVisible(false);
	}
	
}
void GameScenes::enemyAI(Event *event)
{
	Vec2 enemy1Pos = _enemy1->getPosition();
	Vec2 enemy2Pos = _enemy2->getPosition();
	Vec2 enemy3Pos = _enemy3->getPosition();
	Vec2 towerPos = _tower2->getPosition();
	Vec2 soldier1Pos = _soldier1->getPosition();
	Vec2 soldier2Pos = _soldier2->getPosition();
	Vec2 soldier3Pos = _soldier3->getPosition();
	Vec2 diff1 = enemy1Pos - soldier1Pos;
	if (diff1.x < 150 && diff1.y < 150)
	{
		soldierHP1 -=enemyAttack;
	}
	Vec2 diff2 = enemy1Pos - soldier2Pos;
	if (diff2.x < 150 && diff2.y < 150)
	{
		soldierHP2 -= enemyAttack;
	}
	Vec2 diff3 = enemy1Pos - soldier3Pos;
	if (diff3.x < 150 && diff3.y < 150)
	{
		soldierHP3 -= enemyAttack;
	}
	Vec2 diff4 = enemy1Pos - towerPos;
	if (diff4.x < 150 && diff4.y < 150)
	{
		towerHP2 -= enemyAttack;
	}
	Vec2 diff5 = enemy2Pos - soldier1Pos;
	if (diff1.x < 100 && diff1.y < 100)
	{
		soldierHP1 -= enemyAttack*3/2;
	}
	Vec2 diff6 = enemy2Pos - soldier2Pos;
	if (diff2.x < 100 && diff2.y < 100)
	{
		soldierHP2 -= enemyAttack*3/2;
	}
	Vec2 diff7 = enemy2Pos - soldier3Pos;
	if (diff3.x < 100 && diff3.y < 100)
	{
		soldierHP3 -= enemyAttack*3/2;
	}
	Vec2 diff8 = enemy2Pos - towerPos;
	if (diff4.x < 100 && diff4.y < 100)
	{
		towerHP2 -= enemyAttack*3/2;
	}
	Vec2 diff9 = enemy3Pos - soldier1Pos;
	if (diff1.x < 50 && diff1.y < 50)
	{
		soldierHP1 -= enemyAttack*2;
	}
	Vec2 diff10 = enemy3Pos - soldier2Pos;
	if (diff2.x < 50 && diff2.y < 50)
	{
		soldierHP2 -= enemyAttack*2;
	}
	Vec2 diff11 = enemy3Pos - soldier3Pos;
	if (diff3.x < 50 && diff3.y < 50)
	{
		soldierHP3 -= enemyAttack*2;
	}
	Vec2 diff12 = enemy3Pos - towerPos;
	if (diff4.x < 50 && diff4.y < 50)
	{
		towerHP2 -= enemyAttack*2;
	}
	if (soldierHP1 <= 0)
	{
		_soldier1->setVisible(false);
	}
	if (soldierHP2 <= 0)
	{
		_soldier2->setVisible(false);
	}
	if (soldierHP3 <= 0)
	{
		_soldier3->setVisible(false);
	}
	if (towerHP2 <= 0)
	{
		_tower2->setVisible(false);
	}
}
void GameScenes::soldierAI(Event *event)
{
	Vec2 enemy1Pos = _enemy1->getPosition();
	Vec2 enemy2Pos = _enemy2->getPosition();
	Vec2 enemy3Pos = _enemy3->getPosition();
	Vec2 towerPos = _tower1->getPosition();
	Vec2 soldier1Pos = _soldier1->getPosition();
	Vec2 soldier2Pos = _soldier2->getPosition();
	Vec2 soldier3Pos = _soldier3->getPosition();
	Vec2 diff1 = enemy1Pos - soldier1Pos;
	if (diff1.x < 150 && diff1.y < 150)
	{
		enemyHP1 -= soldierAttack;
	}
	Vec2 diff2 = enemy1Pos - soldier2Pos;
	if (diff2.x < 150 && diff2.y < 150)
	{
		enemyHP2 -= soldierAttack;
	}
	Vec2 diff3 = enemy1Pos - soldier3Pos;
	if (diff3.x < 150 && diff3.y < 150)
	{
		enemyHP3 -= soldierAttack;
	}
	Vec2 diff4 = enemy1Pos - towerPos;
	if (diff4.x < 150 && diff4.y < 150)
	{
		towerHP1 -= soldierAttack;
	}
	Vec2 diff5 = enemy2Pos - soldier1Pos;
	if (diff1.x < 100 && diff1.y < 100)
	{
		enemyHP1 -= soldierAttack * 3 / 2;
	}
	Vec2 diff6 = enemy2Pos - soldier2Pos;
	if (diff2.x < 100 && diff2.y < 100)
	{
		enemyHP2 -= soldierAttack * 3 / 2;
	}
	Vec2 diff7 = enemy2Pos - soldier3Pos;
	if (diff3.x < 100 && diff3.y < 100)
	{
		enemyHP3 -= soldierAttack * 3 / 2;
	}
	Vec2 diff8 = enemy2Pos - towerPos;
	if (diff4.x < 100 && diff4.y < 100)
	{
		towerHP1 -= soldierAttack * 3 / 2;
	}
	Vec2 diff9 = enemy3Pos - soldier1Pos;
	if (diff1.x < 50 && diff1.y < 50)
	{
		enemyHP1 -= soldierAttack * 2;
	}
	Vec2 diff10 = enemy3Pos - soldier2Pos;
	if (diff2.x < 50 && diff2.y < 50)
	{
		enemyHP2 -= soldierAttack * 2;
	}
	Vec2 diff11 = enemy3Pos - soldier3Pos;
	if (diff3.x < 50 && diff3.y < 50)
	{
		enemyHP3 -= soldierAttack * 2;
	}
	Vec2 diff12 = enemy3Pos - towerPos;
	if (diff4.x < 50 && diff4.y < 50)
	{
		towerHP1 -= soldierAttack * 2;
	}
	if (enemyHP1 <= 0)
	{
		_enemy1->setVisible(false);
	}
	if (enemyHP2 <= 0)
	{
		_enemy2->setVisible(false);
	}
	if (enemyHP3 <= 0)
	{
		_enemy3->setVisible(false);
	}
	if (towerHP1 <= 0)
	{
		_tower1->setVisible(false);
	}
}

void GameScenes::keyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W)

	{
		log(" w is keyReleased");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q)

	{
		log(" q is keyReleased");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_E)

	{
		log(" e is keyReleased");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S)

	{
		log(" s is keyReleased");
	}
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
	log("目标位置 (%f ,%f) ", pointB.x, pointB.y);

	
	Vec2 offset = pointA - pointB;
	log("offset (%f ,%f) ", offset.x, offset.y);
	this->setPosition(offset);

}
