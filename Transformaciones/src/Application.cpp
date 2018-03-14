#define _USE_MATH_DEFINES 

#include "Application.h"
#include <cmath>

void Application::update() {
	
	vcopy.clear();
	vec3 vtemp(0,0);
	mat3 rot1;
	mat3 rot2;
	mat3 acum;
	mat3 trans1;
	mat3 trans2;
	mat3 trans3;
	angle += 1;

	rot1 = rot1.rot(angle);
	rot2 = rot2.rot(angle+5);

	trans1 = trans1.trans(0, 0);
	trans3 = trans3.trans(200, 200);
	trans2 = trans2.trans(WIDTH / 2 +cx, HEIGHT / 2 +cy);
	acum = rot1 * trans1;
	acum = trans3 * acum;
	acum = rot2 * acum;
	acum = trans2 * acum;
	for (int i = 0; i < v.size(); i++) {
		vtemp = acum * v[i];
		vcopy.push_back(vtemp);

	}



}


void Application::clearScreen() {
	for (int i = 0; i <= WIDTH; i++) {
		for (int j = 0; j <= HEIGHT; j++) {
			putPixel(i, j, 0, 0, 0, 255);
		}
	}
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


	//Poligono(4);

	//triangle(vec3(0, -300), vec3(300, 300), vec3(-300, 300));

	clearScreen();
	for (int i = 0; i < vcopy.size(); i += 3) {
		triangle(vcopy[i], vcopy[i + 1], vcopy[i + 2]);
		
	}
	
	



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
	vec3 a(0, -300);
	vec3 b(300, 300);
	vec3 c(-300, 300);

	sierpinsky(a, b, c, 3);
}


Application::Application()
{
	
	
}



Application::~Application()
{
}
