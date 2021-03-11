#include <GL/glew.h>
#include "vertex.hpp"
#include <math.h>
#include <array>

class Car
{
private:
  std::array<STRVertex, 4> vertices = {};
  GLuint vbo;
  unsigned int ibo_size;
public:
  Car();
  void draw();
};

