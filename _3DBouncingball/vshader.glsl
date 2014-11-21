#version 330 core

//in  vec3 vPosition;
in vec3 vPosition;
in  vec4 vColor;
out vec4 color;
uniform mat4 mM;    // Matrix for world coordinate
uniform mat4 mV;    // Matrix for camera coordinate
uniform mat4 mP;    // Matrix for prespective for depth

void main()
{
//    gl_Position = vec4(vPosition,1.0);
    gl_Position = mP*mV*mM*vec4(vPosition,1);
    color = vColor;
}
