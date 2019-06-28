#ifndef SHAPE_H
#define SHAPE_H

#include <Box2D/Box2D.h>

class Shape
{
public:
    virtual void draw() = 0;

protected:
    b2Body* mBody;

};

#endif // SHAPE_H
