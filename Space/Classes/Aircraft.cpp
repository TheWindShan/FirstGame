#include "Aircraft.h"
#include <algorithm>

USING_NS_CC;

Aircraft::Aircraft()
{
    visibleSize = Director::getInstance()->getWinSize();
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
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Aircraft::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Aircraft::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    scheduleUpdate();
}

void Aircraft::update(float delta)
{
    auto loc = this->getPosition();
    float angle = fmod(this->getRotation(), 360);
    Vec2 vec;
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW)){
        this->move();
        // this->shotLaser(laserGreen);
        // auto ac = RotateTo::create(1.0f, Vec3(0, 30, 0));
        // this->runAction(ac);
    }

    if(isKeyPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW)){
        if(isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW)){        
            this->setRotation(--angle);

        }
        if(isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)){
            this->setRotation(++angle);
        }
    }
}

void Aircraft::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    keys.push_back(keyCode);
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE)){
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
    auto move = MoveTo::create(0.1, destination);
    this->runAction(move);
}

void Aircraft::shotLaser()
{
    // this->setRotation(180);
    Vec2 nodeLocation = this->getPosition();
    float nodeAngle = fmod(this->getRotation(), 360);
    // log("%f", nodeAngle);
    float angle = nodeAngle;
    float nodeAngleRadius = angle * (M_PI/180);
    float yOff = visibleSize.height - nodeLocation.y;
    if(angle == 90 || angle == 180){
        yOff = nodeLocation.y;
    }
    float deltax = yOff * tan(nodeAngleRadius);
    float deltay = yOff;
    float dx = nodeLocation.x + deltax;
    float dy = nodeLocation.y + deltay;

    if(angle > 90 && angle < 180){
        dx = nodeLocation.x - deltax;
        dy = nodeLocation.y - deltay;
    }else if(angle > 180 && angle < 270){
        dx = nodeLocation.x - deltax;
        dy = nodeLocation.y - deltay;
    }else if(angle < -90 && angle > -180){
        dx = nodeLocation.x - deltax;
        dy = nodeLocation.y - deltay;
    }else if(angle==90){
        dx = visibleSize.width;
        dy = nodeLocation.y;
    }else if(angle==-90){
        dx = -visibleSize.width;
        dy = nodeLocation.y;
    }else if(angle==-180){
        dx = nodeLocation.x;
        dy = -visibleSize.height;
    }
    Vec2 destination = Vec2(dx, dy);
    auto actionLaser = MoveTo::create(1.0, destination);
    Sprite *laser = Sprite::create("res/laserGreen.png");
    laser->setPosition(nodeLocation);
    laser->setRotation(nodeAngle);
    laser->runAction(actionLaser);
    this->getParent()->addChild(laser);
}