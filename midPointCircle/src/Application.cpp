#define _USE_MATH_DEFINES 

#include "Application.h"
#include <cmath>




void Application::update() {
	
	
	/*vec4 vtemp(0,0,0);*/
	/*mat3 rot1;
	mat3 rot2;
	mat3 acum;
	mat3 trans1;
	mat3 trans2;
	mat3 trans3;
	angle += 4;
	angle2 -= 2;

	rot1 = rot1.rot(angle);
	rot2 = rot2.rot(angle2);

	trans1 = trans1.trans(0, 0);
	trans3 = trans3.trans(200, 200);
	trans2 = trans2.trans(WIDTH / 2 +cx, HEIGHT / 2 +cy);
	acum = rot1 * trans1;
	acum = trans3 * acum;
	acum = rot2 * acum;
	acum = trans2 * acum;
	for (int i = 0; i < v.size(); i++) {
		
		vcopy.push_back(vtemp);

	}*/


	//cubo(V);


	/*vec4 ups(0, 1, 0);
	vec4 eye(30, 30, 1);
	vec4 target(0, 0, 0);
	mat4 rota;
	mat4 per = mat4::persp(FOV, aspectRatio, farClip, nearClip);
	mat4 ca = mat4::cam(ups, eye, target);
	Vcopy.clear();
	
	rota = mat4::rotz(angle) * mat4::rotx(angle);
	rota = rota * mat4::rotz(angle);

	angle++;
	mat4 acum1 = per * ca;

	mat4 acum2 = acum1 * rota;


	for (int i = 0; i < V.size(); i++) {
		vtemp = acum2 * V[i];
		Vcopy.push_back(vtemp);
	}


}


void Application::clearScreen() {
	for (int i = 0; i <= WIDTH; i++) {
		for (int j = 0; j <= HEIGHT; j++) {
			putPixel(i, j, 0, 0, 0, 255);
		}
	}*/
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



	midPointCircle(cx, cy, 300);




	//triangle(vec3(0, -300), vec3(300, 300), vec3(-300, 300));

	/*clearScreen();
	for (int i = 0; i < Vcopy.size(); i += 3) {
		triangle(Vcopy[i], Vcopy[i + 1], Vcopy[i + 2]);
		
	}
	*/
	



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
	/*vec3 a(0, -300);
	vec3 b(300, 300);
	vec3 c(-300, 300);

	sierpinsky(a, b, c, 3);*/
	

	
	//Vcopy.push_back(vec4(-10, -10, 10));
	//Vcopy.push_back(vec4(-10, 10, 10));
	//Vcopy.push_back(vec4(10, 10, 10));
	//Vcopy.push_back(vec4(10, -10, 10));
	//Vcopy.push_back(vec4(10, -10, -10));
	//Vcopy.push_back(vec4(10, 10, -10));
	//Vcopy.push_back(vec4(-10, -10, -10));
	//Vcopy.push_back(vec4(-10, 10, -10));


	//	
	//	V.push_back(Vcopy[0]);
	//	V.push_back(Vcopy[1]);
	//	V.push_back(Vcopy[2]);
	//	//cara a, triangulo S
	//	V.push_back(Vcopy[0]);
	//	V.push_back(Vcopy[2]);
	//	V.push_back(Vcopy[3]);
	//	//cara b, triangulo I
	//	V.push_back(Vcopy[3]);
	//	V.push_back(Vcopy[2]);
	//	V.push_back(Vcopy[5]);
	//	//cara b, triangulo S
	//	V.push_back(Vcopy[3]);
	//	V.push_back(Vcopy[5]);
	//	V.push_back(Vcopy[4]);
	//	//cara c, triangulo I
	//	V.push_back(Vcopy[5]);
	//	V.push_back(Vcopy[4]);
	//	V.push_back(Vcopy[6]);
	//	//cara c, triangulo S
	//	V.push_back(Vcopy[5]);
	//	V.push_back(Vcopy[6]);
	//	V.push_back(Vcopy[7]);
	//	//cara d, triangulo I
	//	V.push_back(Vcopy[7]);
	//	V.push_back(Vcopy[6]);
	//	V.push_back(Vcopy[0]);
	//	//cara d, triangulo S
	//	V.push_back(Vcopy[7]);
	//	V.push_back(Vcopy[1]);
	//	V.push_back(Vcopy[0]);
	//	//ara e, triangulo I
	//	V.push_back(Vcopy[0]);
	//	V.push_back(Vcopy[7]);
	//	V.push_back(Vcopy[6]);
	//	//ara e, triangulo S
	//	V.push_back(Vcopy[0]);
	//	V.push_back(Vcopy[3]);
	//	V.push_back(Vcopy[4]);
	//	//ara f, triangulo I
	//	V.push_back(Vcopy[5]);
	//	V.push_back(Vcopy[7]);
	//	V.push_back(Vcopy[1]);
	//	//ara f, triangulo S
	//	V.push_back(Vcopy[5]);
	//	V.push_back(Vcopy[2]);
	//	V.push_back(Vcopy[1]);

	 //Vcubo(V);
}


Application::Application()
{
	
	
}



Application::~Application()
{
}
