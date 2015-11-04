#include "LightPixel.hpp"
#include "SceneManager.hpp"
#include "App.hpp"
#include "Camera.hpp"

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
	this->FlushScene();
	//���Ӳü�

	//��Ⱦ����

	//��Ⱦ����
	//RendererPtr render = Engine::Instance().RendererInstance();
	//auto item = mRenderQueue.begin();
	//for (; item != mRenderQueue.end(); ++item)
	//{
		//render.Render(item);
	//}
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
