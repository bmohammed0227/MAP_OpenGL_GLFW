#include "cylinder_base.hpp"

CylinderBase::CylinderBase() {
}
CylinderBase::CylinderBase(float offsetX, float offsetZ) {
    numPoints = 50;
    // cylinder positions
    double pi = 3.14, x, y;
    float rayon = 1.5;

    // bases cylinder positions
    STRVertex positions[50 + 3];
    positions[0] = {
      glm::vec3(offsetX, 0.0f, offsetZ),
      glm::vec3(0.0f, 0.0f, 1.0f)
    }; // draw center
    for (int i = 0; i < numPoints + 1; i++)
    {
	if (i < numPoints + 1) { // draw circumference - {last vertex}
	    x = rayon * cos(i * 2 * pi / numPoints);
	    y = rayon * sin(i * 2 * pi / numPoints);
	    positions[i + 1] = {
	      glm::vec3(offsetX+x, y, offsetZ),
	      glm::vec3(0.0f, 0.0f, 1.0f)
	    };
	}
	else
	{
	    positions[i + 1] = {
	      glm::vec3(offsetX, 0.0f, offsetZ),
	      glm::vec3(0.0f, 0.0f, 1.0f)
	    }; // draw last vertex
	}
    }

    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
			  sizeof(STRVertex),
			  (void *)offsetof(STRVertex, color));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}

void CylinderBase::draw() {
    // drawing first cylinder base
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numPoints + 2);
    glBindVertexArray(0);
}
