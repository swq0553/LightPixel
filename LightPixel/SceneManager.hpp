#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void Init();
	void Update();

	void      SetCamera(CameraPtr camera);
	CameraPtr GetCamera();
private:
	void FlushScene();

private:
	CameraPtr mCamera;
};

