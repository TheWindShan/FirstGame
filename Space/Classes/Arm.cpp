#include "Arm.h"
#include "Aircraft.h"

USING_NS_CC;

Arm::Arm()
{

}

Arm* Arm::create()
{
    Arm* pSprite = new Arm();
    if (pSprite->initWithFile("res/laserGreen.png"))
    {
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}
void Arm::addEvents()
{

}

void Arm::update(float delta)
{

}

float Arm::getHeigth()
{
    return this->getBoundingBox().size.height;
}

void Arm::shotLaser()
{
    Vec2 location = aircraft->getPosition();
    float angle = fmod(aircraft->getRotation(), 360);
    float angleRadius = angle * (M_PI/180);
    float yOff = aircraft->visibleSize.height - location.y;
    float deltax = yOff * tan(angleRadius);
    float dx = location.x + deltax;
    float dy = aircraft->visibleSize.height + this->getHeigth();
    if((angle > 90 && angle < 270) || (angle < -90 && angle > -270)){
        yOff = location.y;
        deltax = yOff * tan((2*M_PI)-(angleRadius));
        dx = location.x + deltax;
        dy = -1*( this->getHeigth());
    }else if(angle == 90 || angle == -270  ){
        dx = aircraft->visibleSize.width + this->getHeigth();
        dy = location.y;
    }else if(angle == -90 || angle == +270){
        dx = -aircraft->visibleSize.width;
        dy = location.y;
    }
    Vec2 destination = Vec2(dx, dy);
    auto actionLaser = MoveTo::create(0.5f, destination);
    aircraft->addLaser(this);
    this->setPosition(location);
    this->setRotation(angle);
    aircraft->getParent()->addChild(this, -1);
    this->runAction(actionLaser);
}

void Arm::addToAircraft(Aircraft *aircraft)
{
    this->aircraft = aircraft;
}