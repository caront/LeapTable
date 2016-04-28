#include "Object3D.hpp"
#include "Log.hpp"


Object3D::Object3D(std::string tag, std::string file, sf::Vector3f coor, sf::Vector3f size)
	: _file(file){

}

Object3D::~Object3D(){

}

void Object3D::Init(){
    std::cout << LoadMesg(_file.c_str(), vertices, uvs, normals) << std::endl;
   	
    //bool res = loadOBJ(_file.c_str(), vertices, uvs, normals);
    //if (res == false)
      //  LOG("loadOBJ fail");
}

void Object3D::Rotate(sf::Vector3f add){
	coor += add;
}

void Object3D::Resize(sf::Vector3f add){
	size += add;
}

void Object3D::Draw(){
  for (unsigned i=0; i < vertices.size(); i++) 
   {
        std::vector<glm::vec3> vertexGroup = vertices[i];
        glBegin(GL_TRIANGLES);
            glVertex3f(vertexGroup[0].x,vertexGroup[0].y,vertexGroup[0].z);
            glVertex3f(vertexGroup[1].x,vertexGroup[1].y,vertexGroup[1].z);
            glVertex3f(vertexGroup[2].x,vertexGroup[2].y,vertexGroup[2].z);
        glEnd();
    }
}

std::string Object3D::getTag()
{
	return _tag;
}

void 		Object3D::setTag(std::string tag)
{
	_tag = tag;
}

void 		Object3D::setFile(std::string file)
{
	_file = file;
	Init();
}
