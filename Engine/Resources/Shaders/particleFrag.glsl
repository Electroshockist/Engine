// #version 330 core
// in vec2 TexCoords;
// in vec4 ParticleColor;
// out vec4 color;

// uniform sampler2D sprite;

// void main()
// {
    // color = vec4(1);//(texture(sprite, TexCoords) * ParticleColor);
// } 
#version 450 core

in vec3 customColour;

out vec4 color;

void main(){
	color = vec4(customColour, 1.0f);
}
