//
// Created by dev on 3/31/23.
//

#include "camera.h"

GameCamera::GameCamera() {
    mPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    mTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    mUp = glm::vec3(0.0f, 1.0f, 0.0f);
    mZoom = 1.0f;
}

glm::mat4 GameCamera::GetViewMatrix() const {
    return glm::lookAt(mPosition, mTarget, mUp);
}

glm::mat4 GameCamera::GetProjectionMatrix(float width, float height) const {
    return glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
}

//setters
void GameCamera::SetPosition(const glm::vec3& position) {
    mPosition = position;
}

void GameCamera::SetTarget(const glm::vec3& target) {
    mTarget = target;
}

void GameCamera::SetUp(const glm::vec3& up) {
    mUp = up;
}

void GameCamera::SetZoom(float zoom) {
    mZoom = zoom;
}

//getters
const glm::vec3& GameCamera::GetPosition() const {
    return mPosition;
}

const glm::vec3& GameCamera::GetTarget() const {
    return mTarget;
}

const glm::vec3 GameCamera::GetDirection() const {
    return glm::normalize(mPosition - mTarget);
}

const glm::vec3& GameCamera::GetRight() const {
    //cross product of direction and up
    return glm::normalize(glm::cross(mUp, GetDirection()))
}

const glm::vec3& GameCamera::GetUp() const {
    return mUp;
}

float GameCamera::GetZoom() const {
    return mZoom;
}
