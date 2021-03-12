#include "cylinder.hpp"

Cylinder::Cylinder() {
  
}
Cylinder::Cylinder(float offsetX, float offsetZ, float length) {
  numPoints = 50;

  // Cylinder positions
  double pi = 3.14, x, y;
  float rayon = 1.5;
  STRVertex positions[numPoints + 2];
  for (int i = 0; i < numPoints + 1; i = i + 2) {
    x = rayon * cos(i * 2 * pi / numPoints);
    y = rayon * sin(i * 2 * pi / numPoints);
    positions[i] = {glm::vec3(x+offsetX, y, offsetZ - length),
                    glm::vec3(0.0f, 0.0f, 1.0f)};
    positions[i + 1] = {glm::vec3(x+offsetX, y, offsetZ + length),
                        glm::vec3(1.0f, 0.0f, 1.0f)};
  }

  glGenBuffers(1, &vbo);              // Création du vbo
  glGenVertexArrays(1, &vao);         // Création du vao
  glBindVertexArray(vao);             // Bind du vao
  glBindBuffer(GL_ARRAY_BUFFER, vbo); // Bind du vbo
  glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions,
               GL_STATIC_DRAW); // Remplissage du vbo

  // Spécification des attributs
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex),
                        (void *)offsetof(STRVertex, color));

  glBindVertexArray(0);             // Débinder
  glBindBuffer(GL_ARRAY_BUFFER, 0); // Débinder
}

void Cylinder::draw() {
    // drawing cylinder
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, numPoints + 2);
    glBindVertexArray(0);
}
