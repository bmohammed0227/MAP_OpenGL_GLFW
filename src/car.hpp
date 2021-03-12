#include <GL/glew.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/fwd.hpp>
#include <math.h>
#include <array>
#include "wheel.hpp"

class Car
{
private:
  std::array<STRVertex, 50> vertices = {};
  Wheel wheel;
  GLuint vbo, vao, ibo;
  unsigned int ibo_size;
  float posX;
public:
  Car();
  void draw(GLuint, glm::mat4, glm::mat4, glm::mat4, int);
};

