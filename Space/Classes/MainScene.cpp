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
    Device::setKeepScreenOn(true);
    sprite = Aircraft::create();
    this->addChild(sprite, 0);
    this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{
    meteor = Meteor::create();
    this->addChild(meteor, -1);
    meteor->moveDown();
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

}
