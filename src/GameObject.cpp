//
// Created by TIANTIAN on 2023/3/18.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject(ObjectSpace space, ObjectInfo info, std::shared_ptr<Texture2D> texture2D)
    : space(space), info(info), texture(std::move(texture2D)) {

}

GameObject::~GameObject() {

}

void GameObject::bind() {
    texture->Bind();
}