#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Aircraft.h"
#include "Meteor.h"
#include <vector>


class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual void update(float delta) override;
    CREATE_FUNC(MainScene);


private:
    cocos2d::Rect box;
    Aircraft * sprite;
    Meteor * meteor;
    std::vector<Meteor*> meteors;
    cocos2d::Size visibleSize;
    void launchMeteors(int num);
};

#endif // __MAIN_SCENE_H__
