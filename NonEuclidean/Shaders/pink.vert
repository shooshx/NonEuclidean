//#version 150

//Globals
uniform mat4 mvp;

//Inputs
attribute vec3 in_pos;
attribute vec2 in_uv;

void main(void) {
	gl_Position = mvp * vec4(in_pos, 1.0);
}
