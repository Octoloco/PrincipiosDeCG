#define _USE_MATH_DEFINES 

#include "Application.h"
#include <cmath>

void Application::update() {

}







void Application::draw() {


	for (int angulo = 0; angulo < 360; angulo++)
	{
		int x = 1000 * cos((angulo*3.1416) / 180);
		int y = 1000 * sin((angulo*3.1416) / 180);
		line(WIDTH / 2, HEIGHT / 2, x, y);
		
		

	}


	

	



	
	for (int i = 0; i < WIDTH; i++) {
		putPixel(i, HEIGHT/2,0,255,0,255);
	}
	for (int i = 0; i < WIDTH; i++) {
		putPixel(WIDTH/2, i, 0, 255, 0, 255);
	}

	for (int i = 0; i < WIDTH; i++) {
		putPixel(i, i, 0, 255, 0, 255);
	}
	for (int i = 0; i < WIDTH; i++) {
		putPixel(i*-1, i, 0, 255, 0, 255);
	}
	

}



void Application::setup() {

}


Application::Application()
{
	
	
}



Application::~Application()
{
}
