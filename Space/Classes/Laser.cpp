#include "Laser.h"

USING_NS_CC;

Laser::Laser()
{

}

Laser* Laser::create()
{
    Laser* pSprite = new Laser();
    if (pSprite->initWithFile("res/laserGreen.png"))
    {
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void Laser::update(float delta)
{

}
