#include <GL/glew.h>
#include <math.h>
#include "vertex.hpp"

class Cylinder
{
private:
  unsigned int numPoints;
  GLuint vbo, vao;
public:
  Cylinder();
  Cylinder(float, float, float);  // offsetZ, length
  void draw();
};
