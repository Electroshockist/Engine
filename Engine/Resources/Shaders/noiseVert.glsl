#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in  vec2 texCoords;

out vec3 Normal;
out vec3 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform vec3 lightPos;
uniform float time;

uniform float noiseSpread;
uniform float noiseSpeed;
uniform float noiseHeight;

uniform sampler3D noise3D;

void main() {
	vec3 texPos = vec3(time) * noiseSpeed + aPos * noiseSpread;
	vec4 noise = (normalize(texture(noise3D, texPos)) - vec4(0.5)) * noiseHeight;
	vec3 randN = aNormal * noise.xyz;
	
	vec3 p = aPos + randN;
	
    Normal = mat3(transpose(inverse(model))) * aNormal;
    Position = vec3(model * vec4(p, 1.0));
    gl_Position = proj * view * model * vec4(p, 1.0);
}