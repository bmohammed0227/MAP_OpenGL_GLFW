#include <GL/glew.h>
#include "environment.hpp"
using namespace std;
#include <iostream>
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

Environment::Environment() {
	
	glm::vec2 nullVector = glm::vec2(0,0);
	vertices = {
		glm::vec3(-1, -0.6832772098542, 0),						glm::vec3(0, 0, 1),						nullVector,  // 1
		glm::vec3(-0.7752259910481, -0.7310536957976, 0),		glm::vec3(0, 0, 0.9),  					nullVector,  // 2
		glm::vec3(-0.8, -0.4187115527999, 0.7),					glm::vec3(0, 0.3, 0.8),					nullVector,
		glm::vec3(-0.5973636826423, -0.3569864449502, 0),		glm::vec3(0, 0, 0.7),					nullVector,
		glm::vec3(-0.654574821967, -0.0723036840276, 0),		glm::vec3(0, 0.4, 0.6),					nullVector,
		glm::vec3(-0.95, -0.289820037446, 0),					glm::vec3(0, 0, 0.5),					nullVector,
		glm::vec3(-0.7837162363342, -0.1115273447983, 0.45),	glm::vec3(0, 0.2, 0.9),					nullVector,
		glm::vec3(-0.7634356724748, 0.1418802170533, 0),		glm::vec3(0, 0.2, 0.8),					nullVector,
		glm::vec3(-0.9688024123658, -0.2038131437624, 0),		glm::vec3(0, 0.2, 0.7),					nullVector,
		glm::vec3(-0.967070855012, -0.0568609899734, 0.6),		glm::vec3(0.3, 0.0, 0.5),				nullVector,
		glm::vec3(-1, -0.4, 0),									glm::vec3(0.0, 0.2, 0.5),				nullVector,
		glm::vec3(-0.9225394204773, 0.0723478582739 , 0),		glm::vec3(0.0, 0.1, 0.5),				nullVector,
		glm::vec3(-0.81962329608, 0.25350534751, 0.7),			glm::vec3(0.0, 0.3, 0.5),				nullVector,
		glm::vec3(-0.7822550598144, 0.1970286718143, 0.3),		glm::vec3(0.0, 0.4, 0.5),				nullVector,
		glm::vec3(-0.6915905858449, 0.8953635458457, 0),		glm::vec3(0.0, 0.5, 0.5),				nullVector,
		glm::vec3(-0.4408411670838, 0.3328254791165, 0.3),		glm::vec3(0.3, 0.2, 0.7),				nullVector,
		glm::vec3(-0.4431944409857, 0.1140576279743, 0),		glm::vec3(0.3, 0.2, 0.9),				nullVector,
		glm::vec3(-0.2799469163364, 0.3286997227006, 0),		glm::vec3(0.1, 0.4, 0.8),				nullVector,
		glm::vec3(-0.3553580184701, 0.6776306505678, 0),		glm::vec3(0.3, 0.1, 0.7),				nullVector,
		glm::vec3(-0.28863647659, 0.5331850617281, 0.15),		glm::vec3(0.2, 0.1, 0.5),				nullVector,
		glm::vec3(-0.2456576860497, 0.6201642099589, 0),		glm::vec3(0.2, 0.1, 0.5),				nullVector,
		glm::vec3(-0.2909377535191, 0.6820698664054, 0.1),		glm::vec3(0.1, 0.4, 0.85),				nullVector,
		glm::vec3(-0.2426214600664, 0.7509283581576, 0),		glm::vec3(0.1, 0.4, 0.85),				nullVector,
		glm::vec3(-0.4336883598489, 0.8038996183226, 0.1),		glm::vec3(0.1, 0.4, 0.85),				nullVector,
		glm::vec3(-0.3430505956682, 0.8550508183201, 0),		glm::vec3(0.1, 0.4, 0.85),				nullVector,
	};


	vertices2 = {
		glm::vec3(-10, 10, -0.001), glm::vec3(0.5, 0.0, 1.0), glm::vec2(-100,100),
		glm::vec3(-10, -10, -0.001), glm::vec3(0.5, 0.0, 1.0), glm::vec2(-100,-100),
		glm::vec3(10, 10, -0.001), glm::vec3(0.5, 0.0, 1.0), glm::vec2(100,100),
		glm::vec3(10, -10, -0.001), glm::vec3(0.5, 0.0, 1.0), glm::vec2(100,-100),
		glm::vec3(-10, -10, -0.001), glm::vec3(0.5, 0.0, 1.0), glm::vec2(-100,-100),
		glm::vec3(10, 10, -0.001), glm::vec3(0.5, 0.0, 1.0), glm::vec2(100,100),
	};


	GLuint vbo2;
	glGenBuffers(1, &vbo2);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glBufferData(GL_ARRAY_BUFFER, vertices2.size() * sizeof(STRVertex), vertices2.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)(sizeof(float) * 3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void *)offsetof(STRVertex, texture));


	char data[256 * 256 * 3];
	FILE *f = fopen("ground3.raw", "rb");
	if (f)
	{
		fread(data, 256 * 256 * 3, 1, f);
		fclose(f);
		glGenTextures(1, &text);
		glBindTexture(GL_TEXTURE_2D, text);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}

	glBindVertexArray(0);


	unsigned int
		vertex_index[] =
	{
	  0,1,2,1,2,3,2,3,4,0,1,5,2,5,4,4,6,5,4,6,7,6,7,8,8,6,5,9,10,11,
	12,13,8,12,13,14,13,8,14,13,8,7,13,7,14,15,7,16,15,16,17,15,17,18,7,15,14,15,14,18,17,19,18,17,19,20,
	19,18,20,21,20,22,21,22,18,24,23,18,24,23,14,14,24,18,
	};

	ibo_size = sizeof(vertex_index);
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ibo_size * sizeof(unsigned int), vertex_index,
		GL_STATIC_DRAW);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(STRVertex), vertices.data(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao2);
	glBindVertexArray(vao2);

	
}

void Environment::draw(double dy, glm::mat4 Model, glm::mat4 View, glm::mat4 Projection, GLuint MatrixID, GLuint color_or_texture, GLuint TextureID) {
	
	// First moutains
	glBindVertexArray(vao2);
	Model = glm::translate(Model, glm::vec3(0.f, -dy, 0.0f)); // translate to draw the moutain 'i'
	glm::mat4 MVP = Projection * View * Model;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glDrawElements(GL_TRIANGLES, ibo_size, GL_UNSIGNED_INT, (void *)0);
	Model = glm::translate(Model, glm::vec3(-1.f, dy, 0.0f));
	glBindVertexArray(0);

	// Second moutain
	glBindVertexArray(vao2);
	Model = glm::translate(Model, glm::vec3(0.5f, 0.5f, 0.5f));	 // translate to the center
	Model = glm::rotate(Model, glm::radians(180.f), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate
	Model = glm::translate(Model, glm::vec3(-0.5f, -0.5f, -0.5f)); // Re translate to the initial position

	Model = glm::translate(Model, glm::vec3(-1.f, -dy, 0.0f)); // translate -1 in x axe to increase the distance between the two mountains
	MVP = Projection * View * Model;
	Model = glm::translate(Model, glm::vec3(1.f, -dy, 0.0f)); // Re translate to the initial position
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glDrawElements(GL_TRIANGLES, ibo_size, GL_UNSIGNED_INT, (void *)0);


	//glUniform1f(color_or_texture, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, text);
	glUniform1i(TextureID, 0);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//glUniform1f(color_or_texture, 1);
	glBindVertexArray(0);

	Model = glm::translate(Model, glm::vec3(-1.f, dy, 0.0f));
	glBindVertexArray(0);

}

