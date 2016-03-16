#include <stdlib.h>
#include <algorithm>
#include "Meteor.h"

USING_NS_CC;

Meteor::Meteor()
{
    visibleSize = Director::getInstance()->getWinSize();
}

Meteor* Meteor::create()
{   
    Meteor* pSprite = new Meteor();
    pSprite->makeResMeteors();
    auto pinfo = AutoPolygon::generatePolygon(pSprite->selectResMeteors());
    if (pSprite->initWithPolygon(pinfo))
    { 
        pSprite->makePositions();
        pSprite->initOptions();
        pSprite->addEvents();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Meteor::addEvents()
{   
    auto physicsBody = PhysicsBody::createBox(this->getContentSize(),
        PhysicsMaterial(0.3f, 0, 0)
    );
    physicsBody->setContactTestBitmask(true);
    physicsBody->setDynamic(true);
    this->addComponent(physicsBody);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Meteor::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void Meteor::initOptions()
{
    setPosition(selectPosition());
    makeRotation();
}

void Meteor::toMove()
{
    int timeDelay = rand() % 4;
    auto delay = DelayTime::create(0.25f + (float) timeDelay);
    auto toMove = MoveTo::create(5.0f + (float) timeDelay, selectPosition());
    auto changeTag = CallFunc::create([this](){
        setAnimed(true);
    });
    auto seq = Sequence::create(delay, toMove, changeTag, nullptr);
    this->runAction(seq);
}

float Meteor::getHeigth()
{
    return this->getTextureRect().size.height;
}

void Meteor::makeRotation()
{
    float time = (float) (rand() % 4 + 2);
    float angle = (float) (rand() % 360 + 360);
    auto rotateBy = RotateBy::create(time, angle);
    // auto rotateByRev= RotateBy::create(0.5, -360);
    this->runAction(
        RepeatForever::create(rotateBy)
    );
    // float angle = fmod(this->getRotation(), 360);
    // this->setRotation(++angle);
}

void Meteor::setAnimed(bool value)
{
    animed = value;
}

bool Meteor::getAnimed()
{
    return animed;
}

void Meteor::makePositions()
{
    positions.push_back(up());
    positions.push_back(down());
    positions.push_back(right());
    positions.push_back(left());
}

void Meteor::makeResMeteors()
{
    resMeteors.push_back("res/Meteors/meteorBrown_med1.png");
    resMeteors.push_back("res/Meteors/meteorBrown_med3.png");
    resMeteors.push_back("res/Meteors/meteorBrown_small1.png");
    resMeteors.push_back("res/Meteors/meteorBrown_small2.png");
    resMeteors.push_back("res/Meteors/meteorBrown_big4.png");
    resMeteors.push_back("res/Meteors/meteorGrey_med2.png");
    resMeteors.push_back("res/Meteors/meteorGrey_small2.png");
    resMeteors.push_back("res/Meteors/meteorBrown_big1.png");
    resMeteors.push_back("res/Meteors/meteorGrey_big3.png");
}

float Meteor::xMax()
{
    float width = Director::getInstance()->getWinSize().width;
    return width + getHeigth();
}

float Meteor::xMin()
{
    float min =- getHeigth();
    return min;
}

float Meteor::yMax()
{
    float heigth = Director::getInstance()->getWinSize().height;
    return heigth + getHeigth();
}

float Meteor::yMin()
{
    float min =- getHeigth();
    return min;
}

float Meteor::xRand()
{
    return (float) (rand() % (int) xMax());
}

float Meteor::yRand()
{
    return (float) (rand() % (int) yMax());
}

Vec2 Meteor::right()
{         
    return Vec2(xMax(), yRand());
}

Vec2 Meteor::left()
{         
    return Vec2(xMin(), yRand());
}

Vec2 Meteor::up()
{         
    return Vec2(xRand(), yMax());
}

Vec2 Meteor::down()
{         
    return Vec2(xRand(), yMin());
}

std::string Meteor::selectResMeteors(void)
{  
    int raffle = rand() % resMeteors.size();
    return resMeteors[raffle];
}

Vec2 Meteor::selectPosition(void)
{
    int raffle = rand() % positions.size();
    Vec2 selected = positions[raffle];
    positions.erase(positions.begin() + raffle);
    return positions[raffle];
}

bool Meteor::onContactBegin(PhysicsContact& contact)
{
    return true;
}
