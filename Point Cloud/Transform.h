/*
* @file Transform.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir düzelmde farklı orjinlere sahip noktları noktayı tek bir orjine göe değiştiren sınıf.
*/

//! Transform Sinifi
/*!
  İki koordinat duzleminin orijinleri arasindaki uzakligi ve rotasyon acilarini kullanarak
  donusum matrisini olusturur.
  Nokta ya da nokta bulutunu bu donusum matrisi ile bir donusum yapmasını saglayarak
  nokta ya da nokta bulutunu geri dondurur.
*/
#pragma once
#include"PointCloud.h"
#include <Eigen/Dense>
#include<iomanip>

using namespace std;


class Transform {
private:
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;


public:
	//! Point sinifi icin constructor.
	Transform() {

	}
	//! acı değerlerini geri döndürür
	double* getAngles() const;
	//! Donusum değerlerini geri döndürür
	double* getTrans() const;
	//! Donusum matrixini geri döndürür
	double getTransMatrix() const;
	//! Acı degerlerini düzenler
	void setAngels(double, double, double);
	//! Donusum değerlerini duzenler
	void setTrans(double, double, double);
	//! Donusum matrixini düzenler
	void setTansMatrix(double, int, int);
	//! Acı egerleriyle rotasyon matrisini olusturur
	void setRotation(Eigen::Vector3d ang);
	//! translation matrisini hesaplar
	void setTranslation(Eigen::Vector3d tr);
	//! verilen rotaston değerleri ile transMatrixi düzenler
	void setRotation1(Eigen::Matrix3d rotation);
	//! alınan noktanın donusumunu saglar
	Point doTransform(Point p);
	//! alınan nokta bulutunun donusumunu saglar
	//! 
	list<Point> doTransform(list<Point> lp);
	PointCloud doTransform(PointCloud& pc);
	//! Point sinifi icin deconstructor.
	~Transform() {

	}
};