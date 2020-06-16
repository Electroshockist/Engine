#version 450 core

layout (location = 0) in vec3 initialVelocity;
layout (location = 1) in float lifetime;

out vec2 ParticleUV;

uniform mat4 cameraMat;

uniform vec3 position;
uniform float elapsedTime;

//set consts
const vec2[] particle_quad = {
	vec2(-0.5f, -0.5f),
	vec2(0.5f, -0.5f),
	vec2(0.5f, 0.5f),
	vec2(-0.5f, 0.5f)
	
};

 const vec2[] particle_UV = {
	vec2(0,1),
	vec2(1,1),
	vec2(1,0),
	vec2(0,0)
};

void main(){
	uint particleID = uint(mod(gl_VertexID, 4));
	ParticleUV = particle_UV[particleID];
	
	const vec3 cameraRight = vec3(cameraMat[0][0], cameraMat[1][0], cameraMat[2][0]);
	const vec3 cameraUp = vec3(cameraMat[0][1], cameraMat[1][1], cameraMat[2][1]);	
	
	//calculate particle position
	float relativeTime = mod(elapsedTime, lifetime);
	vec3 displacement = initialVelocity * relativeTime;
	vec3 calculatedPos = position + displacement;
	
	//calculate the particle quad in worldspace
	vec3 particlePos = calculatedPos + cameraRight * particle_quad[particleID].x + cameraUp * particle_quad[particleID].y;
	
	gl_Position =  cameraMat * vec4(particlePos, 1.0f);
}