/*
* @file main.cpp
* @Author Me Buse Ercan (busercan@hotmail.com)
*			 İrem Kavakpınar (kavakpinarirem1@gmail.com)
*			 Beyza Uygur (beyzauygur989@gmail.com)
*			 Şeyma Coştur (seymacostur0@gmail.com)
* @date December,2022
* @brief oluşturulan fonksiyonların testlerinin yapıldığı kısım
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include "Point.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "Transform.h"
#include "3DGridMap.h"
#include"PointCloudGenerator.h"
#include"MapperInterface.h"
#include "Map.h"

using namespace std;

int main() {

	PointCloudRecorder* PCR = new PointCloudRecorder();
	DepthCamera DC1, DC2, DC3, DC4;
	Transform T1, T2, T3, T4;
	GridMap GM;
	MapperInterface MI;
	PointCloudGenerator* PCG1, * PCG2, * PCG3, * PCG4;


	DC1.setFileName("cam.txt");
	DC2.setFileName("cam1.txt");
	DC3.setFileName("cam2.txt");
	DC4.setFileName("cam3.txt");

	PCG1 = &DC1;
	PCG2 = &DC2;
	PCG3 = &DC3;
	PCG4 = &DC4;

	Eigen::Matrix3d rotation1;
	rotation1 << -0.7076050, 0.0065031, -0.7065783,
		0.7066082, 0.0065134, -0.7075750,
		0.0000008, -0.9999576, -0.0092041;
	Eigen::Vector3d trans1(1.95704, 1.93000, 1.05707);
	T1.setRotation1(rotation1);
	T1.setTranslation(trans1);
	PCG1->setTransform(T1);

	Eigen::Matrix3d rotation2;
	rotation2 << -0.6638364, -0.0068830, 0.7478462,
		-0.7478778, 0.0061099, -0.6638082,
		-0.0000002, -0.9999576, -0.0092036;
	Eigen::Vector3d trans2(-1.91288, 1.94412, 1.05465); // x, y, z
	T2.setRotation1(rotation2);
	T2.setTranslation(trans2);
	PCG2->setTransform(T2);


	Eigen::Matrix3d rotation3;
	rotation3 << 0.8762180, 0.0044351, -0.4818945,
		0.4819149, -0.0080638, 0.8761809,
		0.0000001, -0.9999577, -0.0092030;
	Eigen::Vector3d trans3(1.96978, -1.94622, 1.05264); // x, y, z
	T3.setRotation1(rotation3);
	T3.setTranslation(trans3);
	PCG3->setTransform(T3);

	Eigen::Matrix3d rotation4;
	rotation4 << 0.3597052, -0.0085871, 0.9330265,
		-0.9330660, -0.0033108, 0.3596900,
		0.0000003, -0.9999576, -0.0092033;
	Eigen::Vector3d trans4(-1.87445, -1.95027, 1.06432); // x, y, z
	T4.setRotation1(rotation4);
	T4.setTranslation(trans4);
	PCG4->setTransform(T4);


	MI.addGenerator(PCG1);
	MI.addGenerator(PCG2);
	MI.addGenerator(PCG3);
	MI.addGenerator(PCG4);

	if (MI.generate())
		cout << "pointCloud olusturuldu." << endl;
	else
		cout << "PointCloudGenerator nesnesi bulunamadi!" << endl;

	MI.setRecorder(PCR);

	if (MI.recordPointCloud())
		cout << "pointCloud output.txt dosyasina yazildi." << endl;
	else
		cout << "pointCloud nesnesi bulunamadi!" << endl;

	GM.setDepth(10);
	GM.setGridSize(1);

	if (MI.insertMap())
		cout << "Harita yuklendi" << endl;
	else
		cout << "Harita yuklenemedi" << endl;





	if (MI.recordMap("Map.txt"))
		cout << "Harita kaydeldi" << endl;
	else
		cout << "Harita kaydedilemedi" << endl;

}