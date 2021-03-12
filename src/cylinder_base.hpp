#include <GL/glew.h>
#include <math.h>
#include "vertex.hpp"

class CylinderBase
{
private:
  unsigned int numPoints;
  GLuint vbo, vao;
public:
  CylinderBase();
  CylinderBase(float, float);
  void draw();
};
