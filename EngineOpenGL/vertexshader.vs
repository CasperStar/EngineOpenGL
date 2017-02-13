#version 330 core

layout(location = 0) in vec3 Position;

uniform mat4 gWorld;

void main()
{
    //gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z, 1.0);
    gl_Position = gWorld * vec4(Position, 1.0);
}
