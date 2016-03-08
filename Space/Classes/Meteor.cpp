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
    std::vector<std::string> resources = {
        "res/meteorSmall.png", "res/meteorBig.png",
    };
    int raffle = rand() % resources.size();
    auto pinfo = AutoPolygon::generatePolygon(resources[raffle]);
    if (pSprite->initWithPolygon(pinfo))
    { 
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

void Meteor::makeDirection()
{
    // Vec2 fromUp = [=] ()
    // {         
    //     int xRand = rand() % (int) visibleSize.width;
    //     Vec2 loc = Vec2((float) xRand, visibleSize.height + getHeigth());
    //     return loc;
    // };

    // Vec2 fromDown = [=] ()
    // {         
    //     int xRand = rand() % (int) visibleSize.width;
    //     int minHeigth = getHeigth();
    //     minHeigth=-minHeigth;
    //     Vec2 loc = Vec2((float) xRand, minHeigth);
    //     return loc;
    // };
    // origin.push_back(fromUp());
    // origin.push_back(fromDown());
}

void Meteor::initOptions()
{
    auto fromUp = [this] ()
    {         
        int xRand = rand() % (int) visibleSize.width;
        Vec2 loc = Vec2((float) xRand, visibleSize.height + getHeigth());
        return loc;
    };

    auto fromDown = [this] ()
    {         
        int xRand = rand() % (int) visibleSize.width;
        int minHeigth = getHeigth();
        minHeigth=-minHeigth;
        Vec2 loc = Vec2((float) xRand, minHeigth);
        return loc;
    };
    this->setPosition(fromUp());
}

void Meteor::toMove()
{

    int xDown = rand() % (int) visibleSize.width;
    float heigth = getHeigth();
    heigth = -heigth;
    Vec2 dest = Vec2((float) xDown, heigth);
    int t = rand() % 4;
    auto delay = DelayTime::create(0.25f + (float) t);
    auto toMove = MoveTo::create(5.0f, dest);
    auto changeTag = CallFunc::create([=](){
        this->setAnimed(true);
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
    return this->getBoundingBox().size.height;
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

Direction::Direction(Meteor* meteor)
{
    this->meteor = meteor;
}

void Direction::make()
{
    auto fromRight = [this] ()
    {         
        int xRand = rand() % (int) xMax();
        return Vec2((float) xRand, yMax());
    };

    auto toUp = [this] ()
    {         
        int xRand = rand() % (int) xMax();
        return Vec2((float) xRand, yMax());
    };

    auto fromLeft = [this] ()
    {         
        int xRand = rand() % (int) xMax();
        return Vec2((float) xRand, yMax());
    };
    
    auto fromUp = [this] ()
    {         
        int xRand = rand() % (int) xMax();
        return Vec2((float) xRand, yMax());
    };

    auto fromDown = [this] ()
    {         
        int xRand = rand() % (int) xMax();
        return Vec2((float) xRand, yMax());
    };
}

float Direction::xMax()
{
    float width = Director::getInstance()->getWinSize().width;
    return width + meteor->getHeigth();
}

float Direction::xMin()
{
    float min =- meteor->getHeigth();
    return min;
}

float Direction::yMax()
{
    float heigth = Director::getInstance()->getWinSize().height;
    return heigth + meteor->getHeigth();
}

float Direction::yMin()
{
    float min =- meteor->getHeigth();
    return min;
}