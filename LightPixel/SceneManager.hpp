#pragma once
class SceneManager
{
	typedef std::vector<RenderablePtr> RenderItemsType;
	//typedef std::vector<std::pair<RenderTechniquePtr, RenderItemsType>> RenderQueueType;
	typedef std::vector<RenderablePtr> RenderQueueType;
public:
	SceneManager();
	~SceneManager();
	void Init();
	void Update();

	void      AddRenderable(RenderablePtr obj);
	void      SetCamera(CameraPtr camera);
	CameraPtr GetCamera();
private:
	void FlushScene();

private:
	CameraPtr mCamera;
	RenderQueueType mQueue;
};

