#include "Robot.h"

Robot::Robot() {

}

Robot::~Robot() {

}

void Robot::addRobotPart(std::unique_ptr<Entity> part) {
    mRobotParts.push_back(std::move(part));
}
