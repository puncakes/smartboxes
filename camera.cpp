//
// Created by dev on 3/31/23.
//

#include "camera.h"

GameCamera::GameCamera(float width, float height) {
    mOrtho = glm::ortho(0.0f, width, height, 0.0f, 0.1f, 100.0f);
    mPosition = glm::vec3(0.0f, 0.0f, 1000.0f);
    mTarget = glm::vec3(0.0f, 0.0f, -1.0f);
    mUp = glm::vec3(0.0f, 1.0f, 0.0f);
    mZoom = 1.0f;
    mWidth = width;
    mHeight = height;
}

glm::mat4 GameCamera::GetViewMatrix() const {
    return glm::mat4 (1.0f);
    return glm::lookAt(mPosition, mPosition + mTarget, mUp);
}

glm::mat4 GameCamera::GetProjectionMatrix() const {
    return mOrtho;
    return glm::perspective(glm::radians(mZoom), mWidth / mHeight, 0.1f, 1000.0f);
}

//setters
void GameCamera::SetPosition(const glm::vec3& position) {
    mPosition = position;
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

const glm::vec3& GameCamera::GetUp() const {
    return mUp;
}

float GameCamera::GetZoom() const {
    return mZoom;
}
