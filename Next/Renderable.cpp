#include "Next.hpp"
#include "Renderable.hpp"


#include "Camera.hpp"

namespace LightPixel
{
	Renderable::Renderable(void)
		:mModelMatrix(1.0)
	{
	}


	Renderable::~Renderable(void)
	{
	}

	void Renderable::Render()
	{
		this->DoRenderBegin();
		this->DoRender();
		this->DoRenderEnd();
	}

	void Renderable::DoRender()
	{


	}

	void Renderable::DoRenderBegin()
	{


	}

	void Renderable::DoRenderEnd()
	{

	}

	Technique* Renderable::GetTechnique()
	{
		return mTech;
	}

	void Renderable::SetModelMtrix(Mat4 modelmatrix)
	{
		mModelMatrix = modelmatrix;
	}
}