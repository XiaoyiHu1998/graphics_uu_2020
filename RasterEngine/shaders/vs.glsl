#version 330
 
// shader input
in vec2 vUV;				// vertex uv coordinate
in vec3 vNormal;			// untransformed vertex normal
in vec3 vPosition;			// untransformed vertex position

// shader output
out vec4 normal;			// transformed vertex normal
out vec2 uv;	
out vec4 worldPosition;

uniform mat4 objectToScreen;
uniform mat4 objectToWorld;
 
// vertex shader
void main()
{
	// transform vertex using supplied matrix
	gl_Position = objectToScreen * vec4(vPosition, 1.0);
	worldPosition =	objectToWorld * vec4(vPosition, 1.0);

	// forward normal and uv coordinate; will be interpolated over triangle
	normal = objectToWorld * vec4( vNormal, 0.0f );
	uv = vUV;
}