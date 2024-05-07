//
// Created by Adam on 5/7/2024.
//

#include <algorithm>
#include "entitymanager.h"

std::vector<Entity*> EntityManager::mEntities;

void EntityManager::AddEntity(Entity *entity) {
    entity->isManaged = true;
    mEntities.push_back(entity);
}

void EntityManager::RemoveEntity(Entity *entity) {
    entity->isManaged = false;
    mEntities.erase(std::remove(mEntities.begin(), mEntities.end(), entity), mEntities.end());
}

void EntityManager::Draw() {
    for(auto& entity : mEntities) {
        if(entity->isVisible) {
            entity->Draw();
        }
    }
}
