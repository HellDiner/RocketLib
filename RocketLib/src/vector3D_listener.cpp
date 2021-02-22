#include "pch.h"
#include "vector3D_listener.h"
void Vector3DListener::update(VECTOR_3D vec) {
	this->onUpdate(vec.x, vec.y, vec.z);
}