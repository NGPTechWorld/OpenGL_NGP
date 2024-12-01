#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"../models/shaderClass.h"
#include"../models/VAO.h"
#include"../models/VBO.h"
#include"../models/EBO.h"

class Shape {
protected:
    VAO vao;
    VBO vbo;
    EBO ebo;
    glm::vec3 position;  
    glm::vec3 color;      

public:
    Shape(glm::vec3 pos, glm::vec3 col) : position(pos), color(col) {}

    virtual void setupMesh() = 0;

    virtual void draw(Shader& shader) = 0;

    void setPosition(glm::vec3 newPos) {
        position = newPos;
    }

    glm::vec3 getPosition() {
        return position;
    }
};

