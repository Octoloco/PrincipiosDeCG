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
float cirx1;
float ciry1;
float cirr1;

float cirx2;
float ciry2;
float cirr2;

float cirx3;
float ciry3;
float cirr3;

float cirx4;
float ciry4;
float cirr4;

float cirx5;
float ciry5;
float cirr5;

float cirx6;
float ciry6;
float cirr6;

float cirx7;
float ciry7;
float cirr7;

float cirx8;
float ciry8;
float cirr8;

float cirx9;
float ciry9;
float cirr9;

float cirx10;
float ciry10;
float cirr10;

float cirx11;
float ciry11;
float cirr11;

float cirx12;
float ciry12;
float cirr12;

float cirx13;
float ciry13;
float cirr13;

float cirx14;
float ciry14;
float cirr14;

float cirx15;
float ciry15;
float cirr15;




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


	
	midPointCircle(cirx1, ciry1, cirr1);
	midPointCircle(cirx2, ciry2, cirr2);
	midPointCircle(cirx3, ciry3, cirr3);
	midPointCircle(cirx4, ciry4, cirr4);
	midPointCircle(cirx5, ciry5, cirr5);
	midPointCircle(cirx6, ciry6, cirr6);
	midPointCircle(cirx7, ciry7, cirr7);
	midPointCircle(cirx8, ciry8, cirr8);
	midPointCircle(cirx9, ciry9, cirr9);
	midPointCircle(cirx10, ciry10, cirr10);
	midPointCircle(cirx11, ciry11, cirr11);
	midPointCircle(cirx12, ciry12, cirr12);
	midPointCircle(cirx13, ciry13, cirr13);
	midPointCircle(cirx14, ciry14, cirr14);
	midPointCircle(cirx15, ciry15, cirr15);




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
	
	cirx1 = rand() % (WIDTH - 0 + 1) + 0;
	ciry1 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr1 = rand() % (600 - 50 + 1) + 50;

	cirx2 = rand() % (WIDTH - 0 + 1) + 0;
	ciry2 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr2 = rand() % (600 - 50 + 1) + 50;

	cirx3 = rand() % (WIDTH - 0 + 1) + 0;
	ciry3 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr3 = rand() % (600 - 50 + 1) + 50;

	cirx4 = rand() % (WIDTH - 0 + 1) + 0;
	ciry4 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr4 = rand() % (600 - 50 + 1) + 50;

	cirx5 = rand() % (WIDTH - 0 + 1) + 0;
	ciry5 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr5 = rand() % (600 - 50 + 1) + 50;

	cirx6 = rand() % (WIDTH - 0 + 1) + 0;
	ciry6 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr6 = rand() % (600 - 50 + 1) + 50;

	cirx7 = rand() % (WIDTH - 0 + 1) + 0;
	ciry7 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr7 = rand() % (600 - 50 + 1) + 50;

	cirx8 = rand() % (WIDTH - 0 + 1) + 0;
	ciry8 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr8 = rand() % (600 - 50 + 1) + 50;

	cirx9 = rand() % (WIDTH - 0 + 1) + 0;
	ciry9 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr9 = rand() % (600 - 50 + 1) + 50;

	cirx10 = rand() % (WIDTH - 0 + 1) + 0;
	ciry10 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr10 = rand() % (600 - 50 + 1) + 50;

	cirx11 = rand() % (WIDTH - 0 + 1) + 0;
	ciry11 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr11 = rand() % (600 - 50 + 1) + 50;

	cirx12 = rand() % (WIDTH - 0 + 1) + 0;
	ciry12 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr12 = rand() % (600 - 50 + 1) + 50;

	cirx13 = rand() % (WIDTH - 0 + 1) + 0;
	ciry13 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr13 = rand() % (600 - 50 + 1) + 50;

	cirx14 = rand() % (WIDTH - 0 + 1) + 0;
	ciry14 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr14 = rand() % (600 - 50 + 1) + 50;

	cirx15 = rand() % (WIDTH - 0 + 1) + 0;
	ciry15 = rand() % (HEIGHT - 0 + 1) + 0;
	cirr15 = rand() % (600 - 50 + 1) + 50;
	
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
