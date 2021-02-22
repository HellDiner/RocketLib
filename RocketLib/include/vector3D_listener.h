#pragma once
#include "Vector3D.h"
typedef void (*listenFunction)(float,float,float);
class Vector3DListener {
public:
	Vector3DListener(listenFunction onUpdate) : onUpdate(onUpdate) {};
	void update(VECTOR_3D vec);
private:
	listenFunction onUpdate;
};