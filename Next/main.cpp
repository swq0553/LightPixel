#include<stdio.h>
#include "Next.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "FrameBuffer.hpp"
#include <App.hpp>
using namespace LightPixel;

class Test :public LightPixel::Application
{
public:
	Test();
	~Test();
	uint32_t DoUpdate();
private:

};

Test::Test()
	:LightPixel::Application("Test")
{
}

Test::~Test()
{
}

uint32_t Test::DoUpdate()
{
	RendererPtr render = Engine::Instance().RendererInstance();

	Color clear_clr(0.2f, 0.4f, 0.6f, 1);
	
	render->CurFrameBuffer()->Clear(1,clear_clr, 1.0f, 0);
	return 0;
}

void main(){

	Test app;
	app.Create();
	app.Run();
}