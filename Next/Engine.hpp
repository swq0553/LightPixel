#ifndef _ENGINE_HPP
#define _ENGINE_HPP
#pragma once

#include <PreDeclare.hpp>

namespace LightPixel
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		static Engine& Instance();
		static void Destroy();

		void Init();

		void AppInstance(Application& app)
		{
			app_ = &app;
		}
		bool AppValid() const
		{
			return app_ != nullptr;
		}
		Application& AppInstance()
		{
			return *app_;
		}

		bool SceneManagerValid() const
		{
			return !!scene_mgr_;
		}
		SceneManagerPtr SceneManagerInstance()
		{
			return scene_mgr_;
		}
		bool RendererValid() const
		{
			return !!renderer_;
		}
		RendererPtr RendererInstance()
		{
			return renderer_;
		}
	private:
		static std::shared_ptr<Engine> engine_instance_;

		Application*		app_;
		SceneManagerPtr		scene_mgr_;
		RendererPtr         renderer_;
	};
}

#endif

