#include"ShopScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
Scene* ShopScene::createScene()
{
	return ShopScene::create();
}
bool ShopScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite*bg = Sprite::create("shop.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bg,0);
	Sprite*sword = Sprite::create("sword.png");
	sword->setPosition(Vec2(80,200));
	this->addChild(sword,1);
	Sprite*spatha = Sprite::create("spatha.jpg");
	spatha->setPosition(Vec2(80, 130));
	this->addChild(spatha, 1);
	Sprite*axe= Sprite::create("axe.jpg");
	axe->setPosition(Vec2(80, 60));
	this->addChild(axe, 1);
	auto okMenuItem = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(ShopScene::menuOkCallback, this));
	okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(origin.x + visibleSize.width / 4 * 3, origin.y + visibleSize.height / 4)));
	Menu *mn = Menu::create(okMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);
	auto label1 = Label::createWithSystemFont("if you reach level3,press L to buy sword", "Arial", 10);
	label1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 70));
	this->addChild(label1, 1);
	auto label2 = Label::createWithSystemFont("if you reach level5,press P to buy spatha", "Arial", 10);
	label2->setPosition(Vec2(origin.x + visibleSize.width / 2, 130));
	this->addChild(label2, 1);
	auto label3 = Label::createWithSystemFont("if you reach level7,press M to buy axe", "Arial", 10);
	label3->setPosition(Vec2(origin.x + visibleSize.width / 2, 60));
	this->addChild(label3, 1);
	return true;

}
void ShopScene::menuOkCallback(Ref*pSender)
{
	Director::getInstance()->popScene();
}