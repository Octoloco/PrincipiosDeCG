#include "Application.h"


void Application::update() {

}

void Application::draw() {
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
