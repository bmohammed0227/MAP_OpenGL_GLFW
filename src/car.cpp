#include <GL/glew.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/fwd.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <ostream>
#include "car.hpp"

Car::Car() {
  glm::vec2 nullVector = glm::vec2(0,0);
  vertices = {
    // Side 1
    // Glass
    glm::vec3(-0.175f, 0.153f, -0.4f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(-0.196f, 0.079f, -0.4f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(0.145f, 0.079f, -0.4f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(0.017f, 0.153f, -0.4f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(-0.243f, 0.081f, -0.4f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    // Door
    glm::vec3(-0.205f, 0.17f, -0.4f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.035f, 0.17f, -0.4f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.193f, 0.074f, -0.4f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.5f, 0.017f, -0.4f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.5f, 0.003f, -0.4f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.5f, -0.017f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.446f, -0.061f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.412f, 0.003f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.259f, 0.003f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.207f, -0.1f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.166f, -0.1f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.22f, 0.003f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.384f, 0.003f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.42f, -0.07f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.485f, -0.053f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.5f, 0.003f, -0.4f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.463f, 0.06f, -0.4f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.411f, 0.081f, -0.4f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,

    // Side 2
    // Glass
    glm::vec3(-0.175f, 0.153f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(-0.196f, 0.079f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(0.145f, 0.079f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(0.017f, 0.153f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(-0.243f, 0.081f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    // Door
    glm::vec3(-0.205f, 0.17f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.035f, 0.17f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.193f, 0.074f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.5f, 0.017f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.5f, 0.003f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.5f, -0.017f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.446f, -0.061f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.412f, 0.003f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.259f, 0.003f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(0.207f, -0.1f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.166f, -0.1f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.22f, 0.003f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.384f, 0.003f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.42f, -0.07f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.485f, -0.053f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.5f, 0.003f, 0.0f), glm::vec3(0.5f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.463f, 0.06f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), nullVector,
    glm::vec3(-0.411f, 0.081f, 0.0f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,


    // Front glass
    glm::vec3(0.035f, 0.17f, -0.02f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(0.193f, 0.074f, -0.02f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,

    glm::vec3(0.035f, 0.17f, -0.38f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector,
    glm::vec3(0.193f, 0.074f, -0.38f), glm::vec3(0.25f, 0.0f, 0.5f), nullVector
  };

    unsigned int
	vertex_index[] =
	    {
	      // Side 1
	      0, 1, 2, 2, 3, 0, 5, 4, 22, // Glass
	      5, 6, 0, 0, 3, 6, 6, 7, 3, 3, 2, 7,
	      5, 0, 1, 1, 4, 5,
	      7, 8, 9, 9, 13, 7,
	      7, 13, 20, 20, 22, 7,
	      20, 21, 22,
	      9, 10, 11, 11, 12, 9,
	      13, 14, 15, 15 ,16, 13,
	      17, 18, 19, 19, 20, 17,

	      // Side 2
	      23, 24, 25, 25, 26, 23, 28, 27, 45, // Glass
	      28, 29, 23, 23, 26, 29, 29, 30, 26, 26, 25, 30,
	      28, 23, 24, 24, 27, 28,
	      30, 31, 32, 32, 36, 30,
	      30, 36, 43, 43, 45, 30,
	      43, 44, 45,
	      32, 33, 34, 34, 35, 32,
	      36, 37, 38, 38 ,39, 36,
	      40, 41, 42, 42, 43, 40,

	      // Top
	      8, 10, 33, 33, 31, 8,
	      7, 8, 31, 31, 30, 7,
	      46, 47, 49, 49, 48, 46,
	      6, 7, 49, 49, 48, 6,
	      29, 30, 47, 47, 46, 29,
	      5, 6, 29, 29, 28, 5,
	      22, 5, 28, 28, 45, 22,
	      21, 22, 45, 45, 44, 21,
	      20, 21, 44, 44, 43, 20,
	      19, 20, 43, 43, 42, 19,
	    };


  glGenBuffers(1, &vbo);
  glGenVertexArrays(1, &vao);         // Création du vao
  glBindVertexArray(vao);             // Bind du vao
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(STRVertex),
	       vertices.data(), GL_STATIC_DRAW);
  
    ibo_size = sizeof(vertex_index);
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
	       ibo_size * sizeof(unsigned int),
	       vertex_index, GL_STATIC_DRAW);
  // Spécification des attributs
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex),
                        (void *)offsetof(STRVertex, color));

  glBindVertexArray(0);             // Débinder
  glBindBuffer(GL_ARRAY_BUFFER, 0); // Débinder

  wheel = Wheel(0.335f, -0.4f);

  posX = 0.0f;
}

void Car::draw(GLuint MatrixID, glm::mat4 Model, glm::mat4 View, glm::mat4 Projection, int isMoving) {

  glm::mat4 newModel = glm::scale(Model, glm::vec3(0.1f, 0.1f, 0.1f));
  if (isMoving != 0) {
    posX += isMoving * 0.11f;
  }
  newModel = glm::rotate(newModel, glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f));
  newModel = glm::rotate(newModel, glm::radians(90.f), glm::vec3(0.0f, 1.0f, 0.0f));
  newModel = glm::translate(newModel, glm::vec3(posX, 0.15f, 7.0f));
  glm::mat4 MVP = Projection * View * newModel;
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, ibo_size, GL_UNSIGNED_INT, (void *)0);
    glBindVertexArray(0);

    wheel.draw(MatrixID, newModel, View, Projection);
}

