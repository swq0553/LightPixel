#include "LightPixel.hpp"
#include "Engine.hpp"
#include "Util.hpp"
#include "Input.hpp"
#include "Config.hpp"
#include "SceneManager.hpp"

#include "GLRenderer.hpp"
std::shared_ptr<Engine> Engine::engine_instance_;

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

Engine& Engine::Instance()
{
	if (!engine_instance_)
	{
		//lock_guard<mutex> lock(singleton_mutex);
		if (!engine_instance_)
		{
			engine_instance_ = std::shared_ptr<Engine>(new Engine());
		}
	}
	return *engine_instance_;
}

void Engine::Init()
{
	mCfg      = MakeSharedPtr<Config>();
	mInput    = MakeSharedPtr<Input>();
	mSceneMgr = MakeSharedPtr<SceneManager>();

	if (mCfg->render_name == "GLES")
	{
		//mRenderer = MakeSharedPtr<GLESRenderer>()
	}
	else 
	{
		mRenderer = MakeSharedPtr<GLRenderer>();
	}
}

void Engine::Destroy()
{

}

void Engine::AppInstance(Application& app)
{
	mApp = &app;
}

Application& Engine::AppInstance()
{
	return *mApp;
}


InputPtr Engine::InputInstance()
{
	return mInput;
}

ConfigPtr Engine::ConfigInstance()
{
	return mCfg;
}


SceneManagerPtr Engine::SceneManagerInstance()
{
	return mSceneMgr;
}

RendererPtr Engine::RendererInstance()
{
	return mRenderer;
}

bool Engine::RendererValid() const
{
	return !!mRenderer;
}
