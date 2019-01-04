//#version 150

//Globals
uniform mat4 mvp;
uniform mat4 mv;

//Inputs
attribute vec3 in_pos;
attribute vec2 in_uv;

//Outputs
varying vec3 ex_normal;

void main(void) {
	gl_Position = vec4(in_pos.xy, 0.0, 1.0);
	vec3 eye_normal = normalize((mvp * gl_Position).xyz);
	ex_normal = normalize((mv * vec4(eye_normal, 0.0)).xyz);
} 
