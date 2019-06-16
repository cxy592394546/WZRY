#include"GameOver.h"
USING_NS_CC;
Scene* GameOver::createScene()
{
	return GameOver::create();
}
bool GameOver::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite*bg = Sprite::create("GameOver.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bg);
	return true;
}