#include "PointCloudGenerator.h"
#include <iostream>
PointCloudGenerator::PointCloudGenerator() {

}
PointCloudGenerator:: ~PointCloudGenerator() {

}
void PointCloudGenerator::setTransform(Transform T) {
	transform = T;
}
Transform PointCloudGenerator::getTransform() {
	return transform;
}