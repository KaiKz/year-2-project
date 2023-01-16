#version 150

// Vertex attributes passed in by OF
in vec4 position;
in vec2 texcoord;
out vec2 vtexcoord; // to fragment shader

// This is passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;

void main (void){
	vtexcoord = texcoord;
	// vtexcoord *= 2.; // do any per-vertex texcoord operations here
    gl_Position = modelViewProjectionMatrix * position;
}
