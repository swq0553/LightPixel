// LightPixel.cpp : 定义控制台应用程序的入口点。
//

#include "LightPixel.hpp"
#include <App.hpp>
#include "Util.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "FrameBuffer.hpp"
#include "RenderableHelper.hpp"

#include "SceneManager.hpp"
#include "Camera.hpp"

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
	CameraPtr camera = MakeSharedPtr<Camera>();
	camera->LookAt(Vec3(1,0,1),Vec3(0),Vec3(0,1,0));
	camera->Project(60.0f, 1.0f, 0.1f, 1000.0f);
	Engine::Instance().SceneManagerInstance()->SetCamera(camera);

	RenderableTrianglePtr triangle = MakeSharedPtr<RenderableTriangle>(Vec3(0, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, 1), Color(1.0, 0.0, 0.0, 1.0));
	Engine::Instance().SceneManagerInstance()->AddRenderable(triangle);
	
}

#ifdef SHIPPING
#pragma comment(linker,"/subsystem:windows /entry:mainCRTStartup")
#endif // SHIPPING

int main(int argc, _TCHAR* argv[])
{
	Test app;
	app.Create();
	app.Run();
}

