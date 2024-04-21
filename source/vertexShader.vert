#version 330 core

#define maxLights 10

// Input vertex data
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;

// Output data
out vec2 UV;
out vec3 fragmentPosition;

// Uniforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Output vertex position
    gl_Position = projection * view * model * vec4(position, 1.0);
    
    // Output (u,v) co-ordinates
    UV = uv;
}
