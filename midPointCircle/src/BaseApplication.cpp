//

//  HelloCube

//

//  Created by Pedro  Cervantes Pintor on 11/Oct/14.

//
#define GLM_FORCE_RADIANS
#define _USE_MATH_DEFINES
#include "BaseApplication.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GLFW\glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "ShaderFuncs.h"




void BaseApplication::midPointCircle(float cx, float cy, float r) {

	float xc = 0;
	float yc = r;
	float d = 1 - r;

	while (xc < yc) {
		putPixel(xc + cx, yc + cy, 0, 255, 0, 255);
		putPixel(yc + cx, xc + cy, 0, 255, 0, 255);
		putPixel(xc + cx, -yc + cy, 0, 255, 0, 255);
		putPixel(-yc + cx, xc + cy, 0, 255, 0, 255);



		putPixel(-xc + cx, yc + cy, 0, 255, 0, 255);
		putPixel(yc + cx, -xc + cy, 0, 255, 0, 255);
		putPixel(-xc + cx, -yc + cy, 0, 255, 0, 255);
		putPixel(-yc + cx, -xc + cy, 0, 255, 0, 255);

		
		if (d < 0) {
			d += (2 * xc) + 3;
		}
		else {
			--yc;
			d += 2 * xc - 2 * yc + 5;
		}
		++xc;

	}


}



void BaseApplication::cubo(std::vector<vec4> vectorin) {

	vec4 ups(0,1,0);
	vec4 eye(2,5,2);
	vec4 target(0,0,0);
	mat4 rota;

	rota = rota.rotx(90);
	
	mat4 acum1 = acum1.persp(FOV, aspectRatio, farClip, nearClip) * acum1.cam(ups, eye, target);

	mat4 acum2 = acum1 * rota;


	for (int i = 0; i < vectorin.size(); i++) {
		vectorin[i] = rota * vectorin[i];
	}
	
}



void BaseApplication::line(const float& x0, const float& y0, const float& x1, const float& y1) {

	

	int dx = (int)(x1 - x0);
	int dy = (int)(y1 - y0);

	int step = 2 * dy - dx;
	//int dS = 2 * dy;
	//int dE = 2 * dx;
	//int dN = -dS;
	//int dO = -dE;
	//int dSO = dS + dO;
	//int dSE = dS + dE;
	//int dNE = -dSE;
	//int dNO = -dSO;

	putPixel((int)x0, (int)y0,255,0,0,255);
	int y = (int)y0, x = (int)x0;

	// The difference is lower in y
	if (abs(dy) <= abs(dx)) {
		// Is decreasing in x and decreasing in y
		if (x0 < x1) {
			if (y0 < y1) {
				//color = Color(255, 0, 0, 255); // RED
				dx = (int)(2 * dy);                        // S
				dy = (int)(2 * (y1 - y0) - 2 * (x1 - x0)); // SW
				while (x <= x1) {
					x++;
					if (step < 0) {
						step += dx;
					}
					else { step += dy; y++; }
					putPixel(x, y, 255, 0, 0, 255);
				}
				// Is decreasing in x and increasing in y :: y >= y1
			}
			else {
				//color = Color(255, 150, 0, 255); // ORANGE
				dx = (int)(2 * dy);                        // S
				dy = (int)(2 * (y1 - y0) + 2 * (x1 - x0)); // SE
				while (x <= x1) {
					x++;
					if (step >= 0) {
						step += dx;
					}
					else { step += dy; y--; }
					putPixel(x, y, 255, 0, 0, 255);
				}
			}
		}
		else {
			// Is increasing in x and decreasing in y
			if (y0 >= y1) {
				//color = Color(0, 255, 0, 255); // GREEN
				dx = (int)(-2 * dy);                        // N
				dy = (int)(-2 * (y1 - y0) + 2 * (x1 - x0)); // NW
				while (x > x1) {
					x--;
					if (step < 0) {
						step += dx;
					}
					else { step += dy; y--; }
					putPixel(x, y, 255, 0, 0, 255);
				}
				// Is increasing in x and increasing in y
				// y >= y1
			}
			else {
				//color = Color(0, 150, 255, 255); // CYAN
				dx = (int)(-2 * dy);                        // N
				dy = (int)(-2 * (y1 - y0) - 2 * (x1 - x0)); // NE
				while (x > x1) {
					x--;
					if (step >= 0) {
						step += dx;
					}
					else { step += dy; y++; }
					putPixel(x, y, 255, 0, 0, 255);
				}
			}
		}
		// The difference is lower in x
	}
	else {
		// Is decreasing in y and decreasing in x
		if (y0 < y1) {
			if (x0 < x1) {
				//color = Color(150, 0, 255, 255); // VIOLET
				dx = (int)(-2 * dx);                        // W
				dy = (int)(2 * (y1 - y0) - 2 * (x1 - x0));  // SW
				while (y <= y1) {
					y++;
					if (step >= 0) {
						step += dx;
					}
					else { step += dy; x++; }
					putPixel(x, y, 255, 0, 0, 255);
				}
				// Is decreasing in y and increasing in x
				// x >= x1
			}
			else {
				//color = Color(0, 0, 255, 255); // BLUE
				dx = (int)(-2 * dx);                        // W
				dy = (int)(-2 * (y1 - y0) - 2 * (x1 - x0)); // NE
				while (y <= y1) {
					y++;
					if (step < 0) {
						step += dx;
					}
					else { step += dy; x--; }
					putPixel(x, y, 255, 0, 0, 255);
				}
			}
		}
		else {
			// Is increasing in y and decreasing in x
			if (x0 >= x1) {
				//color = Color(255, 255, 150, 255); // LIME
				dx = (int)(2 * dx);                         // E
				dy = (int)(-2 * (y1 - y0) + 2 * (x1 - x0)); // NW
				while (y > y1) {
					y--;
					if (step >= 0) {
						step += dx;
					}
					else { step += dy; x--; }
					putPixel(x, y, 255, 0, 0, 255);
				}
				// Is increasing in y and increasing in x
				// x >= x1
			}
			else {
				//color = Color(255, 255, 0, 255); // YELLOW
				dx = (int)(2 * dx);                        // E
				dy = (int)(2 * (y1 - y0) + 2 * (x1 - x0)); // SE
				while (y > y1) {
					y--;
					if (step < 0) {
						step += dx;
					}
					else { step += dy; x++; }
					putPixel(x, y, 255, 0, 0, 255);
				}
			}
		}
	}


	
}



void BaseApplication::triangle(vec4 a, vec4 b, vec4 c) {

	MoveTo(a.x(), a.y());
	LineTo(b.x(), b.y());
	LineTo(c.x(), c.y());
	LineTo(a.x(), a.y());


}

vec3 BaseApplication::midpoint(vec3 A, vec3 B) {

	return vec3((A.x() + B.x()) / 2, (A.y() + B.y()) / 2);

}


void BaseApplication::sierpinsky(vec3 a, vec3 b, vec3 c, int n) {
	if (n == 0) {
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
	}
	else {
		vec3 ab = midpoint(a, b);
		vec3 bc = midpoint(b, c);
		vec3 ac = midpoint(a, c);

		sierpinsky(a, ab, ac, n - 1);
		sierpinsky(b, ab, bc, n - 1);
		sierpinsky(c, ac, bc, n - 1);
	}



}




void BaseApplication::Poligono(int numL) {
	int angulo = 360;

	int numeroLados = numL;

	angulo = angulo / numeroLados;

	for (int i = 0; i <= 360; i += angulo) {
		
		//MoveTo(i);

		//LineTo(numL);

	}
}

void BaseApplication::MoveTo(int x, int y) {
	xG = x;
	yG = y;
}

void BaseApplication::LineTo(int x, int y) {

	
		line(xG + cx, yG + cy, x + cx, y + cy);
		xG = x;
		yG = y;
	
}



BaseApplication::BaseApplication() : vEye(0.0f, 50.0f, 100.0f),
							_drawMode (0),
							shader(0),
							_currentBuffer(0),
							_nextBuffer(1)
							
{
}

BaseApplication::~BaseApplication()
{
	glDeleteTextures(2, texturesID);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(2, pboID);
}

void BaseApplication::initTextures()
{
	glGenTextures(2, texturesID);
	//Textura 0
	glBindTexture(GL_TEXTURE_2D, texturesID[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, Buffers[0]);

	//Sin promediar
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//Textura 1
	glBindTexture(GL_TEXTURE_2D, texturesID[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, Buffers[1]);

	//Sin promediar
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	

}

void BaseApplication::initPBOs()
{
	// create 2 pixel buffer objects, you need to delete them when program exits.
	// glBufferData with NULL pointer reserves only memory space.
	glGenBuffers(2, pboID);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[0]);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, WIDTH * HEIGHT * RGBA, 0, GL_STREAM_DRAW);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[1]);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, WIDTH * HEIGHT * RGBA, 0, GL_STREAM_DRAW);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}


void BaseApplication::init()
{
	fakeBuffers();
	initTextures();
	initPBOs();
	GLfloat vertices[]
	{
		//triangulo 0


		-1.0f, -1.0f, 0.0f, 1.0f,

		1.0f, -1.0f, 0.0f, 1.0f,

		-1.0f, 1.0f, 0.0f, 1.0f,

		//triangulo2
		//-1.0f, 1.0f, 0.0f, 1.0f,

		//1.0f, -1.0f, 0.0f, 1.0f,

		1.0f, 1.0f, 0.0f, 1.0f,
	};
	GLfloat texCoords[] 
	{
		0.0f, 1.0f, 0.0f, 0.0f,  //TEX
		1.0f, 1.0f, 0.0f, 0.0f,//TEX
		0.0f, 0.0f, 0.0f, 0.0f, //TEX

		1.0f, 0.0f, 0.0f, 0.0f//TEX

		//0.0f, 1.0f, 0.0f, 0.0f,//TEX
		//1.0f, 0.0f, 0.0f, 0.0f,//TEX
	};

	vEye = glm::vec3(0.0f, 50.0f, 50.0f);

	std::string sVertex, sFragment;
	sVertex = loadTextFile("shaders/passThru.v");
	sFragment = loadTextFile("shaders/passThru.f");
	InitializeProgram(shaderID, sVertex, sFragment);
	
	uTransform = glGetUniformLocation(shaderID, "mTransform");
	sampler = glGetUniformLocation(shaderID, "theTexture");

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(texCoords), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(texCoords), texCoords);
	
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(vertices)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	setup();
}


void BaseApplication::display()
{
	processPBO();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUseProgram(shaderID);

	mProjectionMatrix = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f);
	mTransform = glm::mat4(1.0f) * mProjectionMatrix;

	glUniformMatrix4fv(uTransform, 1, GL_FALSE, glm::value_ptr(mTransform));

	//pasamos parametros de textura
	glBindTexture(GL_TEXTURE_2D, texturesID[_currentBuffer]);
	glUniform1i(sampler, _currentBuffer);
	glActiveTexture(_currentBuffer==0? GL_TEXTURE0 : GL_TEXTURE1);
	//glActiveTexture(GL_TEXTURE0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	swapbuffers();
}

void BaseApplication::processPBO()
{
	// bind the texture and PBO
	glBindTexture(GL_TEXTURE_2D, texturesID[_currentBuffer]); //solo se necesita una textura
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[_currentBuffer]);

	// copy pixels from PBO to texture object
	// Use offset instead of pointer.
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, WIDTH, HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, 0);


	// bind PBO to update texture source
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[_nextBuffer]);

	// Note that glMapBufferARB() causes sync issue.
	// If GPU is working with this buffer, glMapBufferARB() will wait(stall)
	// until GPU to finish its job. To avoid waiting (idle), you can call
	// first glBufferDataARB() with NULL pointer before glMapBufferARB().
	// If you do that, the previous data in PBO will be discarded and
	// glMapBufferARB() returns a new allocated pointer immediately
	// even if GPU is still working with the previous data.
	glBufferData(GL_PIXEL_UNPACK_BUFFER, WIDTH * HEIGHT * RGBA, 0, GL_STREAM_DRAW);

	// map the buffer object into client's memory

	_screenBuffer = (GLubyte*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_READ_WRITE);
	if (_screenBuffer)
	{
		// update data directly on the mapped buffer
		//updatePixels(ptr);
		draw();
		glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER); // release the mapped buffer
	}

	// it is good idea to release PBOs with ID 0 after use.
	// Once bound with 0, all pixel operations are back to normal ways.
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void BaseApplication::reshape(int w, int h)
{
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//mProjectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 1.0f, 10000.f);
}



									 
void BaseApplication::cursor_position(double xpos, double ypos)
{
	int width, heigth;

	glfwGetWindowSize(window, &width, &heigth);
}


void BaseApplication::fakeBuffers()
{
	for (int i = 0; i < WIDTH*HEIGHT*RGBA; i+=4)
	{
		Buffers[1][i] = 255;
		Buffers[1][i + 1] = 0;
		Buffers[1][i + 2] = 0;
		Buffers[1][i + 3] = 255;

		Buffers[0][i] = 0;
		Buffers[0][i + 1] = 255;
		Buffers[0][i + 2] = 0;
		Buffers[0][i + 3] = 255;
	}
}

void BaseApplication::swapbuffers()
{
	_currentBuffer = 1 - _currentBuffer;
	_nextBuffer = 1 - _currentBuffer;
}


void BaseApplication::putPixel(GLubyte *buffer, const int& x, const int& y, const char& R, const char& G, const char& B, const char& A)
{
	int offset = (x + (y * WIDTH)) * RGBA;
	if (offset < 0 || offset > WIDTH * HEIGHT *RGBA)
		return;

	buffer[offset]	 = R;
	buffer[offset + 1] = G;
	buffer[offset + 2] = B;
	buffer[offset + 3] = A;

}

void BaseApplication::putPixel(const int& x, const int& y, const char& R, const char& G, const char& B, const char& A)
{
	putPixel(_screenBuffer, x, y, R, G, B, A);
}

void BaseApplication::putPixel(const int& x, const int& y, Color c)
{
	putPixel(x, y, c.R(),c.G(), c.B(), c.A());
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void BaseApplication::setup()
{
}

void BaseApplication::update()
{
}

void BaseApplication::draw()
{
	
}


void BaseApplication::keyboard(int key, int scancode, int action, int mods)
{
	const float inc = 1.0;
	switch (action)
	{		
	case GLFW_PRESS:
		switch (key)
		{
		
		case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GL_TRUE); break;		
		case GLFW_KEY_T: _currentBuffer = 1 - _currentBuffer; break;
		case GLFW_KEY_P:
			_drawMode = ++_drawMode % 3;
			switch (_drawMode)
			{
				case 0: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
				case 1: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
				case 2:	glPolygonMode(GL_FRONT, GL_FILL);
						glPolygonMode(GL_BACK, GL_LINE);
						break;
			}
		}
		//break;
		
	} //switch (action)
}
