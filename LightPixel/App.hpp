#pragma once

#include <string>
#include <stdint.h>
class Application
{
public:
	explicit Application(std::string const & name);
	Application(std::string const & name, void* native_wnd);
	virtual ~Application();

	void Create();
	void Destroy();
	void Suspend();
	void Resume();
	void Refresh();

	void Run();
	void Quit();

	virtual void OnResize(uint32_t width, uint32_t height);	
	
	WindowPtr const & MainWnd() const;
	WindowPtr MakeWindow(std::string const & name, void* native_wnd);
	WindowPtr MakeWindow(std::string const & name, int w, int h, bool full_screen);

	void Update();
	void UpdateStats();
private:
	virtual void OnCreate()	{}
	virtual void OnDestroy(){}
	virtual void OnSuspend(){}
	virtual void OnResume() {}

	//virtual void DoUpdateOverlay() = 0;
	virtual uint32_t DoUpdate() = 0;
protected:
	std::string mName;
	WindowPtr   mMain_wnd;
};

