#version 430 core
layout (location = 0) in vec3 aPos;

out vec3 outPos;

void main()
{
	outPos = aPos;
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}