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
    launchMeteors(70);
    sprite->shotCollision(meteors);
}

void MainScene::launchMeteors(unsigned int num)
{
    if(meteors.size()<num){
        meteor = Meteor::create();
        addMeteor(meteor);
        meteor->toMove();
    }
    for(auto meteor: meteors){
        if(!box.containsPoint(meteor->getPosition()))
        {
            if(meteor->getAnimed()){            
                removeMeteor(meteor);
            }
        }
    }
}

void MainScene::addMeteor(Meteor* meteor)
{
    meteors.push_back(meteor);
    this->addChild(meteor, -1);
}


void MainScene::removeMeteor(Meteor* meteor)
{
    if(findMeteor(meteor)){    
        meteors.erase(std::remove(meteors.begin(), meteors.end(), meteor), meteors.end());
        meteor->release();
   }
}

bool MainScene::findMeteor(Meteor* meteor)
{
    if ( std::find(meteors.begin(), meteors.end(), meteor) != meteors.end() ){
        return true;
    }else{
       return false;
    }
}
