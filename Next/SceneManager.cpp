#include "Next.hpp"
#include "SceneManager.hpp"

namespace LightPixel
{
	SceneManager::SceneManager()
	{
	}


	SceneManager::~SceneManager()
	{
	}

	void SceneManager::Init()
	{

	}

	void SceneManager::Update()
	{
		//���Ӳü�

		//��Ⱦ����

		//��Ⱦ����
 		RendererPtr render = Engine::Instance().RendererInstance();
		auto item = mRenderQueue.begin();
 		for (; item != mRenderQueue.end(); ++item)
 		{
			//render.Render(item);
 		}
	}

	void SceneManager::FlushScene()
	{

	}

}
