#version 330

layout (location = 0) in vec3 vertPos;
uniform mat4 viewMatrix, projMatrix;
out vec3 pos_vec;
out vec2 tex_pos;

void main(){
	
    vec4 screenPos = projMatrix * viewMatrix * vec4(vertPos, 1.0);
    gl_Position =  screenPos;
    vec3 tmp = screenPos.xyz / screenPos.w;
    tex_pos = ((tmp + vec3(1.0)) / 2.0).xy;
    pos_vec = vertPos;
}
