#pragma once
#include "BaseApplication.h"
#include "vec3.h"
#include "mat3.h"

class Application:public BaseApplication
{
public:
	Application();
	~Application();
	
	
	void setup() override;
	void update() override;
	void draw() override;

	std::vector<vec4>V;
	std::vector<vec4>Vcopy;

	void clearScreen();
};

