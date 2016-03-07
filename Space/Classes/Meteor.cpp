#include <stdlib.h>
#include "Meteor.h"
// #include "Meteors.h"

USING_NS_CC;

Meteor::Meteor()
{
    visibleSize = Director::getInstance()->getWinSize();

}

Meteor* Meteor::create()
{
    Meteor* pSprite = new Meteor();
    auto pinfo = AutoPolygon::generatePolygon("res/meteorSmall.png");
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

void Meteor::initOptions()
{
    int xUp = rand() % (int) visibleSize.width;
    Vec2 loc = Vec2((float) xUp, visibleSize.height);
    this->setPosition(loc);
}

void Meteor::moveDown()
{

    int xDown = rand() % (int) visibleSize.width;
    float heigth = getHeigth();
    heigth = -heigth;
    Vec2 dest = Vec2((float) xDown, heigth);
    int t = rand() % 4;
    auto delay = DelayTime::create(0.25f + (float) t);
    auto toDown = MoveTo::create(5.0f, dest);
    auto seq = Sequence::create(delay, toDown, nullptr);
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
