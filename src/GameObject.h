//
// Created by TIANTIAN on 2023/3/18.
//

#ifndef BREAKOUT3D_GAMEOBJECT_H
#define BREAKOUT3D_GAMEOBJECT_H

#include <memory>
#include <glm.hpp>
#include "Texture2D.h"

struct ObjectSpace {
    glm::vec3 position;
    glm::vec2 size;
    float rotation;
};

struct ObjectInfo {
    bool isSolid;
    bool isDestroy;
};

class GameObject {
public:
    GameObject(ObjectSpace space, ObjectInfo info, std::shared_ptr<Texture2D> texture2D);
    ~GameObject();
    void bind();
    ObjectSpace space;
    ObjectInfo info;
private:
    std::shared_ptr<Texture2D> texture;
};


#endif //BREAKOUT3D_GAMEOBJECT_H
