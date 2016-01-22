#version 330 
		
layout (location = 0) in vec3 vertPos; 
layout (location = 1) in vec2 tex; 
layout (location = 2) in vec3 normalIn; 
layout (location = 3) in vec3 causticNormal;
uniform mat4 viewMatrix, projMatrix; 
uniform float waveValue;
uniform int waveType;
out vec2 texcoords; 
out vec3 normal;
out float height;
out vec3 caustic;

void main(){ 
	vec3 newPos = vertPos;
	float typeValue = 0;
	
	if (waveType != 6) {
		switch (waveType) {
			case 0:
				// xAxis
				typeValue = newPos.x;
				break;
			case 1:
				// xAxisNeg
				typeValue = -newPos.x;
				break;
			case 2:
				// zAxis
				typeValue = newPos.z;
				break;
			case 3:
				// zAxisNeg
				typeValue = -newPos.z;
				break;
			case 4:
				// diagonal
				typeValue = newPos.x + newPos.z;
				break;
			case 5:
				// digonalNeg
				typeValue = -(newPos.x + newPos.z);
				break;
		}
		
		typeValue /= 10.0;
		
		newPos.y += sin(waveValue + typeValue)*5.0;	
	}
	
	gl_Position =  projMatrix * viewMatrix * vec4(newPos, 1.0); 
	texcoords = tex; 
	normal = normalize(normalIn);
	height = newPos.y;
	caustic = normalize(causticNormal);
}
