#ifndef __METEOR_H__
#define __METEOR_H__

#include "cocos2d.h"

class Meteor : public cocos2d::Sprite
{
public:
    Meteor();
    static Meteor* create();
};

#endif // __METEOR_H__
