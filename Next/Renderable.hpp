#ifndef _Renderable_HPP
#define _Renderable_HPP
#pragma once

#include <PreDeclare.hpp>
#include <vector>
#include <string>
namespace LightPixel
{
	typedef std::vector<std::string> TextureSrc;
	struct  RenderMaterial
	{
		std::string id;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		glm::vec3 emit;
		float opacity;
		float specular_level;
		float shininess;

		TextureSrc textures;
	};
	class Technique;
	class BoundingBox;
	class Renderable
	{
		typedef std::shared_ptr<Technique>  TechniquePtr;
	public:
		Renderable(void);
		~Renderable(void);

		Technique* GetTechnique();
		void SetModelMtrix(Mat4 modelmatrix);
		void Render();
		virtual void DoRender();
		virtual void DoRenderBegin();
		virtual void DoRenderEnd();

		virtual BoundingBox* GetBoundingBox() = 0;
		inline RenderMaterial GetMaterial(){ return mMtl; };
	protected:
		Technique*     mTech;
		RenderMaterial mMtl;
		Mat4           mModelMatrix;
	};
}
#endif