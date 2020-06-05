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
#version 450 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 texCoords;
layout (location = 3) in vec3 colour;

out vec3 customColour;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform vec3 offset;
uniform vec3 initialVelocity;
uniform float gravityScale;
uniform float elapsedTime;

void main(){
	const float gravity = 9.81;
	
	const float totalGravity = gravity * gravityScale;
	
	vec3 calculatedPos = (position + offset) + (initialVelocity*elapsedTime + (totalGravity * elapsedTime * elapsedTime)/2);

	gl_Position = proj * view * model * vec4(calculatedPos, 1.0f);
	customColour = colour;
}