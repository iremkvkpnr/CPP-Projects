//İrem Kavakpınar
#include "3DGridMap.h"
#include<string>
#include<iostream>
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include <iterator>
using namespace std;
//koordinatları verilen mapi döndurur.
bool* GridMap::getMap(int i, int j, int k) const {

	return (map + (i * depth * depth) + (j * depth) + k);
}
//gridsize'ı dondurur.
float GridMap::getGridSize() const {
	return gridSize;
}
//depthi dondurur.
int GridMap::getDepth() const {
	return depth;
}
//mapin koordinatlarını atar.
void GridMap::setMap(int i, int j, int k, bool value) {

	*(map + (i * depth * depth) + (j * depth) + k) = value;

}
//gridsize'ı atar.
void GridMap::setGridSize(float _gridSize) {
	gridSize = _gridSize;
}
//depthi atar.
void GridMap::setDepth(int _depth) {
	depth = _depth;
}
//verilen noktalar dizisinin denk geldiği küpü true olarak degistirir.
void GridMap::insertPointCloud(PointCloud& pc) {
	list<Point>::iterator iter;
	list<Point> p = pc.getPoints();
	for (iter = p.begin(); iter != p.end(); iter++)
	{
		double coordX;
		double coordY;
		double coordZ;



		coordX = iter->getX() / gridSize;
		coordY = iter->getY() / gridSize;
		coordZ = iter->getZ() / gridSize;

		int coordx, coordy, coordz;
		if (coordX - (int)coordX == 0)
		{
			coordx = (int)coordX;
		}
		else
		{
			coordx = (int)coordX;
			coordx++;
		}
		if (coordX - (int)coordX == 0)
		{
			coordy = (int)coordY;
		}
		else
		{
			coordy = (int)coordY;
			coordy++;
		}
		if (coordX - (int)coordX == 0)
		{
			coordz = (int)coordZ;
		}
		else
		{
			coordz = (int)coordZ;
			coordz++;
		}
		*(map + (coordx * depth * depth) + (coordy * depth) + coordz) = true;
	}

}
//verilen noktanın denk geldigi kupu true olarak degistirir.
void GridMap::insertPoint(Point& p) {
	double coordX;
	double coordY;
	double coordZ;

	coordX = p.getX() / gridSize;
	coordY = p.getY() / gridSize;
	coordZ = p.getZ() / gridSize;

	int coordx, coordy, coordz;
	if (coordX - (int)coordX == 0)
	{
		coordx = (int)coordX;
	}
	else
	{
		coordx = (int)coordX;
		coordx++;
	}
	if (coordX - (int)coordX == 0)
	{
		coordy = (int)coordY;
	}
	else
	{
		coordy = (int)coordY;
		coordy++;
	}
	if (coordX - (int)coordX == 0)
	{
		coordz = (int)coordZ;
	}
	else
	{
		coordz = (int)coordZ;
		coordz++;
	}
	*(map + (coordx * depth * depth) + (coordy * depth) + coordz) = true;

}
//koordinatları verilen grid'i dondurur.
bool GridMap::getGrid(int x, int y, int z) const {
	return*((map + (x * depth * depth) + (y * depth) + z));

}
//filename'i verilen dosyaya noktaları yukler.
bool GridMap::loadMap(PointCloud pc) {
	int count = 0;
	list<Point>* P = new list<Point>;
	*P = pc.getPoints();
	list<Point>::iterator iter;
	for (iter = P->begin(); iter != P->end(); iter++)
	{
		insertPoint(*iter);
	}
	return true;

}
//filename'i verilen dosyayı saveler.
bool GridMap::saveMap(string _fileName) {
	ofstream file;

	file.open(_fileName);
	file << gridSize;
	file << endl;
	file << depth;
	file << endl;
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < depth; j++)
		{
			for (int k = 0; k < depth; k++) {

				file << *(map + i * depth * depth + j * depth + k);
				file << endl;
			}
		}
	}
	return true;
}