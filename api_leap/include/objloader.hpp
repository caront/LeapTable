#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <iostream>

bool loadOBJ(
	const char * path, 
	std::vector<glm::vec3> & out_vertices, 
	std::vector<glm::vec2> & out_uvs, 
	std::vector<glm::vec3> & out_normals
);


int LoadMesg(const char* inputFile, std::vector<std::vector<glm::vec3>> & out_vertices,std::vector < glm::vec2 > & out_uvs,std::vector < glm::vec3 > & out_normals);

#endif