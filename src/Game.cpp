//
// Created by TIANTIAN on 2023/3/18.
//

#include "Game.h"

Game::Game(int width, int height) : width(width), height(height) {
    init();
}

Game::~Game() {}

void Game::init() {
    auto shader = ResourceManager::getInstance().addShader(SPRITE_SHA,
       "./Resources/asset/shader/sprite/sprite.vert","./Resources/asset/shader/sprite/sprite.frag", nullptr);
    shader->Use().SetInteger("spriteTex", 0);
    render = std::make_shared<SpriteRender>(shader);
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    shader->Use().SetMatrix4("projection", projection);
    /* bricks */
    ResourceManager::getInstance().addTexture(BLOCK_TEX, "./Resources/asset/image/container.png", true);
    levels = std::make_shared<GameLevel>();
    levels->load("./Resources/asset/levels/one.lvl", width, height / 2);
    /* ball */
    auto ball = ResourceManager::getInstance().addTexture(BALL_TEX, "./Resources/asset/image/wall.jpeg", false);
    ObjectSpace space = {
        .position = glm::vec3(1.f),
        .size = glm::vec2(100.f),
        .velocity = glm::vec3(100.0f, -350.0f, 0.f),
        .rotation = 0.f
    };
    gameObject = std::make_shared<BallObject>(space, ball);
}

void Game::update(float duration) {
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    levels->draw(render);
    render->draw(gameObject);
}
