#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"../models/shaderClass.h"
#include"../models/VAO.h"
#include"../models/VBO.h"
#include"../models/EBO.h"
#include"shape.h"

class Wall : public Shape {
private:
    float vertices[24]; 
    unsigned int indices[6];

public:
    Wall(glm::vec3 pos, glm::vec3 col) : Shape(pos, col) {
        setupMesh();
    }

    void setupMesh() override {
        float wallVertices[] = {
            // Positions             // Colors
            -1.0f, -0.5f, -0.1f,     color.r, color.g, color.b,
             1.0f, -0.5f, -0.1f,     color.r, color.g, color.b,
             1.0f,  0.5f, -0.1f,     color.r, color.g, color.b,
            -1.0f,  0.5f, -0.1f,     color.r, color.g, color.b
        };

        unsigned int wallIndices[] = {
            0, 1, 2,
            2, 3, 0
        };

        // نسخ البيانات
        memcpy(vertices, wallVertices, sizeof(wallVertices));
        memcpy(indices, wallIndices, sizeof(wallIndices));
        vao = VAO();
        vao.Bind();
        vbo = VBO(vertices,sizeof(vertices));
        ebo = EBO(indices,sizeof(indices));
        vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float),(void*)0);
        vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float),(void*)(3 * sizeof(float)));
        vao.Unbind();
    }

    void draw(Shader& shader) override {
        // إنشاء مصفوفة النموذج
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position); // تعيين الموضع
       
        GLuint modelLoc = glGetUniformLocation(shader.ID, "modelBox");
        if (modelLoc == -1) {
            std::cerr << "Error: 'model' uniform not found in the shader program!" << std::endl;
            return; // خروج لتجنب أخطاء إضافية
        }

        // تمرير مصفوفة النموذج إلى الشيدر
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        // ربط VAO ورسم العنصر
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        vao.Unbind();
    }

};
