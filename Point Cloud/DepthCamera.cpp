/* * @file DepthCamera.cpp * @Author Me Beyza Uygur(beyzauygur989@gmail.com) *
@date December,2022 *
@brief capture fonksiyonu çağrıldığında noktaları okuyan ve yaratılan nokta
bulutu nesnesine bu noktaları atayan sınıf. */
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include <fstream>
#include <iostream>
#include <string>
#include <list>
/ fileName adlı dosyayı public değişkenine eşitler /
void DepthCamera::setFileName(const string & fileName)
{
	this->fileName = fileName;
}
string DepthCamera::getFileName() const / fileName dosyasını return eder /
{
	return fileName;
}
PointCloud DepthCamera::capture() {/*fileName dosyasını okur ve pointcloud nesnesine atar.*/

	fileName = getFileName();

	ifstream file(fileName);

	if (!file.is_open())
		exit(0);

	int n = 0;
	double x, y, z;
	string temp;
	int count;
	double tem1, tem2, tem3;
	list<Point> P1;
	PointCloud pointcloud;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> count;
	while (!file.eof()) {
		file >> x >> y >> z;
		file >> tem1 >> tem2 >> tem3;
		Point* point = new Point(x, y, z);
		P1.push_back(*point);
		n++;
		if (n == count)
		{
			break;
		}
	}

	pointcloud.setPoints(P1);
	file.close();
	return pointcloud;
};
PointCloud DepthCamera::captureFor() {
	fileName = getFileName();

	ifstream file(fileName);

	if (!file.is_open())
		exit(0);
	int n = 0;
	double x, y, z;
	string temp;
	int count;
	double tem1, tem2, tem3;
	list<Point> P1;
	Transform T;
	T = getTransform();
	PointCloud pointcloud;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> temp;
	file >> count;
	while (!file.eof()) {
		file >> x >> y >> z;
		file >> tem1 >> tem2 >> tem3;
		Point* point = new Point(x, y, z);
		P1.push_back(*point);
		n++;
		if (n == count)
		{
			break;
		}
	}
	pointcloud.setPoints(P1);
	file.close();

	pointcloud = T.doTransform(pointcloud);

	return pointcloud;
}