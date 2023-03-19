//
// Created by TIANTIAN on 2023/3/18.
//

#include "Game.h"

Game::Game() {
    init();
}

Game::~Game() {}

void Game::init() {
    auto shader = ResourceManager::getInstance().addShader(SPRITE_SHA,
       "./Resources/asset/shader/sprite/sprite.vert","./Resources/asset/shader/sprite/sprite.frag", nullptr);
    shader->Use().SetInteger("spriteTex", 0);
    render = std::make_shared<SpriteRender>(shader);
    auto boxTexture = ResourceManager::getInstance().addTexture(BLOCK_TEX, "./Resources/asset/image/container.png", true);
    ObjectSpace space = { .position = glm::vec3(1.f), .size = glm::vec2(100.f), .rotation = 0.f };
    ObjectInfo info = { .isSolid = true, .isDestroy = false };
    gameObject = std::make_shared<GameObject>(space, info, boxTexture);
}

void Game::update(float duration) {
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    render->draw(gameObject);
}
