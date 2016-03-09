#ifndef __METEOR_H__
#define __METEOR_H__

#include "cocos2d.h"
#include <vector>
#include <tuple>


class Meteor : public cocos2d::Sprite
{
public:
    Meteor();
    static Meteor* create();
    virtual void update(float delta) override;
    void toMove();
    float getHeigth();
    void makeRotation();
    void setAnimed(bool value);
    bool getAnimed();
    void makeDirection();

private:
    void addEvents();
    void initOptions();
    bool animed = false;
    cocos2d::Size visibleSize;
};


class Direction
{
public:
    Direction(Meteor* meteor);
    void make();
    float xMax();
    float yMin();    
    float xMin();
    float yMax();
    float xRand();
    float yRand();


private:
    cocos2d::Vec2 origin;
    cocos2d::Vec2 last;
    std::tuple<cocos2d::Vec2, cocos2d::Vec2> locations;
    Meteor *meteor;
};

#endif // __METEOR_H__
