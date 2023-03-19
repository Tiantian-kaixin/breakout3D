#include "GameLevel.h"

GameLevel::GameLevel() {

}
GameLevel::~GameLevel() {}

void GameLevel::load(const char *file, unsigned int levelWidth, unsigned int levelHeight) {
    this->Bricks.clear();
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4},
        {4, 1, 4, 1, 4, 0, 0, 1, 0, 0, 4, 1, 4, 1, 4},
        {3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3},
        {3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
    this->init(tileData, levelWidth, levelHeight);
}

void GameLevel::draw(std::shared_ptr<SpriteRender> renderer) {
    for (auto tile : Bricks) {
        if (!tile->isDestroy) {
            renderer->draw(tile);
        }
    }

}

bool GameLevel::isCompleted() {
    for (auto tile : Bricks) {
        if (!tile->isSolid && !tile->isDestroy) {
            return false;
        }
    }
    return true;
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight) {
    unsigned int height = tileData.size();
    unsigned int width = tileData[0].size();
    float unit_width = levelWidth / static_cast<float>(width), unit_height = levelHeight / height; 
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            glm::vec3 pos(unit_width * x, unit_height * y, 0.f);
            glm::vec2 size(unit_width, unit_height);
            ObjectSpace space = {.position = pos, .size = size, .rotation = 0.f};
            auto gameObject = std::make_shared<GameObject>(space, ResourceManager::getInstance().getTexture(BLOCK_TEX));
            gameObject->isDestroy = false;
            if (tileData[y][x] == 1) {
                gameObject->isSolid = true;
            }
            this->Bricks.push_back(gameObject);
        }
    }
}