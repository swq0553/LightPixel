#pragma once
#include "PreDeclare.hpp"
#include "Renderable.hpp"
#include "BoundingBox.hpp"
#include "ResLoader.hpp"
#include "RenderEffect.hpp"
class RenderableHelper : public Renderable
{
public:
	RenderableHelper();
	virtual ~RenderableHelper();

	virtual RenderTechniquePtr GetTechnique() ;
	virtual BoundingBoxPtr  GetBoundingBox() ;
	virtual RenderLayoutPtr GetRenderLayout();
protected:
	BoundingBoxPtr pos_aabb_;
	

	RenderLayoutPtr rl_;
};


class  RenderableTriangle : public RenderableHelper
{
public:
	explicit RenderableTriangle();
	RenderableTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, const Color& clr);
	virtual ~RenderableTriangle()	{}

	void SetTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2);
	void SetColor(const Color  & clr);

	void DoRenderBegin();
	void DoRender();
private:
	void Init();
 	GraphicsBufferPtr vbo;
	ProgramPtr mProgram;
	EffectLoader fx;
};