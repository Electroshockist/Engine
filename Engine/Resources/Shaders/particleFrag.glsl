#version 450 core

in vec2 ParticleUV;
uniform sampler2D image;

out vec4 color;

void main() {
	color = texture(image, ParticleUV);
}