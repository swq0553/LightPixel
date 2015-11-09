#include "LightPixel.hpp"

#include "App.hpp"
#include <Input.hpp>
#include <Engine.hpp>
#include <Window.hpp>
#include "Config.hpp"
#include "Renderer.hpp"

Application::Application(std::string const & name)
{
	Engine::Instance().AppInstance(*this);
	ConfigPtr cfg = Engine::Instance().ConfigInstance();

	mMain_wnd = this->MakeWindow(name, cfg->width, cfg->height, false);
	
}

Application::Application(std::string const & name, void* native_wnd)
{
	Engine::Instance().AppInstance(*this);
	ConfigPtr cfg = Engine::Instance().ConfigInstance();

	mMain_wnd = this->MakeWindow(name, native_wnd);

}


Application::~Application()
{
}

void Application::Create()
{
	Engine::Instance().InputInstance()->Init();
	Engine::Instance().RendererInstance()->CreateRenderContext();
	
	this->OnCreate();
	ConfigPtr cfg = Engine::Instance().ConfigInstance();
	this->OnResize(cfg->width, cfg->height);
}

void Application::Destroy()
{
	this->OnDestroy();
}

void Application::Suspend()
{
	this->OnSuspend();
}

void Application::Resume()
{
	this->OnResume();
}

void Application::Refresh()
{
	//Engine::Instance().RendererInstance()->Refresh();
}

void Application::Run()
{
	RendererPtr render = Engine::Instance().RendererInstance();

	bool gotMsg;
	MSG  msg;

	::PeekMessage(&msg, nullptr, 0, 0, PM_NOREMOVE);

	while (WM_QUIT != msg.message)
	{
		// 如果窗口是激活的，用 PeekMessage()以便我们可以用空闲时间渲染场景
		// 不然, 用 GetMessage() 减少 CPU 占用率
		if (mMain_wnd->Active())
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
			
		}
		render->Refresh();
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

WindowPtr const & Application::MainWnd() const
{
	return mMain_wnd;
}

WindowPtr Application::MakeWindow(std::string const & name, void* native_wnd)
{
	return std::shared_ptr<Window>(new Window(name, native_wnd));
}

WindowPtr Application::MakeWindow(std::string const & name, int w, int h, bool full_screen)
{
	return std::shared_ptr<Window>(new Window(name, w, h, full_screen));
}

void Application::Update()
{
	this->UpdateStats();
	this->DoUpdate();
}

void Application::UpdateStats()
{

}

