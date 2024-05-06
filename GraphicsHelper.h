//
// Created by Radl, Adam J. on 1/7/20.
//

#ifndef EDITOR_GRAPHICSHELPER_H
#define EDITOR_GRAPHICSHELPER_H

#include "Shader.h"
#include <GLFW/glfw3.h>
#include <map>

class GraphicsHelper {
public:
    static GLuint LoadTexture2D(const char* texturePath);
    static Shader LoadShader(const char* vertexPath, const char* fragmentPath);

private:
    static std::map<const char*, GLuint> mTextureCache;
    static std::map<const char*, Shader> mShaderCache;

};


#endif //EDITOR_GRAPHICSHELPER_H
