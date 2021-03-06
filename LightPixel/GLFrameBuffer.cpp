#include "LightPixel.hpp"
#include "GLFrameBuffer.hpp"


GLFrameBuffer::GLFrameBuffer(bool off_screen)
	:FrameBuffer(off_screen)
{
	left_ = 0;
	top_ = 0;

	if (off_screen)
	{
		glGenFramebuffers(1, &fbo_);
	}
	else
	{
		fbo_ = 0;
	}
}


GLFrameBuffer::~GLFrameBuffer()
{
	if (fbo_ != 0)
	{
		if (Engine::Instance().RendererValid())
		{
			RendererPtr re = Engine::Instance().RendererInstance();
			//re.DeleteFramebuffers(1, &fbo_);
		}
// 		if (Context::Instance().RenderFactoryValid())
// 		{
// 			OGLRenderEngine& re = *checked_cast<OGLRenderEngine*>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
// 			re.DeleteFramebuffers(1, &fbo_);
// 		}
		else
		{
			glDeleteFramebuffers(1, &fbo_);
		}
	}
}

void GLFrameBuffer::Clear(uint32_t flags, Color const & clr, float depth, int32_t stencil)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(clr[0], clr[1], clr[2], clr[3]);
}

void GLFrameBuffer::OnBind()
{

}
