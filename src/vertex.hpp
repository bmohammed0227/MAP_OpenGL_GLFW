#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/fwd.hpp>

#ifndef VERTEX_H
#define VERTEX_H

struct STRVertex {
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texture;
};

#endif
