//
// Created by TIANTIAN on 2023/3/19.
//

#include "SpriteRender.h"

SpriteRender::SpriteRender(std::shared_ptr<Shader> spriteShader): shader(std::move(spriteShader)) {
    initRender();
}

SpriteRender::~SpriteRender() {

}

void SpriteRender::draw(const std::shared_ptr<GameObject>& gameObject) {
    shader->Use();
    shader->SetMatrix4("view", glm::mat4(1.f));
    shader->SetMatrix4("model", glm::mat4(1.f));
    shader->SetMatrix4("projection", glm::mat4(1.f));
    auto model = glm::mat4(1.f);
    glm::translate(model, gameObject->space.position);
    shader->SetMatrix4("model", model);

    glActiveTexture(GL_TEXTURE0);
    gameObject->bind();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRender::initRender() {
    GLuint VBO;
    float vertices[] = {
        // pos            // tex
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3*sizeof (float )));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

