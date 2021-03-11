#include <GL/glew.h>
#include "vertex.hpp"
#include <math.h>
#include <array>

class Environment
{
private:

	std::array<STRVertex, 25> vertices = {};
	GLuint ibo;
	GLuint vao2;
	unsigned int ibo_size;
	std::array<STRVertex, 6> vertices2 = {};
	GLuint vao;
	GLuint text;
public:
	Environment();
	void draw(double dy, glm::mat4 Model, glm::mat4 View, glm::mat4 Projection, GLuint MatrixID, GLuint color_or_texture, GLuint TextureID);
};

