//
// Created by Adam on 5/7/2024.
//

#ifndef SMART_BOXES_ENTITYMANAGER_H
#define SMART_BOXES_ENTITYMANAGER_H


#include <vector>
#include "RobotParts/Entity.h"
#include "camera.h"

class EntityManager {
public:
    EntityManager();
    static void Draw(GameCamera *pCamera);
    static void Update();
    static void AddEntity(Entity* entity);
    static void RemoveEntity(Entity* entity);
private:
    static std::vector<Entity*> mEntities;
};


#endif //SMART_BOXES_ENTITYMANAGER_H
