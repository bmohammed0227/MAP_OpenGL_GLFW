#include <GL/glew.h>
#include <glm/fwd.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <math.h>
#include <array>
#include "vertex.hpp"
#include "cylinder.hpp"
#include "cylinder_base.hpp"

class Wheel
{
private:
  float thickness;
  unsigned int numPoints;
  Cylinder cylinder;
  CylinderBase base1, base2;

public:
  Wheel();
  Wheel(float, float);
  void draw(GLuint, glm::mat4, glm::mat4, glm::mat4);
};
