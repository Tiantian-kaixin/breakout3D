//
// Created by TIANTIAN on 2023/3/18.
//

#ifndef BREAKOUT3D_GAMEOBJECT_H
#define BREAKOUT3D_GAMEOBJECT_H
#pragma once
#include <memory>
#include <glm.hpp>
#include "Texture2D.h"

struct ObjectSpace {
    glm::vec3 position;
    glm::vec2 size;
    glm::vec3 velocity;
    float rotation;
    float radius;
};

class GameObject {
public:
    GameObject();
    GameObject(ObjectSpace space, std::shared_ptr<Texture2D> texture2D);
    ~GameObject();
    void bindTexture();
    ObjectSpace space;
    bool isSolid;
    bool isDestroy;
private:
    std::shared_ptr<Texture2D> texture;
};


#endif //BREAKOUT3D_GAMEOBJECT_H
