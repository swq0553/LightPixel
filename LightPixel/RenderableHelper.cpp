#include "LightPixel.hpp"
#include "RenderableHelper.hpp"

#include "PreDeclare.hpp"
#include "Util.hpp"
#include "GraphicsBuffer.hpp"
#include "RenderEffect.hpp"
#include "SceneManager.hpp"
#include "Camera.hpp"

RenderableHelper::RenderableHelper()	
{
}


RenderableHelper::~RenderableHelper()
{
}

RenderTechniquePtr RenderableHelper::GetTechnique()
{
	return mTech;
}

BoundingBoxPtr RenderableHelper::GetBoundingBox()
{
	return pos_aabb_;
}

RenderLayoutPtr RenderableHelper::GetRenderLayout()
{
	return rl_;
}

//RenderableTriangle
RenderableTriangle::RenderableTriangle()
{
	this->Init();
}

RenderableTriangle::RenderableTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, const Color& clr)
{
	this->Init();

	this->SetTriangle(v0, v1, v2);
	this->SetColor(clr);
}

void RenderableTriangle::Init()
{
 	EffectLoader fx = EffectLoader::Instance();
 	mTech = fx.ParseEffect("../media/RenderHelper.fx");

// 
    mProgram = mTech->GetPass(0)->GetProgram();
    mProgram->link();
    mProgram->use();

 	float vertices[] = { 0, 1, 2 };
 	vbo = MakeSharedPtr<GraphicsBuffer>(GraphicsBuffer::VertexBuffer);
 	vbo->Create();
 	vbo->Bind();
 	vbo->Allocate(vertices, 3 * sizeof(float));
 
 	int loc = mProgram->getGetAttribLocation("VertexPosition");
 	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 1, GL_FLOAT, GL_FALSE, 0, NULL);
	
	Vec3 color( 1.0f, 0.0f, 0.0f );
	mProgram->setUniform("color",  color);
	GLfloat vertexData[] =
	{
		0.0f, 0.8f, 0.0f,
		-0.8f, -0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
	};
	mProgram->setUniform3fv("position", 3, vertexData);
}

void RenderableTriangle::SetTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2)
{
// 	Vec3 pos[] = {v0,v1,v2};
// 	ProgramPtr shader = mTech->GetPass(0)->GetProgram();
// 	shader->use();
// 	shader->setUniform3fv("position", 3, &pos[0][0]);
}

void RenderableTriangle::SetColor(const Color & clr)
{
	//ProgramPtr shader = mTech->GetPass(0)->GetProgram();
	//shader->use();
	//shader->setUniform("color", clr);
}

void RenderableTriangle::DoRenderBegin()
{
	
}

void RenderableTriangle::DoRender()
{
  	vbo->Bind();
 	mProgram->use();
 	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	
}
