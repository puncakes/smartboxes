
#include "GraphicsHelper.h"
#include <SOIL.h>
#include <iostream>
#include <sstream>
#include <fstream>

#define GL_CLAMP_TO_EDGE 0x812F

std::map<const char*, GLuint> GraphicsHelper::mTextureCache;
std::map<const char*, Shader> GraphicsHelper::mShaderCache;

GLuint GraphicsHelper::LoadTexture2D(const char *texturePath) {
    auto search = mTextureCache.find(texturePath);
    if(search != mTextureCache.end()) {
        //return the textureID in the cache
        return search->second;
    }
    // Load and create a texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // Load image, create texture
    int width, height;
    unsigned char* image = SOIL_load_image(texturePath, &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

    //store the textureID in the texture cache map for later access
    mTextureCache.insert({texturePath, textureID});

    // Return the ID of the texture we just created
    return textureID;
}

Shader GraphicsHelper::LoadShader(const char *vertexPath, const char *fragmentPath) {

    auto search = mShaderCache.find(vertexPath);
    if(search != mShaderCache.end()) {
        //return the shader in the cache
        return search->second;
    }

    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {
        // open files
        std::ifstream vertexShaderFile(vertexPath);
        std::ifstream fragmentShaderFile(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        // close file handlers
        vertexShaderFile.close();
        fragmentShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

    }
    catch (std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    const char *gShaderCode = geometryCode.c_str();
    // 2. now create shader object from source code
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode, nullptr);

    //store the shader in the shader cache map for later access
    mShaderCache.insert({vertexPath, shader});
    return shader;
}
