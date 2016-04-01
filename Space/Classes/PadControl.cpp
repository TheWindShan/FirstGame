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
        pSprite->addPhysics();
        pSprite->initOptions();
        pSprite->initControl();
        pSprite->addEvents();

        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void PadControl::addPhysics()
{
    auto physicsBody = PhysicsBody::createCircle(this->getContentSize().width/2);
    physicsBody->setDynamic(false);
    this->addComponent(physicsBody);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(PadControl::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool PadControl::onContactBegin(PhysicsContact& contact)
{
    return false;
}

void PadControl::addEvents()
{
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    listener1->onTouchBegan = [&](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point p = target->convertToNodeSpace(touch->getLocation());
        Rect rect = control->getBoundingBox();
        if (rect.containsPoint(p))
        {
            return true;
        }
        return false;
    };
    listener1->onTouchMoved = [&](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point p = touch->getLocation();
        if (target->getBoundingBox().containsPoint(p))
        {
            control->setPosition(control->getPosition() + touch->getDelta());
        }
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1,this);
    this->scheduleUpdate();
}

void PadControl::update(float delta)
{

}

void PadControl::initOptions()
{
    this->getPhysicsBody()->setCategoryBitmask(10);
    this->getPhysicsBody()->setCollisionBitmask(0);
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
