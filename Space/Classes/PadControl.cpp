#include "PadControl.h"
#include "Aircraft.h"
#include "Control.h"

USING_NS_CC;

PadControl::PadControl()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    control = Control::create();
}

PadControl* PadControl::create(Aircraft* aircraft)
{
    PadControl* pSprite = new PadControl();
    auto pinfo = AutoPolygon::generatePolygon("res/Controls/flatLight05.png");
    if (pSprite->initWithPolygon(pinfo))
    {
        pSprite->addEvents();
        pSprite->initOptions();
        pSprite->initControl();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void PadControl::addEvents()
{
    this->scheduleUpdate();
}

void PadControl::update(float delta)
{

}

void PadControl::initOptions()
{
    this->setPosition(
        Point(origin.x + this->getContentSize().width, origin.y + this->getContentSize().height)
    );
    this->setOpacity(150);
}

Rect PadControl::getBox()
{
    return Director::getInstance()->getRunningScene()->getBoundingBox();
}

void PadControl::initControl()
{
    size = this->getContentSize();
    control->setPosition(
        size.width/2, size.height/2
    );
    this->addChild(control);
}

float PadControl::getAngle()
{
    return fmod(this->getRotation(), 360);
}
