//
// Created by TIANTIAN on 2023/3/19.
//

#ifndef BREAKOUT3D_BALLOBJECT_H
#define BREAKOUT3D_BALLOBJECT_H
#pragma once

#include "GameObject.h"
#include "glm.hpp"

class BallObject : public GameObject {
public:
    BallObject(ObjectSpace space, std::shared_ptr<Texture2D> texture2D);
    ~BallObject();
    glm::vec3 move(float dt, unsigned int window_width);
    float radius;
    bool stuck;
    bool sticky;
    bool passThrough;
};


#endif //BREAKOUT3D_BALLOBJECT_H
