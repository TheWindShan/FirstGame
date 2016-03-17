#ifndef __AIRCRAFT_H__
#define __AIRCRAFT_H__

#include "cocos2d.h"
#include "Aircraft.h"
#include <vector>

class Arm;
class Meteor;
class Aircraft : public cocos2d::Sprite
{
public:
    Aircraft();
    static Aircraft* create();
    virtual void update(float delta) override;
    void makeMove();
    void shotLaser();
    void addLaser(Arm* laser);
    void removeLaser(Arm* laser);
    bool findLaser(Arm* laser);
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    void makeRotation(char side);
    float getAngle();
    Meteor* shotCollision(std::vector<Meteor*> meteors);
    cocos2d::Rect getBox();
    Aircraft* pSprite;
    cocos2d::Size visibleSize;
private:
    std::vector<cocos2d::EventKeyboard::KeyCode> keys;
    std::vector<Arm*> lasers;
    void initOptions();
    void addEvents();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode KeyCode);
    void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
};
#endif // __AIRCRAFT_H__
