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
#include "shader.hpp"
#include "car.hpp"
#include "environment.hpp"
#include "tree.hpp"
#include "fire.hpp"

double xpos, ypos;
bool lbutton_down = false;
double diffX = 0;
double diffY = 0;
double diffXOld = 0;
double diffYOld = 0;
double xOld = 0;
double yOld = 0;
double SCALE_ROTATION = 0.5;
double SCALE = 0.5;
double xCamera = 8, yCamera = -1.5, zCamera = 4.5;
double xOrigin = 0, yOrigin = 0, zOrigin = -40;
double scaleX = 1, scaleY = 1, scaleZ = 1;
float rotationX = 0, rotationY = 0, rotationZ = 0;
int carIsMoving = 0;
static void key_callback(GLFWwindow *window, int key, int scancode, int action,
	int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	else if ((key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) && action == GLFW_PRESS)
		scaleX += SCALE;
	else if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_A) && action == GLFW_PRESS)
		scaleX -= SCALE;
	if ((key == GLFW_KEY_UP || key == GLFW_KEY_W) && action == GLFW_PRESS)
		carIsMoving = -1;
	else if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_S) && action == GLFW_PRESS)
	    carIsMoving = 1;
	if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_S || key == GLFW_KEY_UP || key == GLFW_KEY_W) && action == GLFW_RELEASE)
	    carIsMoving = 0;
	xCamera -= 0.0605*carIsMoving;
	std::cout << "xCamera : " << xCamera << std::endl;
	if (key == GLFW_KEY_I && action == GLFW_PRESS)
	{
		xCamera++;
		std::cout << "xCamera : " << xCamera << std::endl;
	}
	if (key == GLFW_KEY_O && action == GLFW_PRESS)
	{
		yCamera++;
		std::cout << "yCamera : " << yCamera << std::endl;
	}
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		zCamera++;
		std::cout << "zCamera : " << zCamera << std::endl;
	}

	if (key == GLFW_KEY_K && action == GLFW_PRESS)
	{
		xCamera--;
		std::cout << "xCamera : " << xCamera << std::endl;
	}
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		yCamera--;
		std::cout << "yCamera : " << yCamera << std::endl;
	}
	if (key == GLFW_KEY_M && action == GLFW_PRESS)
	{
		zCamera--;
		std::cout << "zCamera : " << zCamera << std::endl;
	}

	///////////////////////////////////////
	if (key == GLFW_KEY_T && action == GLFW_PRESS)
	{
		xOrigin++;
		std::cout << "xOrigin : " << xOrigin << std::endl;
	}
	if (key == GLFW_KEY_Y && action == GLFW_PRESS)
	{
		yOrigin++;
		std::cout << "yOrigin : " << yOrigin << std::endl;
	}
	if (key == GLFW_KEY_U && action == GLFW_PRESS)
	{
		zOrigin++;
		std::cout << "zOrigin : " << zOrigin << std::endl;
	}

	if (key == GLFW_KEY_G && action == GLFW_PRESS)
	{
		xOrigin--;
		std::cout << "xOrigin : " << xOrigin << std::endl;
	}
	if (key == GLFW_KEY_H && action == GLFW_PRESS)
	{
		yOrigin--;
		std::cout << "yOrigin : " << yOrigin << std::endl;
	}
	if (key == GLFW_KEY_J && action == GLFW_PRESS)
	{
		zOrigin--;
		std::cout << "zOrigin : " << zOrigin << std::endl;
	}
}
static void cursor_position_callback(GLFWwindow *window, double xposNew,
	double yposNew) {
	xpos = xposNew;
	ypos = yposNew;
}

static void mouse_button_callback(GLFWwindow *window, int button, int action,
	int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (GLFW_PRESS == action)
			lbutton_down = true;
		else if (GLFW_RELEASE == action)
			lbutton_down = false;
	}

	if (lbutton_down) {
		xOld = xpos;
		yOld = ypos;
		diffXOld = 0;
		diffYOld = 0;
	}
}

static void scroll_callback(GLFWwindow *window, double xoffset,
	double yoffset) {
	zCamera += (yoffset)*SCALE;
}
void MouseMotion(double x, double y) {
	diffX = xOld - x;
	diffY = yOld - y;
}

int main() {
	GLFWwindow *window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 960, "Projet SI", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	if (glewInit() != GLEW_OK)
		std::cout << "Error while initializing glew!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;


	Car car = Car();
	Environment env = Environment();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex),
		(void *)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex),
		(void *)(sizeof(float) * 3));

	GLuint shader =
		LoadShaders("res/shaders/SimpleVertexShader.vert",
			"res/shaders/SimpleFragmentShader.frag");

	Tree tree = Tree(shader);
	Fire fire = Fire(shader);
	glUseProgram(shader);

	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(glm::vec3(xCamera, yCamera, zCamera),
		glm::vec3(xOrigin, yOrigin, zOrigin), glm::vec3(0, 1, 0));
	glm::mat4 Model = glm::mat4(1.0f);

	glm::mat4 MVP = Projection * View * Model;

	GLuint MatrixID = glGetUniformLocation(shader, "MVP");
	GLuint TextureID = glGetUniformLocation(shader, "ourTexture");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	double tree_pos_x[11][29];
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 29; j++)
			tree_pos_x[i][j] = rand() % 45 * (-1) - 10;

	double day_night_speed = 0.001;
	double direction = 1;
	double clear_color_x = 0.7;
	double clear_color_z = 0.8;
	GLint color_or_texture = glGetUniformLocation(shader, "color_or_texture");
	glUniform1f(color_or_texture, 0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Render here */

		if (clear_color_x >= 0.7 || clear_color_x <= 0.1)
			direction *= -1;

		clear_color_x += direction * day_night_speed;
		clear_color_z += direction * day_night_speed;
		glClearColor(clear_color_x, 0.f, clear_color_z, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (lbutton_down) {
			MouseMotion(xpos, ypos);
			rotationX += (diffX - diffXOld) * SCALE_ROTATION;
			rotationY += (diffY - diffYOld) * SCALE_ROTATION;
			diffXOld = diffX;
			diffYOld = diffY;
		}


		glm::mat4 View =
			glm::lookAt(glm::vec3(xCamera - 30, yCamera + 2, zCamera - 8),
				glm::vec3(xOrigin + 90, yOrigin - 30, zOrigin + 45), glm::vec3(0, 1, 0));

		glm::mat4 Model = glm::mat4(1.0f);
		Model = glm::translate(Model, glm::vec3(-1.f, 0.0f, 0.0f));
		Model = glm::scale(Model, glm::vec3(3.f + scaleX, 3.f + scaleY, 3.f + scaleZ));
		Model = glm::rotate(Model, glm::radians(-90.f), glm::vec3(1.0f, 0.0f, 0.0f));
		Model = glm::rotate(Model, glm::radians(90.f), glm::vec3(0.0f, 0.0f, 1.0f));
		//Model = glm::rotate(Model, glm::radians(10.f), glm::vec3(0.0f, 1.0f, 0.0f));
		Model = glm::rotate(Model, glm::radians(rotationY),
			glm::vec3(1.0f, 0.0f, 0.0f));
		Model = glm::rotate(Model, glm::radians(rotationX),
			glm::vec3(0.0f, 1.0f, 1.0f));

		Model = glm::translate(Model, glm::vec3(0.f, -((int)((xCamera - 58) / 60)) * 15, 0.0f));
		glm::mat4 MVP = Projection * View * Model;

		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glUniform1f(color_or_texture, 1);
		
		Model = glm::translate(Model, glm::vec3(0.f, ((int)((xCamera - 58) / 60)) * 15, 0.0f));
		car.draw(MatrixID, Model, View, Projection, carIsMoving);
		Model = glm::translate(Model, glm::vec3(0.f, -((int)((xCamera - 58) / 60)) * 15, 0.0f));

		for (double i = -7.5; i < 8; i = i + 1.5)
		{
			env.draw(i, Model, View, Projection, MatrixID, color_or_texture, TextureID);
			for (int j = -120; j < 21; j = j + 5) {
				int i_index = i / 1.5 + 5;
				int j_index = (j + 120) / 5;
				tree.draw(Model, MatrixID, View, Projection, tree_pos_x[i_index][j_index], j + i * 100, -4);
			}
		}

		for (double i = -7.5; i < 8; i = i + 1.5)
		{
			fire.draw(Model, MatrixID, View, Projection, 150, 0, i * 200);
			fire.draw(Model, MatrixID, View, Projection, 280, 0, i * 200);
		}
		glUniform1f(color_or_texture, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}
