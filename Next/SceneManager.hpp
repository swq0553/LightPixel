#ifndef _SCENEMANAGER_HPP
#define _SCENEMANAGER_HPP
#pragma once

namespace LightPixel
{
	class SceneManager
	{
	protected:
		//typedef std::vector<SceneObjectPtr> SceneObjsType;
		//typedef std::vector<RenderablePtr> RenderItemsType;
		//typedef std::vector<std::pair<RenderTechniquePtr, RenderItemsType>> RenderQueueType;
	public:
		SceneManager();
		~SceneManager();

		void Init();
		void Update();
	private:
		void FlushScene();
		std::vector<RenderablePtr> mRenderQueue;
	};
}
#endif
