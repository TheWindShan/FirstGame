#include "Control.h"
USING_NS_CC;

Control::Control()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
}

Control* Control::create()
{
    Control* pSprite = new Control();
    auto pinfo = AutoPolygon::generatePolygon("res/Controls/flatLight49.png");
    if (pSprite->initWithFile("res/Controls/flatLight49.png"))
    {
        pSprite->addEvents();
        // pSprite->addPhysics();
        pSprite->initOptions();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Control::addEvents()
{
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    listener1->onTouchBegan = [&](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        auto bounds = target->getParent()->getBoundingBox();
        if (bounds.containsPoint(touch->getLocation()))
        {
            return true;
        }
        return false;
    };

    listener1->onTouchMoved = [&](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setPosition(target->getPosition() + touch->getDelta());
    };

    listener1->onTouchEnded = [this](Touch* touch, Event* event){

    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1,this);
    this->scheduleUpdate();
}

void Control::initOptions()
{
    this->setOpacity(150);
}

void Control::addPhysics()
{
    auto physicsBody = PhysicsBody::createBox(this->getContentSize(),
        PHYSICSBODY_MATERIAL_DEFAULT
    );
    physicsBody->setDynamic(false);
    this->addComponent(physicsBody);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Control::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

Rect Control::getBox()
{
    return Director::getInstance()->getRunningScene()->getBoundingBox();
}

bool Control::onContactBegin(PhysicsContact& contact)
{
    return true;
}

float Control::getAngle()
{
    return fmod(this->getRotation(), 360);
}
