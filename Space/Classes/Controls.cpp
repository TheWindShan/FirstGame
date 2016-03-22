#include "Controls.h"
#include "Aircraft.h"

USING_NS_CC;

Controls::Controls(Aircraft *aircraft)
{
    this->aircraft = aircraft;
    visibleSize = Director::getInstance()->getVisibleSize();
    addControls();
    Vec2 btnVec2 = Vec2(visibleSize.width - 100, visibleSize.height / 6.5f);
    addArm("res/Controls/shadedLight49.png", btnVec2);
    log("INITED...");
}

void Controls::addArm(std::string resource, Vec2 position)
{
    ui::Button* btn = ui::Button::create(resource);
    btn->setTouchEnabled(true);
    btn->setOpacity(150);
    btn->setPosition(position);   
    btn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                aircraft->shotLaser();
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
    });   
    aircraft->getParent()->addChild(btn, 10);
}

void Controls::addControls()
{
    ui::Button* left = ui::Button::create("res/Controls/shadedLight05.png");
    left->setTouchEnabled(true);
    left->setOpacity(150);
    left->setPosition(Point(visibleSize.width / 7.9f, visibleSize.height / 6.5f));   
    left->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                aircraft->makeRotation('-');
                break;
            case ui::Widget::TouchEventType::ENDED:
                aircraft->makeRotation('-');
                break;
            default:
                break;
        }
    });   
    aircraft->getParent()->addChild(left, 10);

    ui::Button* right = ui::Button::create("res/Controls/shadedLight06.png");
    right->setTouchEnabled(true);
    right->setOpacity(150);
    right->setPosition(Point(visibleSize.width / 5.0f, visibleSize.height / 6.5f));
    right->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                aircraft->makeRotation('+');
                break;
            case ui::Widget::TouchEventType::ENDED:
                aircraft->makeRotation('+');
                break;
            default:
                break;
        }
    });     
    aircraft->getParent()->addChild(right, 10);

    ui::Button* up = ui::Button::create("res/Controls/shadedLight03.png");
    up->setTouchEnabled(true);
    up->setOpacity(150);
    up->setPosition(Point(visibleSize.width /6.1f, visibleSize.height / 4.8f));
    up->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                aircraft->makeMove();
                break;
            case ui::Widget::TouchEventType::ENDED:
                aircraft->makeMove();
                break;
            default:
                break;
        }
    });        
    aircraft->getParent()->addChild(up, 10);   

    ui::Button* down = ui::Button::create("res/Controls/shadedLight10.png");
    down->setTouchEnabled(true);
    down->setOpacity(150);
    down->setPosition(Point(visibleSize.width /6.1f, visibleSize.height / 9.8f));
    down->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
    });        
    aircraft->getParent()->addChild(down, 10);
}