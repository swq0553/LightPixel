#include "LightPixel.hpp"
#include "GLRenderer.hpp"
#include "Util.hpp"
#include "GLRenderContext.hpp"

GLRenderer::GLRenderer()
	:Renderer()
{
}


GLRenderer::~GLRenderer()
{
}

void GLRenderer::DoCreateRenderContext()
{	
	mContex = MakeSharedPtr<GLRenderContext>();

}

void GLRenderer::ClearColor(const Color& clr)
{
	glClearColor(clr[0], clr[1], clr[2], clr[3]);
}

