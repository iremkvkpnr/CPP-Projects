/*
* @file Point.cpp
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir düzelmde nokta nesnesini oluşturan sınıf.
*/
#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;
/*!
\param _x Noktaya atanacak x degeri.
\param _y Noktaya atanacak y degeri.
\param _z Noktaya atanacak z degeri.
*/

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}
/*!
\param _x Noktadan alinacak x degeri.
\param _y Noktadan alinacak y degeri.
\param _z Noktadan alinacak z degeri.
*/
Point::Point(double _x = 0.0, double _y = 0.0, double _z = 0.0) :x(_x), y(_y), z(_z) {

}
/*!
\param p Karsilastirma yapilacak diger nokta.
\return Karsilastirma sonucu.
*/
bool Point::operator==(const Point& p) {
	if (p.x == x && p.y == y && p.z == z)
		return true;
	return false;
};
/*!
\param p Aradaki uzakligi hesaplanacak diger nokta.
\return Iki nokta arasindaki uzaklik.
*/
const double Point::distance(const Point& p) {
	double distance = pow(this->x - p.x, 2) + pow(this->y - p.y, 2) + pow(this->z - p.z, 2);
	distance = sqrt(distance);
	return distance;
};
/*!
\return noktanin x kordinati
*/
double Point::getX() const {
	return this->x;
}
/*!
\return noktanin y kordinati
*/
double Point::getY() const {
	return this->y;
}
/*!
\return noktanin z kordinati
*/
double Point::getZ() const {
	return this->z;
}
/*!
* \param x noktanın x kordinatının yeni değeri
\return noktanin x kordinati
*/
void Point::setX(double x) {
	this->x = x;
}
/*!
* * \param y noktanın y kordinatının yeni değeri
\return noktanin y kordinati
*/
void Point::setY(double y) {
	this->y = y;
}
/*!
* * \param z noktanın z kordinatının yeni değeri
\return noktanin z kordinati
*/
void Point::setZ(double z) {
	this->z = z;
}
Point:: ~Point() {

}