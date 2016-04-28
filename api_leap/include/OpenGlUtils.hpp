#ifndef __OPENGL_UTILS_H__
#define __OPENGL_UTILS_H__ 

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Object3D.hpp"


class OpenGlUtils
{
private:
	sf::RenderWindow 	&_window;

public:
	OpenGlUtils(sf::RenderWindow &window);
	~OpenGlUtils();

	void Setup();

	static void Clean(Object3D *obj);

	static void Draw();

	static sf::ContextSettings GetSettings();

	void Push();
	void Pop();
	
};

#endif