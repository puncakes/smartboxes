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
    GameCamera(float width, float height);

    void SetPosition(const glm::vec3& position);
    void SetUp(const glm::vec3& up);
    void SetZoom(float zoom);

    const glm::vec3& GetPosition() const;
    const glm::vec3& GetUp() const;
    float GetZoom() const;

    //get projection matrix
    glm::mat4 GetProjectionMatrix() const;
    glm::mat4 GetViewMatrix() const;

private:
    glm::vec3 mPosition;
    glm::vec3 mTarget;
    glm::vec3 mUp;
    glm::mat4 mOrtho;
    float mZoom;
    float mWidth;
    float mHeight;

};


#endif //EDITOR_CAMERA_H
