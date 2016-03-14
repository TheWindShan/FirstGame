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
    scheduleUpdate();
}

void Meteor::initOptions()
{
    setPosition(selectPosition());
}

void Meteor::toMove()
{
    int timeDelay = rand() % 4;
    auto delay = DelayTime::create(0.25f + (float) timeDelay);
    auto toMove = MoveTo::create(5.0f, selectPosition());
    auto changeTag = CallFunc::create([this](){
        setAnimed(true);
    });
    auto seq = Sequence::create(delay, toMove, changeTag, nullptr);
    this->runAction(seq);
}

void Meteor::update(float delta)
{
    makeRotation();
}

float Meteor::getHeigth()
{
    return this->getTextureRect().size.height;
}

void Meteor::makeRotation()
{
    float angle = fmod(this->getRotation(), 360);
    this->setRotation(++angle);
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
    resMeteors.push_back("res/meteorSmall.png");
    resMeteors.push_back("res/meteorBig.png");
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