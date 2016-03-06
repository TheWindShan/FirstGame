#include "MainScene.h"
#include <algorithm>
#include <vector>
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
    box = this->getBoundingBox();
    sprite = Aircraft::create();
    this->addChild(sprite, 0);
    this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{
    if(meteors.size()<10){
        meteor = Meteor::create();
        meteors.push_back(meteor);
        meteor->moveDown();
        this->addChild(meteor, -1);
    }
    for(int i=0;i<meteors.size();i++){
        Vec2 location = meteors[i]->getPosition();
        if(!box.containsPoint(location))
        {
            meteors.erase(meteors.begin() + i);
        }
    }
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

}
