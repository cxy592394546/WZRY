#include"HelpScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
Scene* HelpScene::createScene()
{
	return HelpScene::create();
}
bool HelpScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite*bg = Sprite::create("helpground.jpg");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bg);
	auto okMenuItem = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelpScene::menuOkCallback, this));
	okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(origin.x + visibleSize.width / 4*3, origin.y + visibleSize.height / 4)));
	Menu *mn = Menu::create(okMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);
	auto label1 = Label::createWithSystemFont("glory of king is a moba game", "Arial", 10);
	label1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 70));
	this->addChild(label1, 1);
	auto label2= Label::createWithSystemFont("using mouse to move your hero", "Arial", 10);
	label2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 50));
	this->addChild(label2, 1);
	auto label3 = Label::createWithSystemFont("choosing your hero among houyi,luban,liubei", "Arial", 10);
	label3->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 30));
	this->addChild(label3, 1);
	auto label4 = Label::createWithSystemFont("pressing Q,W ,Eor S to use its skills", "Arial", 10);
	label4->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 10));
	this->addChild(label4, 1);
	auto label5 = Label::createWithSystemFont("Have a nice game!", "Arial", 30);
	label5->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 50));
	this->addChild(label5, 1);
	return true;

}
void HelpScene::menuOkCallback(Ref*pSender)
{
	Director::getInstance()->popScene();
}