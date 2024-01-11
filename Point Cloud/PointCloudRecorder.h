/*
*@file PointCloudRecorder.h
*@Author Me Şeyma COŞTUR (seymacostur0@gmail.com)
*@date December 2022
*@brief Nokta bulutlarinin dosyaya kaydedilmesi icin kullanilmaktadir.
*/

#pragma once
#include "PointCloud.h"
#include <string>
#include <fstream>

using namespace std;

//PointCloudRecorder sinifi
class PointCloudRecorder {
private:
	string fileName;
	ofstream file;
public:

	//Yapici fonksiyon
	PointCloudRecorder();
	PointCloudRecorder(string);
	//Yikici fonksiyon
	~PointCloudRecorder();
	//Fonksiyon cagrildiginda, dosya acilir ve paremetre olarak verilen nokta bulutlarinin dosyaya kaydedilmesini saglar.
	bool save(PointCloud& PC);
	void setfileName(string);
	string getfileName();
};