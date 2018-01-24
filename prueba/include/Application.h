#pragma once
#include "BaseApplication.h"
class Application:public BaseApplication
{
public:
	Application();
	~Application();
	void horizontal();
	void setup() override;
	void update() override;
	void draw() override;
};

