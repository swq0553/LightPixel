#pragma once
class BoundingBox
{	
public:
	BoundingBox();
	~BoundingBox();
	void  Compute(float*buf, uint32_t size);
	void  Combine(BoundingBox box);
	Vec3  Center();
	float Radius();
private:
	Vec3  mCenter;
	Vec3  mMin;
	Vec3  mMax;
	float mRadius;
};

