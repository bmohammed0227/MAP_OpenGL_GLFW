#include <GL/glew.h>
#include "vertex.hpp"
#include <math.h>
#include <array>

class Tree
{
private:
	std::array<STRVertex, 29> vertices = {};
	GLuint vao;
	GLuint vao2;
	GLuint vao3;
	GLuint vao4;
	GLuint vao5;
	GLuint vao6;
	const int numP = 50;
	const int numP2 = 100;
	const int numP4 = 100;
	unsigned int ibo_size;
	GLuint shader;
	int dx, dy, dz;
public:
	void draw(glm::mat4 Model, GLuint MatrixID, glm::mat4  View, glm::mat4 Projection, int dx, int dy, int dz);
	Tree(GLuint shader);
};

