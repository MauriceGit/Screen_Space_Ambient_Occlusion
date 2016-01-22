#version 330

in vec3 pos_vec;
in vec2 tex_pos;
uniform sampler2D texsampler;
uniform sampler2D texsamplerDepth;
uniform mat4 viewMatrix, projMatrix;
uniform int showTexture;
uniform int screenWidth, screenHeight;
uniform float nearPlane, farPlane;

uniform float multiplier;
uniform int range;
uniform int pixelDistance;

out vec4 Color;

float linearizeDepth (float depth) {
    float nearPlane = 0.5, farPlane = 50.0;
    return (2*nearPlane) / (farPlane + nearPlane - depth * (farPlane - nearPlane));
}

float linearizeDepthExtreme (float depth) {
    float nearPlane = 0.5, farPlane = 50.0;
    float res = (2*nearPlane) / (farPlane + nearPlane - depth * (farPlane - nearPlane));
    res = (res+0.3)*(res+0.3) - 0.5;
    return res;
}

float colorDiff(float d1, float d2) {
    return d1 - d2;
}
float getTexValue(vec2 texcoords, float xDiff, float yDiff) {
    return linearizeDepthExtreme(texture(texsamplerDepth, vec2(texcoords.x+xDiff, texcoords.y+yDiff)).x);
}
vec3 calcColor(vec2 texcoords) {
    float pixelDiffX = float(pixelDistance) / screenWidth;
    float pixelDiffY = float(pixelDistance) / screenHeight;
    float thisPixel = linearizeDepthExtreme(texture(texsamplerDepth, texcoords).x);
    float diff = 0.0;
    
    int count = 0;

    for (int i = -range; i < range; i++) {
        for (int j = -range; j < range; j++) {
			float value = getTexValue(texcoords, i*pixelDiffX, j*pixelDiffY);
			if (thisPixel > value) {
				diff += colorDiff(thisPixel, value);
				count++;
			}
        }
    }
    diff /= float(range*range*4);
    
    if (count < 4/5 * (range*range*4)) {
		diff = 0.0;
	}
	
    switch (showTexture) {
        case 0:
            return mix(texture(texsampler, texcoords).rgb, vec3(0.0), diff*multiplier);
        case 1:
            return mix(vec3(1.0), vec3(0.0), diff*multiplier);
        case 2:
            return texture(texsampler, texcoords).rgb;
    }
	return texture(texsampler, texcoords).rgb;
}

void main(){
    Color = vec4(calcColor(tex_pos), 1.0);
}
