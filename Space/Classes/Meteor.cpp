#include "Meteor.h"

USING_NS_CC;

Meteor::Meteor()
{

}

Meteor* Meteor::create()
{   
    Meteor* pSprite = new Meteor();
    auto pinfo = AutoPolygon::generatePolygon("res/meteorSmall.png");
    if (pSprite->initWithPolygon(pinfo))
    {
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}
