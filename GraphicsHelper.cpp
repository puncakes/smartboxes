
#include "GraphicsHelper.h"
#include <SOIL.h>

std::map<const char*, GLuint> GraphicsHelper::mTextureCache;

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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
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
