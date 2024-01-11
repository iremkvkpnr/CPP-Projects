#include "MapperInterface.h"
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include"Map.h"
#include <iostream>
using namespace std;

MapperInterface::MapperInterface() {

}
MapperInterface:: ~MapperInterface() {

}

void MapperInterface::addGenerator(PointCloudGenerator* gen) {
	this->generators.push_back(gen);
}
void MapperInterface::setRecorder(PointCloudRecorder* rec) {
	this->recorder = rec;
}
bool MapperInterface::generate() {
	for (int i = 0; i <int(generators.size()); i++) {
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return true;
}
bool MapperInterface::recordPointCloud() {
	recorder->setfileName("Output");
	recorder->save(pointCloud);
	return true;
}
bool MapperInterface::recordMap(string fileName) {
	map->saveMap(fileName);
	return true;
}
bool MapperInterface::insertMap() {
	map->loadMap(pointCloud);
	return true;
}