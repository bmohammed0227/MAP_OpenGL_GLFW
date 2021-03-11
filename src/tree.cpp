#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <array>
#include <cstddef>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>

#include "tree.hpp"

Tree::Tree(GLuint s) {
	shader = s;
	// cylinder positions
	double pi = 3.14, x, y;
	float rayon = 0.5;
	const int numPoints =  50;
	STRVertex positions[numPoints + 2];
	for (int i = 0; i < numPoints + 1; i = i + 2)
	{
		x = rayon * cos(i * 2 * pi / numPoints);
		y = rayon * sin(i * 2 * pi / numPoints);
		positions[i] = { glm::vec3(x, y, 0.0f), glm::vec3(0.45f, 0.0f, 0.0f) };
		positions[i + 1] = { glm::vec3(x, y, 4.0f), glm::vec3(0.45f, 0.0f, 0.0f) };
	}

	// bases cylinder positions
	const int numPoints2 = 100;
	STRVertex positions2[numPoints2 + 3];
	STRVertex positions3[numPoints2 + 3];
	positions2[0] = { glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.45f, 0.0f, 0.0f) }; // draw center
	positions3[0] = { glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(0.45f, 0.0f, 0.0f) }; // draw center
	for (int i = 0; i < numPoints2 + 1; i++)
	{
		if (i < numPoints2 + 1) { // draw circumference - {last vertex}
			x = rayon * cos(i * 2 * pi / numPoints2);
			y = rayon * sin(i * 2 * pi / numPoints2);
			positions2[i + 1] = { glm::vec3(x, y, 0.0f), glm::vec3(0.45f, 0.0f, 0.0f) };
			positions3[i + 1] = { glm::vec3(x, y, 4.0f), glm::vec3(0.45f, 0.0f, 0.0f) };
		}
		else
		{
			positions2[i + 1] = { glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.45f, 0.0f, 0.0f) }; // draw last vertex
			positions3[i + 1] = { glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(0.45f, 0.0f, 0.0f) }; // draw last vertex
		}

	}

	const int numPoints4 = 100;
	STRVertex positions4[numPoints4 + 2];
	STRVertex positions5[numPoints4 + 2];
	STRVertex positions6[numPoints4 + 2];

	positions4[0] = { glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(0.0f, 0.0f, 1.0f) }; // draw center
	positions5[0] = { glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 0.0f, 1.0f) }; // draw center
	positions6[0] = { glm::vec3(0.0f, 0.0f, -4.0f), glm::vec3(0.0f, 0.0f, 1.0f) }; // draw center
	for (int i = 0; i < numPoints4 + 1; i = i + 2)
	{
		double x1 = (rayon + 1) * cos(i * 2 * pi / numPoints4);
		double y1 = (rayon + 1) * sin(i * 2 * pi / numPoints4);

		double x2 = (rayon + 0.5) * cos(i * 2 * pi / numPoints4);
		double y2 = (rayon + 0.5) * sin(i * 2 * pi / numPoints4);

		double x3 = (rayon + 0.25) * cos(i * 2 * pi / numPoints4);
		double y3 = (rayon + 0.25) * sin(i * 2 * pi / numPoints4);

		positions4[i] = { glm::vec3(x1, y1, 0.0f), glm::vec3(0.0f, 0.7f, 0.0f) };
		positions4[i + 1] = { glm::vec3(0, 0, -2.0f), glm::vec3(0.0f, 0.7f, 0.0f) };

		positions5[i] = { glm::vec3(x2, y2, -1.0f), glm::vec3(0.0f, 0.85f, 0.0f) };
		positions5[i + 1] = { glm::vec3(0, 0, -3.0f), glm::vec3(0.0f, 0.85f, 0.0f) };

		positions6[i] = { glm::vec3(x3, y3, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f) };
		positions6[i + 1] = { glm::vec3(0, 0, -4.0f), glm::vec3(0.0f, 1.0f, 0.0f) };
	}

	GLuint vbo;
	GLuint vbo2;
	GLuint vbo3;
	GLuint vbo4;
	GLuint vbo5;
	GLuint vbo6;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glGenBuffers(1, &vbo); 
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW); 

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, color));

	glBindVertexArray(0); 
	glBindBuffer(GL_ARRAY_BUFFER, 0); 

	glGenBuffers(1, &vbo2);
	glGenVertexArrays(1, &vao2);
	glBindVertexArray(vao2);
	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions2), positions2, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo3);
	glGenVertexArrays(1, &vao3);
	glBindVertexArray(vao3);
	glBindBuffer(GL_ARRAY_BUFFER, vbo3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions3), positions3, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo4);
	glGenVertexArrays(1, &vao4);
	glBindVertexArray(vao4);
	glBindBuffer(GL_ARRAY_BUFFER, vbo4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions4), positions4, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo5);
	glGenVertexArrays(1, &vao5);
	glBindVertexArray(vao5);
	glBindBuffer(GL_ARRAY_BUFFER, vbo5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions5), positions5, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo6);
	glGenVertexArrays(1, &vao6);
	glBindVertexArray(vao6);
	glBindBuffer(GL_ARRAY_BUFFER, vbo6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions6), positions6, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Tree::draw(glm::mat4 Model, GLuint MatrixID, glm::mat4  View, glm::mat4 Projection, int dx, int dy, int dz) {
	Model = glm::scale(Model, glm::vec3(0.01, 0.01, 0.01));
	Model = glm::rotate(Model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // rotation on the y axis
	Model = glm::translate(Model, glm::vec3(20.f+ dx, -10.0f+dy, 0.0f+dz));
	glm::mat4 MVP;
	MVP = Projection * View * Model;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	Model = glm::translate(Model, glm::vec3(20.f - dx, -10.0f - dy, 0.0f - dz));

	// drawing tree
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numP + 1);
	glBindVertexArray(0);


	// drawing tree base
	glBindVertexArray(vao2);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numP2 + 2);
	glBindVertexArray(0);

	// drawing second tree base
	glBindVertexArray(vao3);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numP2 + 2);
	glBindVertexArray(0);


	// drawing tree leaves 1
	glBindVertexArray(vao4);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numP4 + 1);
	glBindVertexArray(0);

	// drawing tree leaves 2
	glBindVertexArray(vao5);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numP4 + 1);
	glBindVertexArray(0);

	// drawing tree leaves 3
	glBindVertexArray(vao6);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numP4 + 1);
	glBindVertexArray(0);

}