#include "Aircraft.h"
#include <algorithm>

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
    scheduleUpdate();
}

void Aircraft::update(float delta)
{
    float angle = fmod(this->getRotation(), 360);
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW)){
        this->move();
    }

    if(isKeyPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW)){
        if(isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW)){
            this->setRotation(angle-2.5f);

        }
        if(isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)){
            this->setRotation(angle+2.5f);
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
        this->shotLaser();
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

void Aircraft::move()
{
    Vec2 nodeLocation = this->getPosition();
    float nodeAngle = fmod(this->getRotation(), 360);
    float nodeAngleRadius = nodeAngle * (M_PI/180);
    float yOff = 1;
    if(nodeAngle>90 && nodeAngle<180){
        yOff = -1;
    }else if(nodeAngle<-90 && nodeAngle>-270){
        yOff = -1;
    }
    float deltax = yOff * tan(nodeAngleRadius);
    float deltay = yOff;
    float dx = nodeLocation.x + deltax;
    float dy = nodeLocation.y + deltay;
    if(nodeAngle>180 && nodeAngle<270){
        dx = nodeLocation.x - deltax;
        dy = nodeLocation.y - deltay;
    }
    Vec2 destination = Vec2(dx, dy);
    auto move = MoveTo::create(0.5, destination);
    this->runAction(move);
}

void Aircraft::shotLaser()
{
  Laser* laser;
    // this->setRotation(-90);
    laser = Laser::create();
    float laserHeigth = laser->getBoundingBox().size.height;
    Vec2 nodeLocation = this->getPosition();
    float angle = fmod(this->getRotation(), 360);
    float angleRadius = angle * (M_PI/180);
    float yOff = visibleSize.height - nodeLocation.y;
    float deltax = yOff * tan(angleRadius);
    float dx = nodeLocation.x + deltax;
    float dy = visibleSize.height + laserHeigth;
    if((angle > 90 && angle < 270) || (angle < -90 && angle > -270)){
        yOff = nodeLocation.y;
        deltax = yOff * tan((2*M_PI)-(angleRadius));
        dx = nodeLocation.x + deltax;
        dy = -1*(laserHeigth);
    }else if(angle == 90){
        dx = visibleSize.width + laserHeigth;
        dy = nodeLocation.y;
    }else if(angle == -90){
        dx = -visibleSize.width;
        dy = nodeLocation.y;
    }
    Vec2 destination = Vec2(dx, dy);
    auto actionLaser = MoveTo::create(0.5f, destination);
    auto delay = DelayTime::create(1.0f);
    laser->setPosition(nodeLocation);
    laser->setRotation(angle);
    laser->runAction(actionLaser);
    laser->runAction(delay);
    this->getParent()->addChild(laser, -1);
}

// Implementation of the accelerometer callback function prototype
void Aircraft::onAcceleration(Acceleration *acc, cocos2d::Event *event)
{
    log("X: %f", acc->x);
    log("Y: %f", acc->y);
    log("Z: %f", acc->z);
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
