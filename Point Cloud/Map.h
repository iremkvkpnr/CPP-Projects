/*
* @file Map.h
* @Author Me İrem Kavakpınar (kavakpinarirem1@gmail.com)
* @date December,2022
*/
#include "PointCloud.h"
#include <string>
class Map {
public:
	//constructor tanımlandı
	Map();
	//deconstructor tanımlandı
	~Map();
	//verilen pointleri true yapan fonksiyon pure virtual olarak tanımlandı
	virtual void insertPointCloud(PointCloud& pc) = 0;
	//verilen pointleri true yapan fonksiyon pure virtual olarak tanımlandı
	virtual void insertPoint(Point& p) = 0;
	///filename'i verilen dosyaya noktaları yukler.
	virtual bool loadMap(PointCloud) = 0;
	//filename'i verilen dosyayı saveler.
	virtual bool saveMap(string fileName) = 0;

};