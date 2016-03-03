#include "Laser.h"

USING_NS_CC;

Laser::Laser()
{

}

Laser* Laser::create()
{
    Laser* pSprite = new Laser();
    auto pinfo = AutoPolygon::generatePolygon("res/laserGreen.png");
    if (pSprite->initWithPolygon(pinfo))
    {
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Laser::update(float delta)
{

}
