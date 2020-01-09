#ifndef EDITOR_ROBOT_H
#define EDITOR_ROBOT_H

#include <vector>
#include <Box2D/Dynamics/b2Body.h>
#include "RobotParts/IRobotPart.h"

class Robot {
public:
    Robot();
    ~Robot();

    void Draw();

    void addRobotPart(std::unique_ptr<IRobotPart> part);

private:
    std::vector<std::unique_ptr<IRobotPart>> mRobotParts;

};


#endif //EDITOR_ROBOT_H
