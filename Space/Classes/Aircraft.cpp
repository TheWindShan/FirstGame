#include <algorithm>
#include <vector>
#include "Aircraft.h"
#include "Arm.h"
#include "Meteor.h"

USING_NS_CC;

Aircraft::Aircraft()
{
    visibleSize = Director::getInstance()->getVisibleSize();
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
    auto physicsBody = PhysicsBody::createBox(this->getContentSize(),
        PhysicsMaterial(0.1f, 0.1f, 0.0f)
    );
    // physicsBody->setContactTestBitmask(true);
    physicsBody->setDynamic(false);
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
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW)){
        makeMove();
    }

    if(isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW)){
        makeRotation('-');

    }
    if(isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)){
        makeRotation('+');
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
    this->getPhysicsBody()->setCategoryBitmask(0x03);
    this->getPhysicsBody()->setCollisionBitmask(0x01);
}

void Aircraft::makeMove()
{
    Vec2 location = this->getPosition();
    float angle = getAngle();
    float angleRadius = CC_DEGREES_TO_RADIANS(angle);
    float yOff = 3;
    if((angle>90 && angle<180) || (angle<-90 && angle>-270)){
        yOff =-1*(yOff);
    }
    float deltax = yOff * tan(angleRadius);
    float deltay = yOff;
    float dx = location.x + deltax;
    float dy = location.y + deltay;
    if(angle>180 && angle<270){
        dx = location.x - deltax;
        dy = location.y - deltay;
    }else if(angle==90 || angle==-270){
        dx = location.x + yOff;
        dy = location.y;
    }else if(angle==-90 || angle==270){
        dx = location.x - yOff;
        dy = location.y;
    }
    Vec2 destination = Vec2(dx, dy);
    float distance = location.distance(destination);
    float time = distance/2000.0f;
    auto move = MoveTo::create(time, destination);
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
    if(acc->y <-0.5f){
        if(acc->z <-0.2f){
            this->makeMove();
        }
        else if(acc->z > 0.05f){
            this->shotLaser();
        }
        if(acc->x <-0.05f){
            this->setRotation(getAngle()-3.5f);
        }else if(acc->x > 0.05f){
            this->setRotation(getAngle()+3.5f);
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
    // auto bodyA = contact.getShapeA()->getBody();
    // auto bodyB = contact.getShapeB()->getBody();
    return true;
}

void Aircraft::makeRotation(char side)
{   
    float angle = getAngle();
    float speed = 3.555f;
    if(side=='+'){
        this->setRotation(angle+speed);
    }
    else if(side=='-'){
        this->setRotation(angle-speed);
    }
}

float Aircraft::getAngle()
{
    return fmod(this->getRotation(), 360);
}