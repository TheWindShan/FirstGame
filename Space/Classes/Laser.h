#ifndef __LASER_H__
#define __LASER_H__

#include "cocos2d.h"

class Laser : public cocos2d::Sprite
{
public:
    Laser();
    static Laser* create();
};

#endif // __LASER_H__
