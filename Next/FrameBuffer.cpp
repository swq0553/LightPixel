#include "Next.hpp"
#include "FrameBuffer.hpp"
#include "Engine.hpp"
#include "Util.hpp"
#include "Viewport.hpp"
#include "Renderer.hpp"
namespace LightPixel
{
	FrameBuffer::FrameBuffer(bool off_screen)
	: viewport_(MakeSharedPtr<Viewport>())
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


	FrameBuffer::~FrameBuffer()
	{
		if (fbo_ != 0)
		{
			if (Engine::Instance().RendererValid())
			{				
				RendererPtr re = Engine::Instance().RendererInstance();
				//re.DeleteFramebuffers(1, &fbo_);
			}
			else
			{
				glDeleteFramebuffers(1, &fbo_);
			}
		}
	}

	uint32_t FrameBuffer::Left() const
	{
		return left_;
	}

	uint32_t FrameBuffer::Top() const
	{
		return top_;
	}

	uint32_t FrameBuffer::Width() const
	{
		return width_;
	}

	uint32_t FrameBuffer::Height() const
	{
		return height_;
	}

	ViewportPtr& FrameBuffer::GetViewport()
	{
		return viewport_;
	}

	void FrameBuffer::SetViewport(const ViewportPtr & viewport)
	{
		viewport_ = viewport;
	}

	void FrameBuffer::OnBind()
	{
	
	}

	void FrameBuffer::OnUnbind()
	{

	}

	void FrameBuffer::SwapBuffers()
	{

	}

	void FrameBuffer::Clear(uint32_t flags, const Color & clr, float depth, int32_t stencil)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(clr[0], clr[1], clr[2], clr[3]);
	}

	void FrameBuffer::Discard(uint32_t flags)
	{

	}




}