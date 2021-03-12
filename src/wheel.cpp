#include "wheel.hpp"
#include <glm/ext/vector_float3.hpp>
#include <glm/fwd.hpp>
#include <glm/gtx/transform.hpp>

Wheel::Wheel() {
}
Wheel::Wheel(float offsetX, float offsetZ) {
    thickness = 0.5f;
    numPoints = 50;
  
    cylinder = Cylinder(offsetX, offsetZ, thickness);
    base1 = CylinderBase(offsetX, offsetZ+thickness);
    base2 = CylinderBase(offsetX, offsetZ-thickness);

}

void Wheel::draw(GLuint MatrixID, glm::mat4 Model, glm::mat4 View, glm::mat4 Projection) {
  glm::mat4 newModel = glm::scale(Model, glm::vec3(0.06f, 0.06f, 0.06f));
  newModel = glm::translate(newModel, glm::vec3(5.3f, -1.5f, 0.0f));
  glm::mat4 MVP = Projection * View * newModel;
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    cylinder.draw();

    base1.draw();
    base2.draw();

  newModel = glm::scale(Model, glm::vec3(0.06f, 0.06f, 0.06f));
  newModel = glm::translate(newModel, glm::vec3(5.3f, -1.5f, -6.0f));
  MVP = Projection * View * newModel;
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    cylinder.draw();

    base1.draw();
    base2.draw();

  newModel = glm::scale(Model, glm::vec3(0.06f, 0.06f, 0.06f));
  newModel = glm::translate(newModel, glm::vec3(-5.3f, -1.5f, -6.0f));
  MVP = Projection * View * newModel;
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    cylinder.draw();

    base1.draw();
    base2.draw();
    
  newModel = glm::scale(Model, glm::vec3(0.06f, 0.06f, 0.06f));
  newModel = glm::translate(newModel, glm::vec3(-5.3f, -1.5f, 0.0f));
  MVP = Projection * View * newModel;
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    cylinder.draw();

    base1.draw();
    base2.draw();
}
