//
// Created by TIANTIAN on 2023/3/19.
//

#ifndef BREAKOUT3D_SPRITERENDER_H
#define BREAKOUT3D_SPRITERENDER_H
#include <memory>
#include "Shader.h"
#include "GameObject.h"
#include <OpenGL/gl3.h>
#include <gtc/matrix_transform.hpp>

class SpriteRender {
public:
    SpriteRender(std::shared_ptr<Shader> spriteShader);
    ~SpriteRender();

    void draw(const std::shared_ptr<GameObject>& gameObject);
    void initRender();

private:
    std::shared_ptr<Shader> shader;
    GLuint VAO;
};


#endif //BREAKOUT3D_SPRITERENDER_H
