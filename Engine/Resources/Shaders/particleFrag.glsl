#version 450 core

in vec3 Offset;
//in vec3 ParticleMat;

out vec4 color;

void main() {
	const vec4 fireColour = vec4(1.0f, 0.65f, 0.13f, 1.0f);
	const vec4 fadeColour = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	
	const vec4 mixed = mix(fireColour, fadeColour, Offset.y / 4);

	color = mixed;
}