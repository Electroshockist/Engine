// #version 330 core
// layout (location = 0) in vec3 vertex; // vec3 position

// out vec2 TexCoords;
// out vec4 ParticleColor;

// uniform mat4 projection;
// uniform vec2 offset;
// uniform vec4 color;

// void main() {
    // float scale = 10.0f;
    // TexCoords = vertex.xy;
    // ParticleColor = color;
    // gl_Position = projection * vec4((vertex.xy * scale) + offset, 0.0, 1.0);
// }

#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in vec4 color;

out vec3 Normal;
out vec2 TexCoords;
out vec3 FragPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform vec3 initialVelocity;
uniform float gravityScale;
uniform float elapsedTime;

void main() {
	
	Normal = mat3(inverse(transpose(model))) * normal;

	TexCoords = texCoords;
	
	
	

	const float gravity = -9.81;
	
	vec3 totalGravity = vec3(0, gravity * gravityScale, 0);
	
	vec3 calculatedPos = position  + (initialVelocity * elapsedTime + (totalGravity * elapsedTime * elapsedTime)/2);
	

	FragPosition = vec3(model * vec4(calculatedPos, 1.0f));

	gl_Position = proj * view * model * vec4(calculatedPos, 1.0f);
}