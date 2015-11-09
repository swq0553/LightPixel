#include "LightPixel.hpp"
#include "SceneManager.hpp"
#include "App.hpp"
#include "Camera.hpp"
#include "Renderable.hpp"

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
	
	//¿ÉÊÓ²Ã¼ô

	//äÖÈ¾ÅÅÐò

	//äÖÈ¾ÎïÌå
	//RendererPtr render = Engine::Instance().RendererInstance();
	//auto item = mRenderQueue.begin();
	//for (; item != mRenderQueue.end(); ++item)
	//{
		//render.Render(item);
	//}

	
	for (RenderablePtr &item : mQueue)
	{
		item->Render();
		std::cout << "test" << std::endl;
	}
	this->FlushScene();
}

void SceneManager::FlushScene()
{
	Application& app = Engine::Instance().AppInstance();
	app.Update();
}

void SceneManager::SetCamera(CameraPtr camera)
{
	mCamera = camera;
}

CameraPtr SceneManager::GetCamera()
{
	return mCamera;
}

void SceneManager::AddRenderable(RenderablePtr obj)
{
	mQueue.push_back(obj);
}
