//
// Created by dev on 3/31/23.
//

#ifndef EDITOR_CAMERA_H
#define EDITOR_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//contains common camera properties (position, target, right, up, zoom)
class GameCamera {
public:
    GameCamera();

    void SetPosition(const glm::vec3& position);
    void SetTarget(const glm::vec3& target);
    void SetUp(const glm::vec3& up);
    void SetZoom(float zoom);

    const glm::vec3& GetPosition() const;
    const glm::vec3& GetTarget() const;
    const glm::vec3 GetDirection() const;
    const glm::vec3& GetRight() const;
    const glm::vec3& GetUp() const;
    float GetZoom() const;

    glm::mat4 GetViewMatrix() const;

    //get projection matrix
    glm::mat4 GetProjectionMatrix(float width, float height) const;

private:
    glm::vec3 mPosition;
    glm::vec3 mTarget;
    glm::vec3 mUp;
    float mZoom;

};


#endif //EDITOR_CAMERA_H
