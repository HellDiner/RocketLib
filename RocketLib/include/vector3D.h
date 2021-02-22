#pragma once
#define NO_UPDATE 0
#define UPDATE_X 1
#define UPDATE_Y 2
#define UPDATE_Z 3
#define UPDATE_XYZ 4
struct VECTOR_3D {
	float x;
	float y;
	float z;
	int updateIndex = NO_UPDATE;
};