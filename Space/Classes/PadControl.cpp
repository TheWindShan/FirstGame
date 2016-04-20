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
        float r = this->getContentSize().height/2;
        float r2 = control->getContentSize().height/2;
        Vec2 middle = this->getPosition();
        Vec2 middle2 = this->convertToWorldSpace(control->getPosition());
        float disCenter = middle.distance(middle2);
        float diffRadius = r - r2;
        Vec2 p2 = touch->getLocation();
        float disDest = middle.distance(p2);
        Vec2 p = target->convertToNodeSpace(touch->getLocation());
        if(disDest<diffRadius){
            return true;
        }else{
            return false;
        }
    };
    listener1->onTouchMoved = [&](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 p = target->convertToNodeSpace(touch->getLocation());
        Vec2 p2 = touch->getLocation();
        Vec2 middle = this->getPosition();
        Vec2 middle2 = this->convertToWorldSpace(control->getPosition());
        Vec2 dest = control->getPosition() + touch->getDelta();
        auto diff = p2 - middle;
        float angle = CC_RADIANS_TO_DEGREES(-diff.getAngle());
        float radius = -diff.getAngle();
        float r = target->getContentSize().height/2;
        float r2 = control->getContentSize().height/2;
        float disDest = middle.distance(p2);
        float disCenter = middle.distance(middle2);
        float diffRadius = r - r2;

        if(disDest<diffRadius){
            control->setPosition(dest);
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
        Vec2(origin.x + this->getContentSize().width, origin.y + this->getContentSize().height)
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
        Vec2(size.width/2, size.height/2)
    );
    this->addChild(control);
}

float PadControl::getAngle()
{
    return fmod(this->getRotation(), 360);
}