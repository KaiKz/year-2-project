#version 150

uniform sampler2DRect tex0;
uniform float blurAmount;
uniform vec2 resolution;

in vec2 vTexCoord;

out vec4 fragColor;

const float pi = 3.14159265;

vec4 blur(vec2 uv) {
    vec4 col = vec4(0.0);
    float total = 0.0;
    int samples = 5;
    float sigma = blurAmount * 0.5;
    
    for (int x = -samples; x <= samples; x++) {
        for (int y = -samples; y <= samples; y++) {
            float weight = (1.0 / (2.0 * pi * sigma * sigma)) * exp(-(float(x * x + y * y) / (2.0 * sigma * sigma)));
            col += texture(tex0, uv + vec2(x, y)) * weight;
            total += weight;
        }
    }
    return col / total;
}

void main() {
    vec2 uv = vTexCoord;
    fragColor = blur(uv);
}
