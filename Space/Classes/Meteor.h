#ifndef __METEOR_H__
#define __METEOR_H__

#include "cocos2d.h"

class Meteor : public cocos2d::Sprite
{
public:
    Meteor();
    static Meteor* create();
    virtual void update(float delta) override;
    void moveDown();
    float getHeigth();
    void makeRotation();
private:
    void addEvents();
    void initOptions();
    cocos2d::Size visibleSize;
};

#endif // __METEOR_H__
