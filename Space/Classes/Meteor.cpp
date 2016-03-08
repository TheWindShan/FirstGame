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
        "res/Meteors/meteorBrown_med1.png", 
        "res/Meteors/meteorBrown_med3.png",
        "res/Meteors/meteorBrown_tiny1.png",
        "res/Meteors/meteorGrey_med1.png", 
        "res/Meteors/meteorGrey_med2.png", 
        "res/Meteors/meteorGrey_tiny1.png"
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
    auto fromUp = [=] ()
    {         
        int xRand = rand() % (int) visibleSize.width;
        Vec2 loc = Vec2((float) xRand, visibleSize.height + getHeigth());
        return loc;
    };

    auto fromDown = [=] ()
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