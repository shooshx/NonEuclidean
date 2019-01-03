//#version 150

//Globals
uniform mat4 mvp;
uniform mat4 mv;

//Inputs
attribute vec3 in_pos;
attribute vec3 in_uv;
attribute vec3 in_normal;

//Outputs
varying vec3 ex_uv;
varying vec3 ex_normal;

void main(void) {
	gl_Position = mvp * vec4(in_pos, 1.0);
	ex_uv = in_uv;
	ex_normal = normalize((mv * vec4(in_normal, 0.0)).xyz);
}
