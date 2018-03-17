#include "mat4.h"
#include <cmath>

mat4::mat4() {



	m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
	m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;


}


mat4& mat4::operator* (const mat4& rm) {
	mat4 z;
	z.m[0][0] += (m[0][0] * rm.m[0][0] + m[0][1] * rm.m[1][0] + m[0][2] * rm.m[2][0] + m[0][3] * rm.m[3][0]) - 1;
	z.m[1][0] += m[1][0] * rm.m[0][0] + m[1][1] * rm.m[1][0] + m[1][2] * rm.m[2][0] + m[1][3] * rm.m[3][0];
	z.m[2][0] += m[2][0] * rm.m[0][0] + m[2][1] * rm.m[1][0] + m[2][2] * rm.m[2][0] + m[2][3] * rm.m[3][0];
	z.m[3][0] += m[3][0] * rm.m[0][0] + m[3][1] * rm.m[1][0] + m[3][2] * rm.m[2][0] + m[3][3] * rm.m[3][0];

	z.m[0][1] += m[0][0] * rm.m[0][1] + m[0][1] * rm.m[1][1] + m[0][2] * rm.m[2][1] + m[0][3] * rm.m[3][1];
	z.m[1][1] += (m[1][0] * rm.m[0][1] + m[1][1] * rm.m[1][1] + m[1][2] * rm.m[2][1] + m[1][3] * rm.m[3][1]) - 1;
	z.m[2][1] += m[2][0] * rm.m[0][1] + m[2][1] * rm.m[1][1] + m[2][2] * rm.m[2][1] + m[2][3] * rm.m[3][1];
	z.m[3][1] += m[3][0] * rm.m[0][1] + m[3][1] * rm.m[1][1] + m[3][2] * rm.m[2][1] + m[3][3] * rm.m[3][1];

	z.m[0][2] += m[0][0] * rm.m[0][2] + m[0][1] * rm.m[1][2] + m[0][2] * rm.m[2][2] + m[0][3] * rm.m[3][2];
	z.m[1][2] += m[1][0] * rm.m[0][2] + m[1][1] * rm.m[1][2] + m[1][2] * rm.m[2][2] + m[1][3] * rm.m[3][2];
	z.m[2][2] += (m[2][0] * rm.m[0][2] + m[2][1] * rm.m[1][2] + m[2][2] * rm.m[2][2] + m[2][3] * rm.m[3][2]) - 1;
	z.m[3][2] += m[3][0] * rm.m[0][2] + m[3][1] * rm.m[1][2] + m[3][2] * rm.m[2][2] + m[3][3] * rm.m[3][2];

	z.m[0][3] += m[0][0] * rm.m[0][3] + m[0][1] * rm.m[1][3] + m[0][2] * rm.m[2][3] + m[0][3] * rm.m[3][3];
	z.m[1][3] += m[1][0] * rm.m[0][3] + m[1][1] * rm.m[1][3] + m[1][2] * rm.m[2][3] + m[1][3] * rm.m[3][3];
	z.m[2][3] += m[2][0] * rm.m[0][3] + m[2][1] * rm.m[1][3] + m[2][2] * rm.m[2][3] + m[2][3] * rm.m[3][3];
	z.m[3][3] += (m[3][0] * rm.m[0][3] + m[3][1] * rm.m[1][3] + m[3][2] * rm.m[2][3] + m[3][3] * rm.m[3][3]) -1;

	return z;
}

vec4& mat4::operator* (const vec4& rm) {
	vec4 z(0, 0, 0);
	z.m[0] += m[0][0] * rm.m[0] + m[0][1] * rm.m[1] + m[0][2] * rm.m[2];
	z.m[1] += m[1][0] * rm.m[0] + m[1][1] * rm.m[1] + m[1][2] * rm.m[2];
	z.m[2] += m[2][0] * rm.m[0] + m[2][1] * rm.m[1] + m[2][2] * rm.m[2];
	z.m[3] += m[3][0] * rm.m[0] + m[3][1] * rm.m[1] + m[3][2] * rm.m[2];



	return z;
}


mat4 mat4::rotx(float angle) {

	mat4 z;

	z.m[1][1] = std::cos(angle*3.1416 / 180); z.m[1][2] = std::sin(angle*3.1416 / 180)*-1; 
	z.m[2][1] = std::sin(angle*3.1416 / 180); z.m[2][2] = std::cos(angle*3.1416 / 180); 
	

	return z;
}

mat4 mat4::roty(float angle) {

	mat4 z;

	z.m[0][0] = std::cos(angle*3.1416 / 180); z.m[2][0] = std::sin(angle*3.1416 / 180); 
	z.m[0][2] = std::sin(angle*3.1416 / 180); z.m[2][2] = std::cos(angle*3.1416 / 180); 
	

	return z;
}

mat4 mat4::rotz(float angle) {

	mat4 z;

	z.m[0][0] = std::cos(angle*3.1416 / 180); z.m[0][1] = std::sin(angle*3.1416 / 180)*-1;
	z.m[1][0] = std::sin(angle*3.1416 / 180); z.m[1][1] = std::cos(angle*3.1416 / 180);
	

	return z;
}

mat4 mat4::trans(float x, float y, float z) {

	mat4 k;

	k.m[0][0] = 1;   k.m[0][1] = 0;  k.m[0][2] = 0; k.m[0][3] = x;
	k.m[1][0] = 0;   k.m[1][1] = 1;  k.m[1][2] = 0; k.m[1][3] = y;
	k.m[2][0] = 0;   k.m[2][1] = 0;  k.m[2][2] = 1; k.m[2][3] = z;
	k.m[3][0] = 0;   k.m[3][1] = 0;  k.m[3][2] = 0; k.m[3][3] = 1;

	return k;


}


mat4 mat4::persp(float FOV, float aspectRatio, float farClip, float nearClip) {

	mat4 z;

	z.m[0][0] = (1 / (sin(FOV) / cos(FOV)) / aspectRatio);
	z.m[1][1] = 1 / (sin(FOV) / cos(FOV));
	z.m[2][2] = -((farClip + nearClip) / (farClip - nearClip));
	z.m[2][3] = -((2 * farClip*nearClip) / (farClip - nearClip));
	z.m[3][2] = 1;

	return z;

}


mat4 mat4::cam(vec4 up, vec4 eye, vec4 target) {

	mat4 rot1;
	mat4 trans1;
	mat4 acum;

	vec4 f(0, 0, 0);
	vec4 u(0, 0, 0);
	vec4 r(0, 0, 0);

	f = f.normal(eye-target);

	r = r.normal(f.cruz(up));

	u = r.cruz(f);

	rot1.m[0][0] = r.x(); rot1.m[0][1] = u.x(); rot1.m[0][2] = f.x();
	rot1.m[1][0] = r.y(); rot1.m[1][1] = u.y(); rot1.m[1][2] = f.y();
	rot1.m[2][0] = r.z(); rot1.m[2][1] = u.z(); rot1.m[2][2] = f.z();


	trans1.m[0][3] = (eye.x()) * -1;
	trans1.m[1][3] = (eye.y()) * -1;
	trans1.m[2][3] = (eye.z()) * -1;

	acum = rot1 * trans1;

	return acum;
	

}