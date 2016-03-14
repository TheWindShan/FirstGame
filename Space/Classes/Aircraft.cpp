#include "Aircraft.h"
#include "Arm.h"
#include "Meteor.h"
#include <algorithm>
#include <vector>

USING_NS_CC;

Aircraft::Aircraft()
{
    visibleSize = Director::getInstance()->getWinSize();
    Device::setAccelerometerEnabled(true);
}

Aircraft* Aircraft::create()
{
    Aircraft* pSprite = new Aircraft();
    auto pinfo = AutoPolygon::generatePolygon("res/player.png");
    if (pSprite->initWithPolygon(pinfo))
    {
        pSprite->addEvents();
        pSprite->initOptions();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Aircraft::addEvents()
{
    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(Aircraft::onKeyPressed, this);
    keylistener->onKeyReleased = CC_CALLBACK_2(Aircraft::onKeyReleased, this);
    auto aclistener = EventListenerAcceleration::create(CC_CALLBACK_2(Aircraft::onAcceleration, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(aclistener, this);
    this->scheduleUpdate();
}

void Aircraft::update(float delta)
{
    float angle = fmod(this->getRotation(), 360);
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW)){
        this->move();
    }

    if(isKeyPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW)){
        if(isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW)){
            this->setRotation(angle-3.5f);

        }
        if(isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)){
            this->setRotation(angle+3.5f);
        }
    }

    for(auto i : lasers)
    {
        Vec2 location = i->getPosition();
        if(!getBox().containsPoint(location))
        {
            removeLaser(i);
        }
    }
}

void Aircraft::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    keys.push_back(keyCode);
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE)){
        this->shotLaser();
    }
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_ESCAPE)){
        Director::getInstance()->end();
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
        #endif
    }
}

void Aircraft::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    keys.erase(std::remove(keys.begin(), keys.end(), keyCode), keys.end());
}

bool Aircraft::isKeyPressed(EventKeyboard::KeyCode KeyCode)
{
    if ( std::find(keys.begin(), keys.end(), KeyCode) != keys.end() ){
        return true;
    }else{
       return false;
    }
}

void Aircraft::initOptions()
{
    this->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
}

void Aircraft::move()
{
    Vec2 nodeLocation = this->getPosition();
    float nodeAngle = fmod(this->getRotation(), 360);
    float nodeAngleRadius = nodeAngle * (M_PI/180);
    float yOff = 2;
    if((nodeAngle>90 && nodeAngle<180) || (nodeAngle<-90 && nodeAngle>-270)){
        yOff = -2;
    }
    float deltax = yOff * tan(nodeAngleRadius);
    float deltay = yOff;
    float dx = nodeLocation.x + deltax;
    float dy = nodeLocation.y + deltay;
    if(nodeAngle>180 && nodeAngle<270){
        dx = nodeLocation.x - deltax;
        dy = nodeLocation.y - deltay;
    }else if(nodeAngle==90 || nodeAngle==-270){
        dx = nodeLocation.x + 2;
        dy = nodeLocation.y;
    }else if(nodeAngle==-90 || nodeAngle==270){
        dx = nodeLocation.x - 2;
        dy = nodeLocation.y;
    }
    Vec2 destination = Vec2(dx, dy);
    auto move = MoveTo::create(0.1, destination);
    this->runAction(move);
}

void Aircraft::shotLaser()
{   
    laser = Arm::create();
    laser->addToAircraft(this);
    laser->shotLaser();
}

void Aircraft::addLaser(Arm* item)
{
    lasers.push_back(item);
}

void Aircraft::removeLaser(Arm* item)
{
    lasers.erase(std::remove(lasers.begin(), lasers.end(), item), lasers.end());
}

Rect Aircraft::getBox()
{
    return Director::getInstance()->getRunningScene()->getBoundingBox();
}

void Aircraft::onAcceleration(Acceleration *acc, Event *event)
{
    // log("X: %f", acc->x);
    // log("Y: %f", acc->y);
    // log("Z: %f", acc->z);
    float angle = fmod(this->getRotation(), 360);
    if(acc->y <-0.8f){
        if(acc->z <-0.2f){
            this->move();
        }
        if(acc->z > 0.08f){
            this->shotLaser();
        }
        if(acc->x <-0.08f){
            this->setRotation(angle-2.5f);
        }else if(acc->x > 0.08f){
            this->setRotation(angle+2.5f);
        }
    }
}

void Aircraft::shotCollision(std::vector<Meteor*> meteors)
{
    for(auto laser: lasers){
        for(auto meteor: meteors){
            
        }
    }
}

