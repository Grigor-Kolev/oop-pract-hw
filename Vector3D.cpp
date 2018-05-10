#include "stdafx.h"
#include "Vector3D.h"

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;

	correctX();
}

double Vector3D::getX() const {
	return x;
}

double Vector3D::getY() const {
	return y;
}

double Vector3D::getZ() const {
	return z;
}

Vector3D Vector3D::operator+(const Vector3D & other) const {
	return Vector3D(x + other.x, y + other.y, z + other.z);
}


Vector3D Vector3D::operator-() const {
	return -1 * (*this);
}

Vector3D Vector3D::operator-(const Vector3D & other) const {
	return *this + (-other);
}

Vector3D Vector3D::operator*(double number) const {
	return Vector3D(x*number, y*number, z*number);
}

Vector3D operator*(double number, const Vector3D & vector) {
	return vector*number;
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector) {
	char dummy;
	return iStream >> dummy >> vector.x >> dummy >> vector.y >> dummy >> vector.z >> dummy;
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector)
{
	return oStream << '(' << vector.x << ',' << vector.y << ',' << vector.z << ')';
}

void Vector3D::correctX() {
	(x == 0)? x = 0 : 0;
}

void Vector3D::correctY() {
	(y == 0) ? y = 0 : 0;
}

void Vector3D::correctZ() {
	(z == 0) ? z = 0 : 0;
}



Vector3D evaluate(Vector3D* arguments, int size, Vector3D(*transform)(const Vector3D&)) {
	Vector3D result = arguments[0];

	for (int i = 1; i != size; i++) {
		result = result + transform(arguments[i]);
	}

	return result;
}



void transform(Vector3D* arguments, int size, Vector3D(*transform)(const Vector3D&)) {
	for (int i = 0; i != size; i++) {
		arguments[i] = transform(arguments[i]);
	}
}

void transform(Vector3D* arguments, int size, Vector3D(*transform)(const Vector3D&, const double&), double scalarArgument) {
	for (int i = 0; i != size; i++) {
		arguments[i] = transform(arguments[i], scalarArgument);
	}
}



Vector3D identityTransform(const Vector3D& argument) {
	return argument;
}

Vector3D negativeTransform(const Vector3D& argument) {
	return -argument;
}



Vector3D multiplicativeTransform(const Vector3D& vectorArgument, const double& scalarArgument) {
	return vectorArgument*scalarArgument;
}

Vector3D multiplicativeTransform(const double& scalarArgument, const Vector3D& vectorArgument) {
	return multiplicativeTransform(vectorArgument, scalarArgument);
}



void print(Vector3D* vectors, int size) {
	if (!size) {
		return;
	}

	std::cout << vectors[0];

	for (int i = 1; i != size; i++) {
		std::cout << " " << vectors[i];
	}

	std::cout << std::endl;
}

void read(Vector3D* vectors, int& size) {
	std::cin >> size;

	for (int i = 0; i != size; i++) {
		std::cin >> vectors[i];
	}
}