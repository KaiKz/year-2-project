#version 150

in vec2 vtexcoord; // interpolant from vertex shader
out vec4 fragColor;

uniform sampler2D tex; // texture (ID) passed in from the CPU

void main(void){

	// The texture() function takes:
	//		a sampler as the first argument
	//		a texture (UV) coordinate as the second argument
	fragColor = texture(tex, vtexcoord);
}