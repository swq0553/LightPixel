#include "LightPixel.hpp"
#include "Renderable.hpp"


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

RenderTechniquePtr Renderable::GetTechnique()
{
	return mTech;
}

void Renderable::SetModelMtrix(Mat4 modelmatrix)
{
	mModelMatrix = modelmatrix;
}
