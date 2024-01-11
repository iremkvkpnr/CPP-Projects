/*
* @file 3DGridMap.h
* @Author Me İrem Kavakpınar (kavakpinarirem1@gmail.com)
* @date December,2022
* @brief : Bu sınıf, 3B ızgara tabanlı harita oluşturmaktadır.
*/
#include "PointCloud.h"
#include"PointCloudRecorder.h"
#include"DepthCamera.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
class GridMap :public Map {//private uyeler tanımlandı.
private:
	int depth = 0;
	bool* map = new bool[depth * depth * depth];
	float gridSize = 0;

public:
	GridMap() {

	}
	//GridMap icin constructor.
	GridMap(int _depth) :depth(_depth) {
		for (int i = 0; i < depth; i++)
		{
			for (int j = 0; j < depth; j++)
			{
				for (int k = 0; k < depth; k++) {
					*(map + i * depth * depth + j * depth + k) = false;
				}
			}
		}
	}
	//koordinatları verilen map'i döndurur.
	bool* getMap(int i, int j, int k) const;
	//Grid Size'ı dondurur.
	float getGridSize() const;
	//depthi dondurur.
	int getDepth() const;
	//mapin koordinatlarını atar.
	void setMap(int i, int j, int k, bool value);
	//gridsize'ı atar.
	void setGridSize(float _gridSize);
	//depth'i atar.
	void setDepth(int _depth);
	//verilen noktalar dizisinin denk geldiği küpü true olarak degistirir.
	void insertPointCloud(PointCloud& pc);
	//verilen noktanın denk geldigi kupu true olarak degistirir.
	void insertPoint(Point& p);
	//koordinatları verilen grid'i dondurur.
	bool getGrid(int x, int y, int z) const;
	//filename'i verilen dosyaya noktaları yukler.
	bool loadMap(PointCloud);
	//filename'i verilen dosyayı saveler.
	bool saveMap(string fileName);
	~GridMap() {

	}

};