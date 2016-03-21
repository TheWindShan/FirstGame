#include "Arm.h"
#include "Aircraft.h"

USING_NS_CC;

Arm::Arm()
{

}

Arm* Arm::create()
{
    Arm* pSprite = new Arm();
    if (pSprite->initWithFile("res/Lasers/laserRed01.png"))
    {
        pSprite->physics();
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

void Arm::physics()
{
    auto physicsBody = PhysicsBody::createBox(this->getContentSize(),
    PhysicsMaterial(1.0f, 0.0f, 0.0f)
    );
    physicsBody->setDynamic(true);
    this->addComponent(physicsBody);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Arm::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

float Arm::getHeigth()
{
    return this->getBoundingBox().size.height;
}

void Arm::shotLaser()
{
    Vec2 location = aircraft->getPosition();
    float angle = aircraft->getAngle();
    float angleRadius = CC_DEGREES_TO_RADIANS(angle);
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
    // location.y += this->getContentSize().height;
    this->setRotation(angle);
    location = aircraft->getPosition();
    this->setPosition(location);
    aircraft->addLaser(this);
    aircraft->getParent()->addChild(this, -1);
    float distance = location.distance(destination);
    float time = distance/2000.0f;
    auto actionLaser = MoveTo::create(time, destination);
    this->runAction(actionLaser);
}

void Arm::addToAircraft(Aircraft *aircraft)
{
    this->aircraft = aircraft;
}

void Arm::burstLaser()
{
    this->setTexture("res/Lasers/laserRed09.png");
}

bool Arm::onContactBegin(PhysicsContact& contact)
{
    return true;
}
