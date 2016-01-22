#version 330

in vec2 texcoords;
uniform sampler2D texsampler;
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
    return abs(d1 - d2);
}

float getTexValue(vec2 texcoords, float xDiff, float yDiff) {
    return linearizeDepth(texture(texsampler, vec2(texcoords.x+xDiff, texcoords.y+yDiff)).x);
}

vec3 calcColor(vec3 baseColor, vec2 texcoords) {
    float pixelDiffX = 5.0 / 1920.0;
    float pixelDiffY = 5.0 / 1080.0;
    float thisPixel = linearizeDepth(texture(texsampler, texcoords).x);
    float diff = 0.0;

    //diff += colorDiff(thisPixel, getTexValue(texcoords, -pixelDiffX, 0));
    //diff += colorDiff(thisPixel, getTexValue(texcoords, +pixelDiffX, 0));
    //diff += colorDiff(thisPixel, getTexValue(texcoords, 0, -pixelDiffY));
    //diff += colorDiff(thisPixel, getTexValue(texcoords, 0, +pixelDiffY));

    int range = 10;

    for (int i = -range; i < range; i++) {
        for (int j = -range; j < range; j++) {
            diff += colorDiff(thisPixel, getTexValue(texcoords, i*pixelDiffX, j*pixelDiffY))/float(range*range);
        }
    }



    return mix(vec3(1.0), vec3(0.0), diff);

}

//
// Ganz normale Ansicht der jew. Tiefe.
//
//void main(){
//  Color = vec4(linearizeDepth(texture(texsampler, texcoords).x));
//}

//
// Hier mit Kantendetektion die Pixel um das aktuelle rum.
//
void main() {
    Color = vec4(calcColor(vec3(1.0, 1.0, 1.0), texcoords), 1.0);
}
