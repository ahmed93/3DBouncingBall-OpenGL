
#include "Constants.h"
#include <vector>
#ifndef OBJLOADER_H
#define OBJLOADER_H


bool loadOBJ(
	const char * path, 
	vector<vec3> & out_vertices,
	vector<vec2> & out_uvs,
	vector<vec3> & out_normals
);



bool loadAssImp(
	const char * path, 
	vector<unsigned short> & indices,
	vector<vec3> & vertices,
	vector<vec2> & uvs,
	vector<vec3> & normals
);

#endif