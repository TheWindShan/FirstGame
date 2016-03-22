#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Aircraft;
class Controls
{
public:
    Controls(Aircraft *aircraft);
    void addControls();
    void addArm(std::string resource, cocos2d::Vec2 position);
private:
    cocos2d::Size visibleSize;
    cocos2d::ui::Button* left;
    cocos2d::ui::Button* up;
    cocos2d::ui::Button* rith;
    cocos2d::ui::Button* laser;
    cocos2d::Scene* scene;
    Aircraft *aircraft;
};
#endif // __CONTROLS_H__
