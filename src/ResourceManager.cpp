//
// Created by TIANTIAN on 2023/3/18.
//
#define STB_IMAGE_IMPLEMENTATION
#include "ResourceManager.h"
#include "stb_image.h"

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager resourceManager;
    return resourceManager;
}

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {}

std::shared_ptr<Shader> ResourceManager::addShader(ShaderType type, const char* vsPath, const char* fsPath,
                                const char* gsPath) {
    auto shader = loadShaderFromFile(vsPath, fsPath, gsPath);
    shaders[type] = shader;
    return shader;
}

std::shared_ptr<Shader> ResourceManager::getShader(ShaderType type) {
    if (shaders.find(type) != shaders.end()) {
        return shaders[type];
    }
    return nullptr;
}

std::shared_ptr<Texture2D> ResourceManager::addTexture(TextureType type, const char* filePath, bool alpha) {
    auto texture = loadTextureFromFile(filePath, alpha);
    textures[type] = texture;
    return texture;
}

std::shared_ptr<Texture2D> ResourceManager::getTexture(TextureType type) {
    return textures[type];
}

std::shared_ptr<Shader> ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile) {
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try {
        // open files
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
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
        // if geometry shader path is present, also load a geometry shader
        if (gShaderFile != nullptr)
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::exception e) {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    const char *gShaderCode = geometryCode.c_str();
    // 2. now create shader object from source code
    auto shader = std::make_shared<Shader>();
    shader->Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
    return shader;
}

std::shared_ptr<Texture2D> ResourceManager::loadTextureFromFile(const char *file, bool alpha) {
    // create texture object
    auto texture = std::make_shared<Texture2D>();
    if (alpha) {
        texture->Internal_Format = GL_RGBA;
        texture->Image_Format = GL_RGBA;
    }
    // load image
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    // now generate texture
    texture->Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);
    return texture;
}