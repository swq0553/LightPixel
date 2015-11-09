#pragma once
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


class Renderable
{	
public:
	Renderable(void);
	~Renderable(void);

	RenderTechniquePtr GetTechnique();
	void SetModelMtrix(Mat4 modelmatrix);
	void Render();
	virtual void DoRender();
	virtual void DoRenderBegin();
	virtual void DoRenderEnd();

	virtual BoundingBoxPtr  GetBoundingBox()  = 0;
	virtual RenderLayoutPtr GetRenderLayout() = 0;
	inline  RenderMaterial   GetMaterial(){ return mMtl; };
protected:
	RenderTechniquePtr     mTech;
	RenderMaterial         mMtl;
	Mat4                   mModelMatrix;
};

