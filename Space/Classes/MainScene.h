#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Aircraft.h"
#include "Meteor.h"
#include <vector>
#include <algorithm>


class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    void setPhysicsWorld(cocos2d::PhysicsWorld* world) {
        World = world;
        World->setGravity(cocos2d::Vect(0, 0));
    }
    virtual bool init();
    virtual void update(float delta) override;
    cocos2d::PhysicsWorld* World;
    CREATE_FUNC(MainScene);
private:
    cocos2d::Rect box;
    Aircraft* sprite;
    std::vector<Meteor*> meteors;
    cocos2d::Size visibleSize;
    void launchMeteors(unsigned int num);
    void removeMeteor(Meteor* meteor);
    bool findMeteor(Meteor* meteor);
    void addMeteor(Meteor* meteor);

};
#endif // __MAIN_SCENE_H__
