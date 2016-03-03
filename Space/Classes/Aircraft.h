#ifndef __AIRCRAFT_H__
#define __AIRCRAFT_H__

#include "cocos2d.h"
#include "Laser.h"
#include <vector>

class Aircraft : public cocos2d::Sprite
{
public:
    Aircraft();
    static Aircraft* create();
    virtual void update(float delta) override;
    void addEvents();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode KeyCode);
    void move();
    void shotLaser();
    void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
    Laser* laser;
    std::vector<cocos2d::EventKeyboard::KeyCode> keys;
    cocos2d::Size visibleSize;

};

#endif // __AIRCRAFT_H__
