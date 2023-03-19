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

enum GameStatus {
    INITIAL = 0,
    RUNNING = 1,
    STOP = 2,
    END = 3,
};

class Game {
public:
    Game();
    ~Game();
    void init();
    void update(float duration);
    void processInput(float duration);

private:
    void checkCollision();

    GameStatus status = INITIAL;
    std::shared_ptr<GameObject> gameObject;
    std::shared_ptr<SpriteRender> render;
};

#endif //BREAKOUT3D_GAME_H
