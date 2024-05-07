#ifndef EDITOR_ROBOT_H
#define EDITOR_ROBOT_H

#include <vector>
#include <Box2D/Dynamics/b2Body.h>
#include "RobotParts/Entity.h"

class Robot {
public:
    Robot();
    ~Robot();

    void Draw();

    void addRobotPart(std::unique_ptr<Entity> part);

private:
    std::vector<std::unique_ptr<Entity>> mRobotParts;

};


#endif //EDITOR_ROBOT_H
