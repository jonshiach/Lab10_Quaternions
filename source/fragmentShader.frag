#version 330 core

#define maxLights 10

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 fragmentPosition;

// Output data
out vec3 fragmentColour;

// Uniforms
uniform sampler2D diffuseMap;

void main ()
{
    // Loop through the point light sources
    fragmentColour = texture(diffuseMap, UV).rgb;
    
}
