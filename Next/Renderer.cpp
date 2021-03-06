#include "Next.hpp"
#include "Renderer.hpp"

#include "App.hpp"
#include "Util.hpp"
#include "Window.hpp"
#include "RenderWindow.hpp"
#include "SceneManager.hpp"

namespace LightPixel
{
	Renderer::Renderer()
	{
	}


	Renderer::~Renderer()
	{
	}

	void Renderer::Init()
	{

	}

	void Renderer::Refresh()
	{		
		if (Engine::Instance().AppInstance().MainWnd()->Active())
		{
			Engine::Instance().SceneManagerInstance()->Update();
			screen_frame_buffer_->SwapBuffers();
		}

		
	}

	void Renderer::CreateRenderWindow()
	{
		cur_frame_buffer_ = MakeSharedPtr<RenderWindow>();
		screen_frame_buffer_ = cur_frame_buffer_;
		
	}

	const FrameBufferPtr & Renderer::CurFrameBuffer() const
	{
		return cur_frame_buffer_;
	}

	void Renderer::BindFrameBuffer(const FrameBufferPtr & fb)
	{
		cur_frame_buffer_ = fb;
	}

}