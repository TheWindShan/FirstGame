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
    void move();
    void shotLaser();
    Laser* laser;
private:
    cocos2d::Size visibleSize;
    std::vector<cocos2d::EventKeyboard::KeyCode> keys;
    void initOptions();
    void addEvents();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode KeyCode);
    void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);

};

#endif // __AIRCRAFT_H__
