#pragma once

class Engine
{
public:
	Engine();
	~Engine();

	static Engine& Instance();
	static void Destroy();

	void Init();

	InputPtr        InputInstance();
	ConfigPtr       ConfigInstance();
	
	Application&    AppInstance();
	void            AppInstance(Application& app);

	bool            RendererValid() const;
	RendererPtr     RendererInstance();
	SceneManagerPtr SceneManagerInstance();

	
private:
	static std::shared_ptr<Engine> engine_instance_;
	ConfigPtr           mCfg;	
	Application*		mApp;

	InputPtr            mInput;
	RendererPtr         mRenderer;
	SceneManagerPtr		mSceneMgr;
	
};

