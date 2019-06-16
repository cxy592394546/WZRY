
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "HelpScene.h"
#include"GameScenes.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

  
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

   

    auto label = Label::createWithTTF("GLORY OF KING", "fonts/Marker Felt.ttf", 48);
   
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("background.jpg");
  
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2+ origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite,0);
    }
	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(43);
	MenuItemFont*item1 = MenuItemFont::create("help", CC_CALLBACK_1(HelloWorld::menuItem1Callback, this));
	MenuItemFont*item2 = MenuItemFont::create("start", CC_CALLBACK_1(HelloWorld::menuItem2Callback, this));
	Menu*mn = Menu::create(item2,item1, NULL);
	mn->alignItemsVertically();
	this->addChild(mn);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::menuItemStartCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::menuItem1Callback(Ref*pSender)
{
	auto sc = HelpScene::createScene();
	Director::getInstance()->pushScene(sc);
}
void HelloWorld::menuItem2Callback(cocos2d::Ref * pSender) {
	log("play"); auto scene = GameScenes::createScene();
	Director::getInstance()->pushScene(scene);
	
}

