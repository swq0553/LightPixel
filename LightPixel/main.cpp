// LightPixel.cpp : 定义控制台应用程序的入口点。
//

#include "LightPixel.hpp"
#include <App.hpp>
#include "Window.hpp"
#include "Renderer.hpp"
#include "FrameBuffer.hpp"

class Test :public Application
{
public:
	Test();
	~Test();
	void     OnCreate();
	uint32_t DoUpdate();
private:

};

Test::Test()
	:Application("Test")
{
}

Test::~Test()
{
}

uint32_t Test::DoUpdate()
{
	RendererPtr render = Engine::Instance().RendererInstance();
	Color clear_clr(0.2f, 0.4f, 0.6f, 1);
	render->ClearColor(clear_clr);

	return 0;
}

void Test::OnCreate()
{
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test app;
	app.Create();
	app.Run();
}

