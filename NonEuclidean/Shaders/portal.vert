//#version 150

//Globals
uniform mat4 mvp;

//Inputs
attribute vec3 in_pos;
attribute vec2 in_uv;

//Outputs
varying vec4 ex_uv;

void main(void) {
	gl_Position = mvp * vec4(in_pos, 1.0);
	ex_uv = gl_Position;
}
