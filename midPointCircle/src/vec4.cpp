#include "vec4.h"
#include <math.h>

vec4::vec4(int x, int y, int z) {
	m[0] = x;
	m[1] = y;
	m[2] = z;
	m[3] = 1;
}

float vec4::punto(vec4 rh) {

	float s;

	s = (m[0] *rh.m[0]) + (m[1] * rh.m[1]) + (m[2] * rh.m[2]);

	return s;

}

vec4 vec4::cruz(vec4 rh) {

	vec4 c(0,0,0);

	c.m[0] = (m[1] * rh.m[2]) - (m[2] * rh.m[1]);
	c.m[1] = ((m[0] * rh.m[2]) - (m[2] * rh.m[0])) * -1;
	c.m[2] = (m[0] * rh.m[1]) - (m[1] * rh.m[0]);

	return c;
}

vec4& vec4::operator - (const vec4& rh) {

	vec4 r(0,0,0);

	r.m[0] = m[0] - rh.m[0];
	r.m[1] = m[1] - rh.m[1];
	r.m[2] = m[2] - rh.m[2];

	return r;
}


vec4 vec4::normal(vec4 rh) {

	vec4 c(0, 0, 0);

	float mag;

	mag = sqrt((rh.x()) ^ 2 + (rh.y()) ^ 2 + (rh.z()) ^ 2);

	c.m[0] = rh.m[0] / mag;
	c.m[1] = rh.m[1] / mag;
	c.m[2] = rh.m[2] / mag;

	return c;

}
