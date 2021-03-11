#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 VertexColor;
layout(location = 2) in vec2 VertexTexture;
out vec3 vColor;
out vec2 vTexture;

uniform mat4 MVP;

void main() {
  gl_Position.xyz = vertexPosition_modelspace;
  gl_Position.w = 1.0;

  gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

  vColor = VertexColor;
  vTexture = VertexTexture;
}