#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<iostream>

class Vector3D {
public:
	/**
	* Създава вектор със стойности 0
	*/
	Vector3D();

	/**
	* Създава вектор по зададените стойности за компонентите x, y и z, където
	* x, y и z са зададени спрямо правоъгълна координатна система
	* @param x
	* @param y
	* @param z
	*/
	Vector3D(double x, double y, double z);

	/**
	* Връща стойността за x
	* @return x
	*/
	double getX() const;

	/**
	* Връща стойността за y
	* @return y
	*/
	double getY() const;

	/**
	* Връща стойността за z
	* @return z
	*/
	double getZ() const;

	/**
	* Предоставя възможност за събиране на вектори
	* @param secondVector вектор
	* @return Нов вектор
	*/
	Vector3D operator+(const Vector3D & other) const;

	/**
	* Предоставя възможност за изваждане на вектори
	* @param secondVector вектор
	* @return Нов вектор
	*/
	Vector3D operator-(const Vector3D & other) const;

	/**
	* Връща нов вектор с променен знак
	* @return Нов вектор с променен знак
	*/
	Vector3D operator-() const;

	/**
	* Умножава векторът с числото number
	* @param number - число с което се умножава векторът
	* @return Нов вектор
	*/
	Vector3D operator*(double number) const;

	/**
	* приема стойностите на коректно подаден символен низ с формат "(x,y,z)", където x, y и z са числа от тип double
	*/
	void fromCharArray(char* vector) const;

	/**
	* Умножава число с вектор
	* @param number - число
	* @param vector - вектор
	* @return Нов вектор
	*/
	friend Vector3D operator*(double number, const Vector3D & vector);

	/**
	* Предоставя възможност за въвеждане на данни за вектор от стандартния вход, като трябва
	* да бъде спазен следния формат:
	* (x, y, z)
	*/
	friend std::istream & operator>>(std::istream & iStream, Vector3D & vector);

	/**
	* Предоставя възможност за визуализиране (извеждане) на стойностите в следния формат:
	* (x, y, z)
	*/
	friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);

private:
	double x;
	double y;
	double z;
	
	/**
	* changes -0.0 to 0.0
	*/
	void correctX();
	void correctY();
	void correctZ();
};


/**
* called when a single vector is to be evaluated from a set of vectors
*/
Vector3D evaluate(Vector3D* arguments, int size, Vector3D(*transform)(const Vector3D&));

/**
* takes a set of vectors and changes each one according to a transform function
*/
void transform(Vector3D* arguments, int size, Vector3D(*transform)(const Vector3D&));
// for binary operators
void transform(Vector3D* arguments, int size, Vector3D(*transform)(const Vector3D&, const double&), double scalarArgument);


/**
* functions of type Vector3D -> Vector3D
*/
Vector3D identityTransform(const Vector3D& argument);

Vector3D negativeTransform(const Vector3D& argument);

Vector3D multiplicativeTransform(const Vector3D& vectorArgument, const double& scalarArgument);

Vector3D multiplicativeTransform(const double& scalarArgument, const Vector3D& vectorArgument);


/**
* helper functions for input and output
*/
void print(Vector3D* vectors, int size);
void read(Vector3D* vectors, int& size);

#endif