#ifndef MAT4_H
#define MAT4_H
#include "vec4.h"
#include <math.h>

class mat4 {
public:
	float m[4][4];
	//mat3 identity();
	mat4& operator* (const mat4& rm);
	vec4& operator* (const vec4& rm);

	mat4();

	static mat4 rotx(float angle);
	static mat4 roty(float angle);
	static mat4 rotz(float angle);
	mat4 trans(float x, float y, float z);

	float FOV = (100 / 3.1416 * 180)/2;
	float aspectRatio = 1;
	float nearClip = 1;
	float farClip = 20;

	float d = 1 / (sin(FOV)/cos(FOV));

	static mat4 persp(float FOV, float aspectRatio, float farClip, float nearClip);
	static mat4 cam(vec4 up, vec4 eye, vec4 target);


};

#endif