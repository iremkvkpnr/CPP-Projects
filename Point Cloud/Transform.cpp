/*
* @file Transform.cpp
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir düzelmde farklı orjinlere sahip noktları noktayı tek bir orjine göe değiştiren sınıf.
*/
#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include<iostream>
#include<iomanip>
#include<cmath>
#include<Eigen/Dense>

Eigen::Matrix3d rotationMatrix;

using namespace std;
/*!
\return Acıların pointerı.
*/
double* Transform::getAngles() const {

	double* ptr_angles = new double[3];
	for (int i = 0; i < 3; ++i)
	{
		ptr_angles[i] = angles(i);
	}
	return ptr_angles;
}
/*!
\return Trans arrayinin pointerı.
*/
double* Transform::getTrans() const {

	double* ptr_trans = new double[3];
	for (int i = 0; i < 3; i++)
	{
		ptr_trans[i] = trans(i);
	}
	return ptr_trans;
}
/*!
\return Donusum matrisinin ilk değeri pointerı.
*/
double Transform::getTransMatrix() const {
	using namespace Eigen;
	return transMatrix(0, 0);
}
/*!
\param value1 acı degeri
\param value2 acı degeri
\param value3 acı degeri
*/
void Transform::setAngels(double value1, double value2, double value3) {

	using namespace Eigen;
	angles(0) = value1;
	angles(1) = value2;
	angles(2) = value3;
}
/*!
\param value1 acı degeri
\param value2 acı degeri
\param value3 acı degeri
*/
void Transform::setTrans(double value1, double value2, double value3) {
	using namespace Eigen;
	trans(0) = value1;
	trans(1) = value2;
	trans(2) = value3;
}
/*!
\param value1 acı degeri
\param indexX matrisdeki sutun bilgisi degeri
\param indexY matrisdeki satır bilgisi degeri
*/
void Transform::setTansMatrix(double value, int indexX, int indexY) {
	transMatrix(indexX, indexY) = value;
}

/*!
\param ang[] acı degerleri
*/
void Transform::setRotation(Eigen::Vector3d ang) {
	transMatrix(0, 0) = cos(ang(2)) * cos(ang(1));
	transMatrix(0, 1) = (cos(ang(2)) * sin(ang(1)) * sin(ang(0))) - (sin(ang(2)) * cos(ang(0)));
	transMatrix(0, 2) = (cos(ang(2)) * sin(ang(1)) * cos(ang(0))) + (sin(ang(2)) * sin(ang(0)));

	transMatrix(1, 0) = sin(ang(2)) * cos(ang(1));
	transMatrix(1, 1) = (sin(ang(2)) * sin(ang(1)) * sin(ang(0))) + (cos(ang(2)) * cos(ang(0)));
	transMatrix(1, 2) = (sin(ang(2)) * sin(ang(1)) * cos(ang(0))) - (cos(ang(2)) * sin(ang(0)));

	transMatrix(2, 0) = -sin(ang(1));
	transMatrix(2, 1) = cos(ang(1)) * sin(ang(0));
	transMatrix(2, 2) = cos(ang(1)) * cos(ang(0));

	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
}
/*!
\param rotation[][3] rotasyon degerleri
*/
void Transform::setRotation1(Eigen::Matrix3d rotation) {
	transMatrix(0, 0) = rotation(0, 0);
	transMatrix(0, 1) = rotation(0, 1);
	transMatrix(0, 2) = rotation(0, 2);

	transMatrix(1, 0) = rotation(1, 0);
	transMatrix(1, 1) = rotation(1, 1);
	transMatrix(1, 2) = rotation(1, 2);

	transMatrix(2, 0) = rotation(2, 0);
	transMatrix(2, 1) = rotation(2, 1);
	transMatrix(2, 2) = rotation(2, 2);

	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
}
/*!
\param tr[] trans degerleri
*/
void Transform::setTranslation(Eigen::Vector3d tr) {
	transMatrix(0, 3) = tr(0);
	transMatrix(1, 3) = tr(1);
	transMatrix(2, 3) = tr(2);
	transMatrix(3, 3) = 1;

}
/*!
\param p Donusum yapılacak nokta.
\return Donusum yapışan nokta.
*/
Point Transform::doTransform(Point p) {
	Point new_point;

	double p_coord[3];

	p_coord[0] = p.getX();
	p_coord[1] = p.getY();
	p_coord[2] = p.getZ();
	using namespace Eigen;
	Vector4d point1, point2;
	point2(0) = p_coord[0];
	point2(1) = p_coord[1];
	point2(2) = p_coord[2];
	point2(3) = 1;

	//Donusum matrisiyle point in noktalarinin carpim islemi
	point1 = transMatrix * point2;

	//Donusturlmus noktanin koord set edilir.
	new_point.setX(point1(0));
	new_point.setY(point1(1));
	new_point.setZ(point1(2));

	return new_point;
}
/*!
\param p Donusum yapılacak nokta bulutu.
\return Donusum yapılan nokta bulutu.
*/
list<Point> Transform::doTransform(list<Point> lp)
{
	std::list<Point> new_list;
	std::list<Point>::iterator iter;
	//list teki her bir pointe transform islemi uygulanir
	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		new_list.push_back(doTransform(*iter));
	}
	return new_list;

}
PointCloud Transform::doTransform(PointCloud& pc) {

	PointCloud new_pointCloud;
	std::list<Point>pTemp;
	pTemp = pc.getPoints();
	new_pointCloud.setPoints(doTransform(pTemp));
	return new_pointCloud;
}