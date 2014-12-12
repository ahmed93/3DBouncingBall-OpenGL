#version 330 core



layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 mM;    // Matrix for world coordinate
uniform mat4 mV;    // Matrix for camera coordinate
uniform mat4 mP;    // Matrix for prespective for depth


void main(){
    
    // Output position of the vertex, in clip space : MVP * position
    gl_Position = mP*mV*mM*vec4(vPosition,1);
    
    // UV of the vertex. No special space for this one.
    UV = vertexUV;
}