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

#include "fire.hpp"

Fire::Fire(GLuint s) {
	shader = s;
	// colors
	glm::vec3 fire_color1 = glm::vec3(1, 1, 0);
	glm::vec3 fire_color2 = glm::vec3(0.8, 0.7, 0);
	glm::vec3 fire_color3 = glm::vec3(1, 0, 0);

	glm::vec2 nullVector = glm::vec2(0, 0);
	// fire_color1 cube
	STRVertex positions[]{
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f), fire_color1, nullVector,

	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color1, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(1.0f, 1.0f,-1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color1, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color1, nullVector,

	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f), fire_color1, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f), fire_color1, nullVector,

	glm::vec3(1.0f, 1.0f,-1.0f), fire_color1, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color1, nullVector,

	glm::vec3(1.0f, 1.0f,-1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f), fire_color1, nullVector,

	glm::vec3(1.0f,-1.0f, 1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color1, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f), fire_color1, nullVector,

	glm::vec3(1.0f,-1.0f, 1.0f), fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color1, nullVector,

	glm::vec3(1.0f,-1.0f,-1.0f),fire_color1, nullVector,
	glm::vec3(1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f),fire_color1, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color1, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f),fire_color1, nullVector,
	glm::vec3(1.0f, 1.0f,-1.0f),fire_color1, nullVector,
	};

	// fire_color2 cube
	STRVertex positions2[]{
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f), fire_color2, nullVector,

	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color2, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(1.0f, 1.0f,-1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color2, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color2, nullVector,

	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f), fire_color2, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f), fire_color2, nullVector,

	glm::vec3(1.0f, 1.0f,-1.0f), fire_color2, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color2, nullVector,

	glm::vec3(1.0f, 1.0f,-1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f), fire_color2, nullVector,

	glm::vec3(1.0f,-1.0f, 1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color2, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f), fire_color2, nullVector,

	glm::vec3(1.0f,-1.0f, 1.0f), fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color2, nullVector,

	glm::vec3(1.0f,-1.0f,-1.0f),fire_color2, nullVector,
	glm::vec3(1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f),fire_color2, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color2, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f),fire_color2, nullVector,
	glm::vec3(1.0f, 1.0f,-1.0f),fire_color2, nullVector,
	};

	// fire_color3 cube
	STRVertex positions3[]{
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f), fire_color3, nullVector,

	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color3, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(1.0f, 1.0f,-1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color3, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color3, nullVector,

	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f), fire_color3, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f), fire_color3, nullVector,

	glm::vec3(1.0f, 1.0f,-1.0f), fire_color3, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color3, nullVector,

	glm::vec3(1.0f, 1.0f,-1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f, 1.0f,-1.0f), fire_color3, nullVector,

	glm::vec3(1.0f,-1.0f, 1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f), fire_color3, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f), fire_color3, nullVector,

	glm::vec3(1.0f,-1.0f, 1.0f), fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(-1.0f,-1.0f,-1.0f),fire_color3, nullVector,

	glm::vec3(1.0f,-1.0f,-1.0f),fire_color3, nullVector,
	glm::vec3(1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(1.0f,-1.0f, 1.0f),fire_color3, nullVector,

	glm::vec3(1.0f, 1.0f, 1.0f),fire_color3, nullVector,
	glm::vec3(1.0f,-1.0f,-1.0f),fire_color3, nullVector,
	glm::vec3(1.0f, 1.0f,-1.0f),fire_color3, nullVector,
	};


	GLuint vbo;
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


	GLuint vbo2;
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


	GLuint vbo3;
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
}

void Fire::draw(glm::mat4 Model, GLuint MatrixID, glm::mat4  View, glm::mat4 Projection, int dx, int dy, int dz) {
	
	
	float *positions_flamme_1 = new float[25];
	float *positions_flamme_2 = new float[15];
	float *positions_flamme_3 = new float[9];

	Model = glm::scale(Model, glm::vec3(0.004f, 0.004f, 0.004f));
	Model = glm::rotate(Model, glm::radians(-90.f), glm::vec3(1.0f, 0.0f, 0.0f));
	Model = glm::translate(Model, glm::vec3(dx, dy, dz));
		glm::mat4 MVP;
		glBindVertexArray(vao);
		for (float i = 0; i < 25; i = i++) {
			positions_flamme_1[(int)i] = rand() % 2;
			Model = glm::translate(Model, glm::vec3(-1, positions_flamme_1[(int)i], 0));
			MVP = Projection * View * Model;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			Model = glm::translate(Model, glm::vec3(0.0f, -positions_flamme_1[(int)i], 0));
		}

		Model = glm::translate(Model, glm::vec3(4, -1.5, 0));

		glBindVertexArray(vao2);
		for (float i = 0; i < 15; i = i++) {
			positions_flamme_2[(int)i] = rand() % 2;
			Model = glm::translate(Model, glm::vec3(1, positions_flamme_2[(int)i], 0));
			MVP = Projection * View * Model;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			Model = glm::translate(Model, glm::vec3(0.0f, -positions_flamme_2[(int)i], 0));
		}

		
		Model = glm::translate(Model, glm::vec3(-12, -2, 0));

		glBindVertexArray(vao3);
		for (float i = 0; i < 9; i = i++) {
			positions_flamme_3[(int)i] = rand() % 2;
			Model = glm::translate(Model, glm::vec3(1, positions_flamme_3[(int)i], 0));
			MVP = Projection * View * Model;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			Model = glm::translate(Model, glm::vec3(0.0f, -positions_flamme_3[(int)i], 0));
		}
}