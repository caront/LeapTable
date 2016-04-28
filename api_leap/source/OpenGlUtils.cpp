#include "OpenGlUtils.hpp"

OpenGlUtils::OpenGlUtils(sf::RenderWindow &window)
	: _window(window)
	{

	}

OpenGlUtils::~OpenGlUtils(){}

void 		OpenGlUtils::Setup()
{
	  _window.setVerticalSyncEnabled(true);
	  glEnable(GL_TEXTURE_2D);
	  glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
   GLfloat ratio = static_cast<float>(_window.getSize().x) / _window.getSize().y;
   glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
	glEnable(GL_DEPTH_TEST);                     // Enables Depth Testing
   glDepthFunc(GL_LEQUAL);                        // The Type Of Depth Testing To Do
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);     
}

sf::ContextSettings OpenGlUtils::GetSettings()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	return settings;
}

void OpenGlUtils::Clean(Object3D *obj)
{
	static int looptime = 0;
	sf::Clock clock;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
  	glLoadIdentity();                           
  	glTranslatef(-5.0f, 0.0f, -10.0f);       
  	glRotatef(looptime * 3.f, 0.f, 1.f, 0.f);
	looptime++;
    
}

void OpenGlUtils::Push()
{
	 _window.pushGLStates();
}

void OpenGlUtils::Pop()
{
	 _window.popGLStates();

}