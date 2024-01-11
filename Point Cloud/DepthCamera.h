/* * @file DepthCamera.h
* @Author Me Beyza Uygur(beyzauygur989@gmail.com)
* @date December,2022
*@brief capture fonksiyonu çağrıldığında noktaları okuyan ve yaratılan nokta bulutu
nesnesine bu noktaları atayan sınıf.
fileName dosyasından noktaları okur nokta bulut nesnesine bu noktaları atar.
Nokta bulutnu döndürür.Noktalar dosyadan alınır.*/
#pragma once
#include "PointCloud.h"
#include "Transform.h"
#include<iostream>
#include<fstream>
#include <string>
#include "PointCloudGenerator.h"
using namespace std;

class DepthCamera :public PointCloudGenerator {
private:
	string fileName;
public:
	DepthCamera() {

	}
	~DepthCamera() {

	}
	void setFileName(const string&);//fileName yi public değişkenine eşitler.
	string getFileName()const;//dosyayı döndürür.
	PointCloud capture();//fileName dosyasını okuyup pointcloud nesnesine atar.
	PointCloud captureFor();
};