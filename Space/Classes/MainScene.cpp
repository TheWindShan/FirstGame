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
    box = this->getBoundingBox();
    sprite = Aircraft::create();
    this->addChild(sprite, 0);
    this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{
    launchMeteors(7);
}

void MainScene::launchMeteors(int num)
{
    if(meteors.size()<num){
        meteor = Meteor::create();
        meteors.push_back(meteor);
        this->addChild(meteor, -1);
        meteor->toMove();
    }
    for(unsigned int i=0;i<meteors.size();i++){
        Vec2 location = meteors[i]->getPosition();
        if(!box.containsPoint(location))
        {
            if(meteors[i]->getAnimed()){            
                meteors[i]->release();
                meteors.erase(meteors.begin() + i);
            }
        }
    }
}

