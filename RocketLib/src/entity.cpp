#include "pch.h"
#include "entity.h"

void Entity::setX(float x) {
	this->location.x = x;
	this->location.updateIndex = UPDATE_X;
}
void Entity::setY(float y) {
	this->location.y = y;
	this->location.updateIndex = UPDATE_Y;
}
void Entity::setZ(float z) {
	this->location.z = z;
	this->location.updateIndex = UPDATE_Z;
}
void Entity::setTranslationFactorX(float tx) {
	this->translationFactors.x = tx;
	this->translationFactors.updateIndex = UPDATE_X;
}
void Entity::setTranslationFactorY(float ty) {
	this->translationFactors.y = ty;
	this->translationFactors.updateIndex = UPDATE_Y;
}
void Entity::setTranslationFactorZ(float tz) {
	this->translationFactors.z = tz;
	this->translationFactors.updateIndex = UPDATE_Z;
}
void Entity::setRotationFactorX(float rx) {
	this->rotationFactors.x = rx;
	this->rotationFactors.updateIndex = UPDATE_X;
}
void Entity::setRotationFactorY(float ry) {
	this->rotationFactors.y = ry;
	this->rotationFactors.updateIndex = UPDATE_Y;
}
void Entity::setRotationFactorZ(float rz) {
	this->rotationFactors.z = rz;
	this->rotationFactors.updateIndex = UPDATE_Z;
}
void Entity::setLocation(float x, float y, float z) {
	this->location = { x,y,z };
	this->location.updateIndex = UPDATE_XYZ;
}

void Entity::setTranslationFactors(float tx, float ty, float tz) {
	this->translationFactors = { tx, ty, tz };
	this->translationFactors.updateIndex = UPDATE_XYZ;
}

void Entity::setRotationFactors(float rx, float ry, float rz) {
	this->rotationFactors = { rx,ry,rz };
	this->rotationFactors.updateIndex = UPDATE_XYZ;
}

float Entity::getX() {
	return this->location.x;
}
float Entity::getY() {
	return this->location.y;
}
float Entity::getZ() {
	return this->location.z;
}
float Entity::getTranslationFactorX() {
	return this->translationFactors.x;
}
float Entity::getTranslationFactorY() {
	return this->translationFactors.y;
}
float Entity::getTranslationFactorZ() {
	return this->translationFactors.z;
}
float Entity::getRotationFactorX() {
	return this->rotationFactors.x;
}
float Entity::getRotationFactorY() {
	return this->rotationFactors.y;
}
float Entity::getRotationFactorZ() {
	return this->rotationFactors.z;
}
int Entity::updateLocation() {
	return this->location.updateIndex;
}
int Entity::updateTranslationFactors() {
	return this->translationFactors.updateIndex;
}
int Entity::updateRotationFactors() {
	return this->rotationFactors.updateIndex;
}
int Entity::addLocationListener(Vector3DListener listener) {
	this->locationListeners.push_back(listener);
	return this->locationListeners.size() - 1;
}
int Entity::addTranslationFactorsListener(Vector3DListener listener) {
	this->translationFactorsListeners.push_back(listener);
	return this->translationFactorsListeners.size() - 1;
}
int Entity::addRotationFactorsListener(Vector3DListener listener) {
	this->rotationFactorsListeners.push_back(listener);
	return this->rotationFactorsListeners.size() - 1;
}
void Entity::removeLocationListener(int index) {
	this->locationListeners.erase(this->locationListeners.begin() + index);
}
void Entity::removeTranslationFactorsListener(int index) {
	this->translationFactorsListeners.erase(this->translationFactorsListeners.begin() + index);
}
void Entity::removeRotationFactorsListener(int index) {
	this->rotationFactorsListeners.erase(this->rotationFactorsListeners.begin() + index);
}
void Entity::onUpdateLocation(float x, float y, float z) {
	this->location = { x,y,z };
	this->location.updateIndex = NO_UPDATE;
	for (Vector3DListener listener : this->locationListeners) listener.update(this->location);
}
void Entity::onUpdateTranslationFactors(float tx, float ty, float tz) {
	this->translationFactors = { tx,ty,tz };
	this->translationFactors.updateIndex = NO_UPDATE;
	for (Vector3DListener listener : this->translationFactorsListeners) listener.update(this->translationFactors);
}
void Entity::onUpdateRotationFactors(float rx, float ry, float rz) {
	this->rotationFactors = { rx,ry,rz };
	this->rotationFactors.updateIndex = NO_UPDATE;
	for (Vector3DListener listener : this->rotationFactorsListeners) listener.update(this->rotationFactors);
}