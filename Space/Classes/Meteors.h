#ifndef __METEORS_H__
#define __METEORS_H__

#include <vector>
#include "Meteor.h"


class Meteors
{
public:
    Meteors();
    static Meteors* create();
    static const std::vector<Meteor> meteors;

private:

};

#endif // __METEORS_H__
