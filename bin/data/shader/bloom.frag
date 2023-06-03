#version 150

uniform sampler2DRect tex0;
in vec2 texCoordVarying;
out vec4 fragColor;

const float BLOOM_THRESHOLD = 0.1;
const float BLOOM_INTENSITY = 15;
const int NUM_BLUR_SAMPLES = 10;

vec4 bloom(vec2 uv) {
    vec4 col = texture(tex0, uv);

    // Extract bright areas
    float brightness = max(col.r, max(col.g, col.b));
    float threshold = BLOOM_THRESHOLD;
    vec4 bloomColor = max((col - threshold) / (1.0 - threshold), 0.0);

    // Apply Gaussian blur
    vec2 size = textureSize(tex0);
    vec2 texelSize = 1.0 / size;

    for (int i = 0; i < NUM_BLUR_SAMPLES; ++i) {
        float scale = float(i) * 0.5;
        vec2 offset = scale * texelSize;

        bloomColor += texture(tex0, uv + offset);
        bloomColor += texture(tex0, uv - offset);
    }

    bloomColor /= float(NUM_BLUR_SAMPLES) * 2.0;

    // Add bloom to the original color
    col.rgb += bloomColor.rgb * BLOOM_INTENSITY;
    return col;
}

void main() {
    fragColor = bloom(texCoordVarying);
}

