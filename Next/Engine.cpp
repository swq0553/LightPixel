#include "Next.hpp"
#include "Engine.hpp"

#include <windows.h>

#include "Renderer.hpp"
#include "SceneManager.hpp"

namespace LightPixel
{
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

	void Engine::Destroy()
	{

	}

	void Engine::Init()
	{
		renderer_ = std::shared_ptr<Renderer>(new Renderer());
		renderer_->Init();

		scene_mgr_ = std::shared_ptr<SceneManager>(new SceneManager());
		scene_mgr_->Init();
	}

}