#ifndef __3D_OBJECT_H__
#define __3D_OBJECT_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <fstream>
#include <sstream>
#include "objloader.hpp"


class Object3D
{
public:
	sf::Vector3f 	coor;
	
private:

	sf::Vector3f 	size;
	std::string 	_tag;
	std::string 	_file;

	std::vector<std::vector<glm::vec3>> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
 

public:
	Object3D(std::string tag, std::string file, sf::Vector3f coor, sf::Vector3f size);
	~Object3D();

	void Init();

	void Rotate(sf::Vector3f add);

	void Resize(sf::Vector3f add);

	void Draw();

	std::string getTag();
	void 		setTag(std::string file);

	void 		setFile(std::string file);
	
};

#endif