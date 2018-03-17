#ifndef VEC4_H
#define VEC4_H

class vec4 {
public:
	int m[4];
	int x() { return m[0]; }
	int y() { return m[1]; }
	int z() { return m[2]; }

	vec4(int x, int y, int z);

	float punto(vec4 rh);
	vec4 cruz(vec4 rh);

	vec4& operator - (const vec4& rh);

	vec4 normal(vec4 rh);

};

#endif