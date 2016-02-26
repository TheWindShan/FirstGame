#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Aircraft.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual void update(float delta) override;
    CREATE_FUNC(MainScene);

private:
    Aircraft *sprite;
    cocos2d::Size visibleSize;
};

#endif // __MAIN_SCENE_H__
