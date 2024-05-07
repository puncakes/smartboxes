//
// Created by Adam on 3/31/2023.
//

#ifndef EDITOR_SPRITE_H
#define EDITOR_SPRITE_H

#include <glm/glm.hpp>
#include "Shader.h"

class Sprite {
public:
    explicit Sprite(Shader &shader);
    ~Sprite();

    void DrawSprite(unsigned int textureID, glm::vec2 position,
                    glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
                    glm::vec3 color = glm::vec3(1.0f));
private:
    Shader       shader;
    unsigned int quadVAO;

    void initRenderData();
};


#endif //EDITOR_SPRITE_H
