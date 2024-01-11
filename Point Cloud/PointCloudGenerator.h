#pragma once
#include "Transform.h"
class PointCloudGenerator {
private:
	Transform transform;
public:
	PointCloudGenerator();
	~PointCloudGenerator();
	void setTransform(Transform);
	Transform getTransform();
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};
