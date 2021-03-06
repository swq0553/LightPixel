#pragma once

#include "Renderer.hpp"
#include "GLRenderContext.hpp"
class GLRenderer:public Renderer
{
public:
	GLRenderer();
	~GLRenderer();

	
	void DoCreateRenderContext();
	void ClearColor(const Color& clr);
private:
	GLRenderContextPtr mContex;
};

typedef std::shared_ptr<GLRenderer> GLRendererPtr;