//
// Created by TIANTIAN on 2023/3/18.
//

#include "GameObject.h"

#include <utility>

GameObject::GameObject() {

}

GameObject::GameObject(ObjectSpace space, std::shared_ptr<Texture2D> texture2D)
    : space(space), texture(std::move(texture2D)) {

}

GameObject::~GameObject() {

}

void GameObject::bindTexture() {
    texture->Bind();
}