#ifndef __METEOR_H__
#define __METEOR_H__

#include "cocos2d.h"
#include <vector>


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
private:
    void addEvents();
    void initOptions();
    bool animed = false;
    cocos2d::Size visibleSize;
    std::vector<std::string> resources;
};

#endif // __METEOR_H__
