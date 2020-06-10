#version 450 core

layout (location = 0) in vec3 initialVelocity;
layout (location = 1) in float lifetime;

out vec3 Offset;
out mat4 ParticleMat;

uniform mat4 view;
uniform mat4 proj;

uniform vec3 position;
uniform float elapsedTime;

uniform sampler2D texture;

void main() {
	//set consts
	const vec2[] particle_quad = {
		vec2(-0.5f, -0.5f),
		vec2(0.5f, -0.5f),
		vec2(-0.5f, 0.5f),
		vec2(0.5f, 0.5f)
	};
	
	const mat4 totalView = view * proj;
	
	const vec3 cameraRight = vec3(totalView[0][0], totalView[1][0], totalView[2][0]);
	const vec3 cameraUp = vec3(totalView[0][1], totalView[1][1], totalView[2][1]);	
	
	
	//calculate particle position
	float relativeTime = mod(elapsedTime, lifetime);
	
	Offset = initialVelocity * relativeTime;
	
	vec3 calculatedPos = position + Offset;	
	
	//calculate the particle quad in worldspace
	ParticleMat = mat4(
		vec4(calculatedPos + cameraRight * particle_quad[0].x + cameraUp * particle_quad[0].y, 0),
		vec4(calculatedPos + cameraRight * particle_quad[1].x + cameraUp * particle_quad[1].y, 0),
		vec4(calculatedPos + cameraRight * particle_quad[2].x + cameraUp * particle_quad[2].y, 0),
		vec4(calculatedPos + cameraRight * particle_quad[3].x + cameraUp * particle_quad[3].y, 0),
	);
	

	gl_Position = totalView * vec4(calculatedPos, 1.0f);
}