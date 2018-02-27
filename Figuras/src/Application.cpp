#define _USE_MATH_DEFINES 

#include "Application.h"
#include <cmath>

void Application::update() {

}







void Application::draw() {

	float cx = WIDTH / 2;
	float cy = HEIGHT / 2;

	/*for (int angulo = 0; angulo < 360; angulo++)
	{
		int x = 300 * cos((angulo*3.1416) / 180);
		int y = 300 * sin((angulo*3.1416) / 180);
		line(cx, cy, x + cx, y + cy);
		
		

	}*/


	Poligono(360);


	

	



	/*
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
	}*/
	

}



void Application::setup() {

}


Application::Application()
{
	
	
}



Application::~Application()
{
}
