/*
* @file Point.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir düzelmde nokta nesnesini oluşturan sınıf.
*/
#pragma once
#include<vector>
#include<list>

//! Point class
/*
* 3 boyutlu bir düzelmde bir nokta oluşturmamızı sağlar ve bu noktanın kordinat bilgilerini tutar.
	Noktanın oluşturulması, iki nokta arasındaki uzaklık, iki noktanın eşit olup olmadığının kontrolünü yapan
	fonksiyonlara sahiptir.
*/
class Point {
private:
	double x;
	double y;
	double z;
public:
	//! Point sinifi icin constructor.
	Point();
	//! Noktaya koordinatların atamalarını yapar.
	Point(double, double, double);
	//! Iki noktanin ayni olup olmadığının kontrolünü yapar.
	bool operator==(const Point&);
	//! Iki nokta arasindaki uzakligi hesaplar.
	const double distance(const Point&);
	//! Noktanın x koordinatının degerlerini döndürür.
	double getX() const;
	//! Noktanın y koordinatının degerlerini döndürür.
	double getY() const;
	//! Noktanın z koordinatının degerlerini döndürür.
	double getZ() const;
	//! Noktanın x koordinatının degerlerini düzenler.
	void setX(double);
	//! Noktanın y koordinatının degerlerini düzenler.
	void setY(double);
	//! Noktanın z koordinatının degerlerini düzenler.
	void setZ(double);
	//! Point sinifi icin deconstructor.
	~Point();


};