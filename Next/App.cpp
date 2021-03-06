#include <Next.hpp>
#include "App.hpp"

#include <Next.hpp>
#include <Engine.hpp>
#include <Window.hpp>
#include <Renderer.hpp>
#include "Viewport.hpp"
#include "FrameBuffer.hpp"
namespace LightPixel
{
	Application::Application(std::string const & name)
		: name_(name), total_num_frames_(0),
		fps_(0), accumulate_time_(0), num_frames_(0),
		app_time_(0), frame_time_(0)
	{
		Engine::Instance().AppInstance(*this);

		
		main_wnd_ = this->MakeWindow(name_, 800,600,false);

	}

	Application::Application(std::string const & name, void* native_wnd)
	{
	}


	Application::~Application()
	{
	}

	void Application::Create()
	{
		Engine::Instance().RendererInstance()->CreateRenderWindow();
	}

	void Application::Destroy()
	{
		OnDestroy();
	}

	void Application::Suspend()
	{
		OnSuspend();
	}

	void Application::Resume()
	{
		OnResume();
	}

	void Application::Refresh()
	{
		Engine::Instance().RendererInstance()->Refresh();
	}

	LightPixel::CameraPtr Application::ActiveCamera()
	{
		RendererPtr render = Engine::Instance().RendererInstance();
		CameraPtr  & camera = render->CurFrameBuffer()->GetViewport()->camera;
		//BOOST_ASSERT(camera);

		return camera;
	}

	LightPixel::WindowPtr Application::MakeWindow(std::string const & name, int w, int h, bool full_screen)
	{
		return std::shared_ptr<Window>(new Window(name, w, h, full_screen));
	
	}

	LightPixel::WindowPtr Application::MakeWindow(std::string const & name, void* native_wnd)
	{
		return std::shared_ptr<Window>(new Window(name, native_wnd));
	}

	uint32_t Application::TotalNumFrames() const
	{
		return 0;
	}

	float Application::FPS() const
	{
		return 0;
	}

	float Application::AppTime() const
	{
		return 0;
	}

	float Application::FrameTime() const
	{
		return 0;
	}

	void Application::Run()
	{
		

		bool gotMsg;
		MSG  msg;

		::PeekMessage(&msg, nullptr, 0, 0, PM_NOREMOVE);

		while (WM_QUIT != msg.message)
		{
			// 如果窗口是激活的，用 PeekMessage()以便我们可以用空闲时间渲染场景
			// 不然, 用 GetMessage() 减少 CPU 占用率
			if (main_wnd_->Active())
			{
				gotMsg = (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) != 0);
			}
			else
			{
				gotMsg = (::GetMessage(&msg, nullptr, 0, 0) != 0);
			}

			if (gotMsg)
			{
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
			else
			{
				this->Update();
			}
		}

		this->OnDestroy();
	}

	void Application::Quit()
	{
		::PostQuitMessage(0);
	}

	void Application::OnResize(uint32_t width, uint32_t height)
	{

	}

	void Application::Update()
	{
		this->UpdateStats();
		this->DoUpdate();

		RendererPtr render = Engine::Instance().RendererInstance();
		render->Refresh();
	
	}

	void Application::UpdateStats()
	{

	}

	void Application::LookAt(const Vec3 &eye, const Vec3 & lookAt, const Vec3 & up)
	{

	}

	void Application::Proj(float nearPlane, float farPlane)
	{

	}

}