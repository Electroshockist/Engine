#version 450 core
layout (location = 0) in vec3 vVertex;

out vec3 texCoords;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main() {
	texCoords = vec3(vVertex);
	gl_Position = proj * model * vec4(vVertex, 1.0f);
}
