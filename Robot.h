#ifndef EDITOR_ROBOT_H
#define EDITOR_ROBOT_H

#include <vector>
#include <Box2D/Dynamics/b2Body.h>

class Robot {
public:
    Robot();
    ~Robot();

    void Draw();

    void addRobotPart(IRobotPart);

private:
    std::vector<IRobotPart> mRobotParts;
};


#endif //EDITOR_ROBOT_H
