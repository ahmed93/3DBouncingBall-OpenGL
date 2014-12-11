//
//  Sphere.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/25/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Sphere.h"
#include <vector>

void Sphere::create(float Radius, int Resolution){
    double PI = 3.14159;
    
    
    // vectors to hold our data
    // vertice positions
    vector<vec3> v;
    // texture map
    vector<vec2> t;
    // normals
    vector<vec3> n;
    
    // iniatiate the variable we are going to use
    float X1,Y1,X2,Y2,Z1,Z2;
    float inc1,inc2,inc3,inc4,inc5,Radius1,Radius2;
    
    for(int w = 0; w < Resolution; w++) {
        for(int h = (-Resolution/2); h < (Resolution/2); h++){
            
            
            inc1 = (w/(float)Resolution)*2*PI;
            inc2 = ((w+1)/(float)Resolution)*2*PI;
            
            inc3 = (h/(float)Resolution)*PI;
            inc4 = ((h+1)/(float)Resolution)*PI;
            
            
            X1 = sin(inc1);
            Y1 = cos(inc1);
            X2 = sin(inc2);
            Y2 = cos(inc2);
            
            // store the upper and lower radius, remember everything is going to be drawn as triangles
            Radius1 = Radius*cos(inc3);
            Radius2 = Radius*cos(inc4);
            
            
            
            
            Z1 = Radius*sin(inc3);
            Z2 = Radius*sin(inc4);
            
            // insert the triangle coordinates
            v.push_back(vec3(Radius1*X1,Z1,Radius1*Y1));
            v.push_back(vec3(Radius1*X2,Z1,Radius1*Y2));
            v.push_back(vec3(Radius2*X2,Z2,Radius2*Y2));
            
            
            
            v.push_back(vec3(Radius1*X1,Z1,Radius1*Y1));
            v.push_back(vec3(Radius2*X2,Z2,Radius2*Y2));
            v.push_back(vec3(Radius2*X1,Z2,Radius2*Y1));
            
            
            // insert the texture map, im using this to draw texture out from a texture atlas,
            // so you probably want to write your own algorithm for this!
//            t.push_back(vec2(0.6666f, 0.5f)*vec2(1,0.25f)+vec2(0,0.25f*Type));
//            t.push_back(vec2(0.666f, 1.0f)*vec2(1,0.25f)+vec2(0,0.25f*Type));
//            t.push_back(vec2(1.0f, 1.0f)*vec2(1,0.25f)+vec2(0,0.25f*Type));
//            
//            
//            t.push_back(vec2(0.6666f, 0.5f)*vec2(1,0.25f)+vec2(0,0.25f*Type));
//            t.push_back(vec2(1.00f, 1.0f)*vec2(1,0.25f)+vec2(0,0.25f*Type));
//            t.push_back(vec2(1.00f, 0.5f)*vec2(1,0.25f)+vec2(0,0.25f*Type));
//            
            // insert the normal data
            n.push_back(vec3(X1,Z1,Y1)/ length(vec3(X1,Z1,Y1)));
            n.push_back(vec3(X2,Z1,Y2)/ length(vec3(X2,Z1,Y2)));
            n.push_back(vec3(X2,Z2,Y2)/ length(vec3(X2,Z2,Y2)));
            n.push_back(vec3(X1,Z1,Y1)/ length(vec3(X1,Z1,Y1)));
            n.push_back(vec3(X2,Z2,Y2)/ length(vec3(X2,Z2,Y2)));
            n.push_back(vec3(X1,Z2,Y1)/ length(vec3(X1,Z2,Y1)));
        }
        
    }
    
    
    // finally, create the buffers and bind the data to them
    vector<unsigned short> indices;
    vector<vec3> indexed_vertices;
    vector<vec2> indexed_uvs;
    vector<vec3> indexed_normals;
//    indexVBO(v, t, n, indices, indexed_vertices, indexed_uvs, indexed_normals);
    
    
//    glGenBuffers(1, &vertexbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(vec3), &indexed_vertices[0], GL_STATIC_DRAW);
//    
//    
//    glGenBuffers(1, &uvbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
//    glBufferData(GL_ARRAY_BUFFER, indexed_uvs.size() * sizeof(vec2), &indexed_uvs[0], GL_STATIC_DRAW);
//    
//    
//    glGenBuffers(1, &normalbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
//    glBufferData(GL_ARRAY_BUFFER, indexed_normals.size() * sizeof(vec3), &indexed_normals[0], GL_STATIC_DRAW);
//    
//    // Generate a buffer for the indices as well 
//    glGenBuffers(1, &elementbuffer);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);
//    
    // store the number of indices for later use
//    size = indices.size();
    
    // clean up after us
    indexed_normals.clear();
    indexed_uvs.clear();
    indexed_vertices.clear();
    indices.clear();
    n.clear();
    v.clear();
    t.clear();
}