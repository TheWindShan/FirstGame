#include "MainScene.h"
#include <algorithm>

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    sprite = Aircraft::create();
    // sprite->defineScene(this);
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(sprite, 0);

    // this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{

}
