#include <algorithm>
#include <vector>
#include "Aircraft.h"
#include "Arm.h"
#include "Meteor.h"

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
        pSprite->initOptions();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Aircraft::addEvents()
{
    auto physicsBody = PhysicsBody::createCircle(this->getContentSize()/2,
        PhysicsMaterial(0.5f, 0.2f, 0.0f)
    );
    physicsBody->setContactTestBitmask(true);
    physicsBody->setDynamic(true);
    this->addComponent(physicsBody);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Aircraft::onContactBegin, this);

    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(Aircraft::onKeyPressed, this);
    keylistener->onKeyReleased = CC_CALLBACK_2(Aircraft::onKeyReleased, this);
    auto aclistener = EventListenerAcceleration::create(CC_CALLBACK_2(Aircraft::onAcceleration, this));
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keylistener, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(aclistener, this);
    this->scheduleUpdate();
}

void Aircraft::update(float delta)
{
    float angle = fmod(this->getRotation(), 360);
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW)){
        this->move();
    }

    if(isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW)){
        this->setRotation(angle-3.5f);

    }
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)){
        this->setRotation(angle+3.5f);
    }

    if(isKeyPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW)){
    }

    for(auto laser: lasers)
    {
        if(!getBox().containsPoint(laser->getPosition()))
        {
            removeLaser(laser);
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
    float yOff = 1;
    if((nodeAngle>90 && nodeAngle<180) || (nodeAngle<-90 && nodeAngle>-270)){
        yOff = -1;
    }
    float deltax = yOff * tan(nodeAngleRadius);
    float deltay = yOff;
    float dx = nodeLocation.x + deltax;
    float dy = nodeLocation.y + deltay;
    if(nodeAngle>180 && nodeAngle<270){
        dx = nodeLocation.x - deltax;
        dy = nodeLocation.y - deltay;
    }else if(nodeAngle==90 || nodeAngle==-270){
        dx = nodeLocation.x + 1;
        dy = nodeLocation.y;
    }else if(nodeAngle==-90 || nodeAngle==270){
        dx = nodeLocation.x - 1;
        dy = nodeLocation.y;
    }
    Vec2 destination = Vec2(dx, dy);
    auto move = MoveTo::create(0.1, destination);
    this->runAction(move);
}

void Aircraft::shotLaser()
{   
    if(lasers.size()<=2){    
        Arm* laser = Arm::create();
        laser->addToAircraft(this);
        laser->shotLaser();
    }
}

void Aircraft::addLaser(Arm* laser)
{
    lasers.push_back(laser);
}

void Aircraft::removeLaser(Arm* laser)
{   
   if(findLaser(laser)){    
        lasers.erase(std::remove(lasers.begin(), lasers.end(), laser), lasers.end());
        laser->removeFromParent();
        laser->release();
   }
}

bool Aircraft::findLaser(Arm* laser)
{
    if ( std::find(lasers.begin(), lasers.end(), laser) != lasers.end() ){
        return true;
    }else{
       return false;
    }
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
        else if(acc->z > 0.08f){
            this->shotLaser();
        }
        if(acc->x <-0.08f){
            this->setRotation(angle-3.5f);
        }else if(acc->x > 0.08f){
            this->setRotation(angle+3.5f);
        }
    }
}

Meteor* Aircraft::shotCollision(std::vector<Meteor*> meteors)
{
    for(Arm* laser: lasers){
        for(Meteor* meteor: meteors){
            Rect box = meteor->getBoundingBox();
            if(box.containsPoint(laser->getPosition())){
                laser->burstLaser();
                auto delay = DelayTime::create(0.01f);
                auto autoRemove = CallFunc::create([=](){
                    removeLaser(laser);
                });
                auto seq = Sequence::create(delay, autoRemove, nullptr);
                this->runAction(seq);
                return meteor;
            }
        }
    }
    return nullptr;
}

bool Aircraft::onContactBegin(PhysicsContact& contact)
{
    log("COLID");
    return true;
}
