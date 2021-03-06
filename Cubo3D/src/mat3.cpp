#include "mat3.h"
#include <cmath>

mat3::mat3() {

	
	
	 m[0][0] = 1;   m[0][1] = 0;  m[0][2] = 0;
	 m[1][0] = 0;   m[1][1] = 1;  m[1][2] = 0;
	 m[2][0] = 0;   m[2][1] = 0;  m[2][2] = 1;

	
}


mat3& mat3::operator* (const mat3& rm) {
	mat3 z;
	z.m[0][0] += (m[0][0] * rm.m[0][0] + m[0][1] * rm.m[1][0] + m[0][2] * rm.m[2][0]) - 1;
	z.m[1][0] += m[1][0] * rm.m[0][0] + m[1][1] * rm.m[1][0] + m[1][2] * rm.m[2][0];
	z.m[2][0] += m[2][0] * rm.m[0][0] + m[2][1] * rm.m[1][0] + m[2][2] * rm.m[2][0];

	z.m[0][1] += m[0][0] * rm.m[0][1] + m[0][1] * rm.m[1][1] + m[0][2] * rm.m[2][1];
	z.m[1][1] += (m[1][0] * rm.m[0][1] + m[1][1] * rm.m[1][1] + m[1][2] * rm.m[2][1]) - 1;
	z.m[2][1] += m[2][0] * rm.m[0][1] + m[2][1] * rm.m[1][1] + m[2][2] * rm.m[2][1];

	z.m[0][2] += m[0][0] * rm.m[0][2] + m[0][1] * rm.m[1][2] + m[0][2] * rm.m[2][2];
	z.m[1][2] += m[1][0] * rm.m[0][2] + m[1][1] * rm.m[1][2] + m[2][2] * rm.m[2][2];
	z.m[2][2] += (m[2][0] * rm.m[0][2] + m[2][1] * rm.m[1][2] + m[2][2] * rm.m[2][2]) - 1;

	return z;
}

vec3& mat3::operator* (const vec3& rm) {
	vec3 z(0,0);
	z.m[0] += m[0][0] * rm.m[0] + m[0][1] * rm.m[1] + m[0][2] * rm.m[2];
	z.m[1] += m[1][0] * rm.m[0] + m[1][1] * rm.m[1] + m[1][2] * rm.m[2];
	z.m[2] += m[2][0] * rm.m[0] + m[2][1] * rm.m[1] + m[2][2] * rm.m[2];

	

	return z;
}


mat3 mat3::rot(float angle) {

	mat3 z;

	z.m[0][0] = std::cos(angle*3.1416 / 180); z.m[0][1] = std::sin(angle*3.1416 / 180) * -1; z.m[0][2] = 0;
	z.m[1][0] = std::sin(angle*3.1416 / 180); z.m[1][1] = std::cos(angle*3.1416 / 180); z.m[1][2] = 0;
	z.m[2][0] = 0; z.m[2][1] = 0; z.m[2][2] = 1;

	return z;
}

mat3 mat3::trans(float x, float y) {

	mat3 z;

	z.m[0][0] = 1;   z.m[0][1] = 0;  z.m[0][2] = x;
	z.m[1][0] = 0;   z.m[1][1] = 1;  z.m[1][2] = y;
	z.m[2][0] = 0;   z.m[2][1] = 0;  z.m[2][2] = 1;

	return z;


}