//
// Created by TIANTIAN on 2023/3/18.
//

#ifndef BREAKOUT3D_GAME_H
#define BREAKOUT3D_GAME_H
#include "SpriteRender.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include <memory>
#include "GameObject.h"
#include "GameLevel.h"
#include "BallObject.h"

enum GameStatus {
    INITIAL = 0,
    RUNNING = 1,
    STOP = 2,
    END = 3,
};

class Game {
public:
    Game(int width, int height);
    ~Game();
    void init();
    void update(float duration);
    void processInput(float duration);

private:
    void checkCollision();

    GameStatus status = INITIAL;
    std::shared_ptr<BallObject> gameObject;
    std::shared_ptr<SpriteRender> render;
    std::shared_ptr<GameLevel> levels;
    int width;
    int height;
};

#endif //BREAKOUT3D_GAME_H
