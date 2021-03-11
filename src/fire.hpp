#include <GL/glew.h>
#include "vertex.hpp"
#include <math.h>
#include <array>

class Fire
{
private:
	GLuint vao;
	GLuint vao2;
	GLuint vao3;
	GLuint shader;
	int dx, dy, dz;
public:
	void draw(glm::mat4 Model, GLuint MatrixID, glm::mat4  View, glm::mat4 Projection, int dx, int dy, int dz);
	Fire(GLuint shader);
};

