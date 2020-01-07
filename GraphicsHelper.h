//
// Created by Radl, Adam J. on 1/7/20.
//

#ifndef EDITOR_GRAPHICSHELPER_H
#define EDITOR_GRAPHICSHELPER_H


#include <GLFW/glfw3.h>
#include <map>

class GraphicsHelper {
public:
    static GLuint LoadTexture2D(const char* texturePath);

private:
    static std::map<const char*, GLuint> mTextureCache;

};


#endif //EDITOR_GRAPHICSHELPER_H
