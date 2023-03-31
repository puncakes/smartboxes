//
// Created by dev on 3/31/23.
//

#ifndef EDITOR_CAMERA_H
#define EDITOR_CAMERA_H

#include <glm/glm.hpp>

//contains common camera properties (position, zoom, front vector, up vector, etc.)
class GameCamera {
public:
    GameCamera();

    //getters
    const glm::vec3& getPosition() const;
    const glm::vec3& getFront() const;
    const glm::vec3& getUp() const;
    const glm::vec3& getRight() const;
    const glm::vec3& getWorldUp() const;
    const float& getZoom() const;
    const float& getPitch() const;
    const float& getYaw() const;
    const float& getSpeed() const;
    const float& getSensitivity() const;

    //setters
    void setPosition(const glm::vec3& position);
    void setFront(const glm::vec3& front);
    void setUp(const glm::vec3& up);
    void setRight(const glm::vec3& right);
    void setWorldUp(const glm::vec3& worldUp);
    void setZoom(const float& zoom);
    void setPitch(const float& pitch);
    void setYaw(const float& yaw);
    void setSpeed(const float& speed);
    void setSensitivity(const float& sensitivity);

    //updates camera vectors
    void updateCameraVectors();

    //returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 getViewMatrix();

};


#endif //EDITOR_CAMERA_H
