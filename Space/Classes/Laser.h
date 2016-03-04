#ifndef __LASER_H__
#define __LASER_H__

#include "cocos2d.h"

class Laser : public cocos2d::Sprite
{
public:
    Laser();
    static Laser* create();
    virtual void update(float delta) override;
    float getHeigth();
private:
    void addEvents();
};

#endif // __LASER_H__
