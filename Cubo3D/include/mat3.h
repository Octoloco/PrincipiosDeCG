#ifndef MAT3_H
#define MAT3_H
#include "vec3.h"

class mat3 {
public:
	float m[3][3];
	//mat3 identity();
	mat3& operator* (const mat3& rm);
	vec3& operator* (const vec3& rm);

	mat3();

	mat3 rot(float angle);
	mat3 trans(float x, float y);



};

#endif