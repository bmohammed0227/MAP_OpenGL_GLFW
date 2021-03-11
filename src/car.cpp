#include <GL/glew.h>
#include "car.hpp"

Car::Car() {
  vertices = {
    glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f),
    glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f),

    glm::vec3(1.0f, -1.0f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f),
    glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f)
  };

    unsigned int
	vertex_index[] =
	    {
	      0, 1, 2,
	      2, 3, 0
	    };
    ibo_size = 6;
  GLuint ibo;
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, ibo_size * sizeof(unsigned int), vertex_index,
               GL_STATIC_DRAW);
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(STRVertex), vertices.data(), GL_STATIC_DRAW);
}

void Car::draw() {
    glDrawElements(GL_TRIANGLES, ibo_size, GL_UNSIGNED_INT, (void *)0);
}

