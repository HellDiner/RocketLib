#pragma once
#include "Vector3D.h"
#include <vector>
#include "vector3D_listener.h"
#define DllExport __declspec(dllexport)

class Entity {
public:
	DllExport void setX(float x);
	DllExport void setY(float y);
	DllExport void setZ(float z);
	DllExport void setTranslationFactorX(float tx);
	DllExport void setTranslationFactorY(float ty);
	DllExport void setTranslationFactorZ(float tz);
	DllExport void setRotationFactorX(float rx);
	DllExport void setRotationFactorY(float ry);
	DllExport void setRotationFactorZ(float rz);
	DllExport void setLocation(float x, float y, float z);
	DllExport void setTranslationFactors(float tx, float ty, float tz);
	DllExport void setRotationFactors(float rx, float ry, float rz);
	DllExport float getX();
	DllExport float getY();
	DllExport float getZ();
	DllExport float getTranslationFactorX();
	DllExport float getTranslationFactorY();
	DllExport float getTranslationFactorZ();
	DllExport float getRotationFactorX();
	DllExport float getRotationFactorY();
	DllExport float getRotationFactorZ();
	DllExport int addLocationListener(Vector3DListener listener);
	DllExport int addTranslationFactorsListener(Vector3DListener listener);
	DllExport int addRotationFactorsListener(Vector3DListener listener);
	DllExport void removeLocationListener(int index);
	DllExport void removeTranslationFactorsListener(int index);
	DllExport void removeRotationFactorsListener(int index);
	int updateLocation();
	int updateTranslationFactors();
	int updateRotationFactors();
	void onUpdateLocation(float x, float y, float z);
	void onUpdateTranslationFactors(float tx, float ty, float tz);
	void onUpdateRotationFactors(float rx, float ry, float rz);
	static const SIZE_T BALL_ID = 0x3F19999A3EB33333;
private:
	std::vector<Vector3DListener> locationListeners,translationFactorsListeners,rotationFactorsListeners;
	VECTOR_3D location, translationFactors, rotationFactors;
};