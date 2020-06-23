#version 330
 
// shader input
in vec2 uv;						// interpolated texture coordinates
in vec4 normal;					// interpolated normal
in vec4 worldPosition;
uniform sampler2D pixels;		// texture sampler

// shader output
out vec4 outputColor;

uniform mat4 objectToWorld;

uniform vec3 ambientLightColor;

uniform vec3 lightPosition0;
uniform vec3 lightColor0;

uniform vec3 lightPosition1;
uniform vec3 lightColor1;

uniform vec3 lightPosition2;
uniform vec3 lightColor2;

uniform vec3 lightPosition3;
uniform vec3 lightColor3;

// fragment shader
void main()
{
    vec3 materialColor = texture(pixels, uv).xyz;
    
    vec3 lightPosition0 = vec4(objectToWorld * vec4(lightPosition0, 1)).xyz;
    vec3 lightPosition1 = vec4(objectToWorld * vec4(lightPosition1, 1)).xyz;
    vec3 lightPosition2 = vec4(objectToWorld * vec4(lightPosition2, 1)).xyz;
    vec3 lightPosition3 = vec4(objectToWorld * vec4(lightPosition3, 1)).xyz;

    vec3 lightVector0 = lightPosition0 - worldPosition.xyz;
    float lightDistance0 = lightVector0.length();
    lightVector0 = normalize(lightVector0);
    float lightAttenuation0 = 1.0f / (lightDistance0 * lightDistance0);

    vec3 lightVector1 = lightPosition1 - worldPosition.xyz;
    float lightDistance1 = lightVector1.length();
    lightVector1 = normalize(lightVector1);
    float lightAttenuation1 = 1.0f / (lightDistance1 * lightDistance1);

    vec3 lightVector2 = lightPosition2 - worldPosition.xyz;
    float lightDistance2 = lightVector2.length();
    lightVector2 = normalize(lightVector2);
    float lightAttenuation2 = 1.0f / (lightDistance2 * lightDistance2);
    
    vec3 lightVector3 = lightPosition3 - worldPosition.xyz;
    float lightDistance3 = lightVector3.length();
    lightVector3 = normalize(lightVector3);
    float lightAttenuation3 = 1.0f / (lightDistance3 * lightDistance3);
    
    vec3 totalDiffuseLightColor = materialColor * max(0.0f, dot(lightVector0, normal.xyz)) * lightAttenuation0 * lightColor0
                                + materialColor * max(0.0f, dot(lightVector1, normal.xyz)) * lightAttenuation1 * lightColor1
                                + materialColor * max(0.0f, dot(lightVector2, normal.xyz)) * lightAttenuation2 * lightColor2
                                + materialColor * max(0.0f, dot(lightVector3, normal.xyz)) * lightAttenuation3 * lightColor3;
                            
    vec3 reflectionVector0 = 2 * (lightVector0 * normal.xyz) * normal.xyz - lightVector0;
    vec3 reflectionVector1 = 2 * (lightVector1 * normal.xyz) * normal.xyz - lightVector1;
    vec3 reflectionVector2 = 2 * (lightVector2 * normal.xyz) * normal.xyz - lightVector2;
    vec3 reflectionVector3 = 2 * (lightVector3 * normal.xyz) * normal.xyz - lightVector3;

    float alpha = 3f;
    vec3 specularColor = vec3(1,1,1);
    vec3 totalSpecularLightColor = specularColor * pow(dot(lightVector0, reflectionVector0), alpha) * lightAttenuation0 * lightColor0
                                 + specularColor * pow(dot(lightVector1, reflectionVector1), alpha) * lightAttenuation1 * lightColor1
                                 + specularColor * pow(dot(lightVector2, reflectionVector2), alpha) * lightAttenuation2 * lightColor2
                                 + specularColor * pow(dot(lightVector3, reflectionVector3), alpha) * lightAttenuation3 * lightColor3;
                                 
    totalSpecularLightColor.x = max(0.0f, totalSpecularLightColor.x);
    totalSpecularLightColor.y = max(0.0f, totalSpecularLightColor.y);
    totalSpecularLightColor.z = max(0.0f, totalSpecularLightColor.z);



    outputColor = vec4(
                2 * totalDiffuseLightColor
                + vec3(ambientLightColor.x * materialColor.x, ambientLightColor.y * materialColor.y, ambientLightColor.z * materialColor.z)
                + totalSpecularLightColor
                , 1
    );
}