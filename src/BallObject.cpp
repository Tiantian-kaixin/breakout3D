//
// Created by TIANTIAN on 2023/3/19.
//

#include "BallObject.h"

BallObject::BallObject(ObjectSpace space, std::shared_ptr<Texture2D> texture2D):
    GameObject(space, texture2D), stuck(true), sticky(false), passThrough(false) {
}
BallObject::~BallObject() {}

glm::vec3 BallObject::move(float dt, unsigned int window_width) {
    if (!this->stuck) {
        auto position = &space.position;
        auto size = &space.size;
        auto velocity = &space.velocity;
        glm::vec3 v = glm::vec3(1.f);
        v*= dt;
        position->x += velocity->x * dt;
        position->y += velocity->y * dt;
        position->z += velocity->z * dt;
        if (position->x <= 0.0f) {
            velocity->x = -velocity->x;
            position->x = 0.0f;
        } else if (position->x + size->x >= window_width) {
            velocity->x = -velocity->x;
            position->x = window_width - size->x;
        }
        if (position->y <= 0.0f) {
            velocity->y = -velocity->y;
            position->y = 0.0f;
        }
    }
    return space.position;
}