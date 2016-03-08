#ifndef __METEOR_H__
#define __METEOR_H__

#include "cocos2d.h"
#include <vector>

struct product {
  int weight;
  double price;
};

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
    std::vector<cocos2d::Vec2> origin;
    std::vector<cocos2d::Vec2> last;
};

#endif // __METEOR_H__
