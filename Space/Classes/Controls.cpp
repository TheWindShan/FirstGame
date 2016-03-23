#include "Controls.h"
#include "Aircraft.h"

USING_NS_CC;

Controls::Controls(Aircraft *aircraft)
{
    this->aircraft = aircraft;
    visibleSize = Director::getInstance()->getVisibleSize();
    addControls();
    log("INITED...");
}

ui::Button* Controls::make(std::string resource, std::string name)
{
    ui::Button* btn = ui::Button::create(resource);
    btn->setTouchEnabled(true);
    btn->setName(name);
    btn->setOpacity(150);
    aircraft->getParent()->addChild(btn, 10);
    controls.push_back(&name);
    return btn;
}

void Controls::addControls()
{
    laser = make("res/Controls/shadedLight49.png", "laser");
    laser->setPosition(
        Point(visibleSize.width - laser->getContentSize().width, visibleSize.height / 6.5f)
    );
    laser->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type){
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
    

    left = make("res/Controls/shadedLight05.png", "left");
    left->setPosition(
        Point(visibleSize.width / 7.9f, visibleSize.height / 6.5f)
    );   
    left->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type){
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

    right = make("res/Controls/shadedLight06.png", "right");
    right->setPosition(
        Point(visibleSize.width / 5.0f, visibleSize.height / 6.5f)
    );
    right->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type){
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

    up = make("res/Controls/shadedLight03.png", "up");
    up->setPosition(
        Point(visibleSize.width /6.1f, visibleSize.height / 4.8f)
    );
    up->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type){
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

    down = make("res/Controls/shadedLight10.png", "down");
    down->setPosition(
        Point(visibleSize.width /6.1f, visibleSize.height / 9.8f)
    );
    down->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type){
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
}