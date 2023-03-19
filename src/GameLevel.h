#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>
#include <glm.hpp>
#include "GameObject.h"
#include "SpriteRender.h"
#include "ResourceManager.h"
#include <memory>

class GameLevel {
public:
    std::vector<std::shared_ptr<GameObject>> Bricks;
    GameLevel();
    ~GameLevel();
    void load(const char *file, unsigned int levelWidth, unsigned int levelHeight) ;
    void draw(std::shared_ptr<SpriteRender> renderer);
    bool isCompleted();
private:
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif