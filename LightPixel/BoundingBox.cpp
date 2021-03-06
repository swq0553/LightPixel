#include "LightPixel.hpp"
#include "BoundingBox.hpp"

BoundingBox::BoundingBox()
	: mCenter(0, 0, 0)
	, mMin(0, 0, 0)
	, mMax(0, 0, 0)
	, mRadius(0)
{
}

BoundingBox::~BoundingBox()
{

}

//buf为顶点数据指针，size为数据个数 顶点数为(size/4)/3
void BoundingBox::Compute(float*buf, uint32_t size)
{
	float minX, minY, minZ;
	float maxX, maxY, maxZ;
	minX = maxX = buf[0];
	minY = maxY = buf[1];
	minZ = maxZ = buf[2];
	for (uint32_t i = 0; i < size; i += 12)
	{
		buf += 12;
		minX = std::min(minX, buf[0]);
		minY = std::min(minY, buf[1]);
		minZ = std::min(minZ, buf[2]);
		maxX = std::max(maxX, buf[0]);
		maxY = std::max(maxY, buf[1]);
		maxZ = std::max(maxZ, buf[2]);
	}

	mMin = Vec3(minX, minY, minZ);
	mMax = Vec3(maxX, maxY, maxZ);
	mCenter = Vec3((maxX - minX) / 2, (maxY - minY) / 2, (maxX - minX) / 2);

	mRadius = mCenter.length();
}

void BoundingBox::Combine(BoundingBox box)
{
	float minX = std::min(mMin[0], box.mMin[0]);
	float minY = std::min(mMin[1], box.mMin[1]);
	float minZ = std::min(mMin[2], box.mMin[2]);
	float maxX = std::max(mMax[0], box.mMax[0]);
	float maxY = std::max(mMax[1], box.mMax[1]);
	float maxZ = std::max(mMax[2], box.mMax[2]);

	mMin = Vec3(minX, minY, minZ);
	mMax = Vec3(maxX, maxY, maxZ);
	mCenter = Vec3((maxX - minX) / 2, (maxY - minY) / 2, (maxX - minX) / 2);

	mRadius = mCenter.length();
}

Vec3 BoundingBox::Center()
{
	return mCenter;
}

float BoundingBox::Radius()
{
	return mRadius;
}
