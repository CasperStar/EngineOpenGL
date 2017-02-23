#version 330 core

layout (location = 0) in vec3 Position;

uniform mat4 MVP;

void main()
{
    //gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z, 1.0); // Basic
    
    gl_Position = MVP * vec4(Position, 1.0);
}
