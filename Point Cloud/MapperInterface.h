#pragma once
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include"Map.h"
class MapperInterface {
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;
public:
	MapperInterface();
	~MapperInterface();

	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool recordPointCloud();
	bool recordMap(string);
	bool insertMap();
};
