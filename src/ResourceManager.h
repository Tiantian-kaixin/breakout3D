//
// Created by TIANTIAN on 2023/3/18.
//

#ifndef BREAKOUT3D_RESOURCEMANAGER_H
#define BREAKOUT3D_RESOURCEMANAGER_H

#include <vector>
#include <unordered_map>
#include "Shader.h"
#include <memory>
#include "Texture2D.h"


enum TextureType {
    BLOCK_TEX = 0,
    BALL_TEX = 1,
    PLAYER_TEX = 2,
};

enum ShaderType {
    SPRITE_SHA,
    BLOCK_SHA,
    BALL_SHA,
    PLAYER_SHA,
    LIGHT_SHA,
};

class ResourceManager {
public:
    static ResourceManager &getInstance();

    std::shared_ptr<Texture2D> addTexture(TextureType type, const char* filePath, bool alpha);

    std::shared_ptr<Texture2D> getTexture(TextureType type);

    std::shared_ptr<Shader> addShader(ShaderType type, const char* vsPath, const char* fsPath,
                   const char* gsPath);

    std::shared_ptr<Shader> getShader(ShaderType type);

private:
    ResourceManager();

    ~ResourceManager();

    ResourceManager(const ResourceManager &);

    ResourceManager &operator=(const ResourceManager &);

    std::unordered_map<ShaderType, std::shared_ptr<Shader>> shaders;
    std::unordered_map<TextureType, std::shared_ptr<Texture2D>> textures;

    std::shared_ptr<Shader>
    loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile);

    std::shared_ptr<Texture2D> loadTextureFromFile(const char *file, bool alpha);
};
#endif //BREAKOUT3D_RESOURCEMANAGER_H
