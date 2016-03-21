#include "MainScene.h"
#include <algorithm>

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = MainScene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Device::setKeepScreenOn(true);
    Device::setAccelerometerEnabled(true);
    Device::setAccelerometerInterval(1.0 / 60);
    
    auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    sprite = Aircraft::create();
    addChild(sprite, 0);
    box = this->getBoundingBox();
    this->scheduleUpdate();
    return true;
}

void MainScene::update(float delta)
{
    launchMeteors(7);
    Meteor* meteor = sprite->shotCollision(meteors);
    if(meteor){
        removeMeteor(meteor);
    }
}

void MainScene::launchMeteors(unsigned int num)
{
    if(meteors.size()<num){
        Meteor* meteor = Meteor::create();
        addMeteor(meteor);
        meteor->toMove();
    }
    for(Meteor* meteor: meteors){
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
        meteor->removeFromParent();
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
