#include "LightPixel.hpp"
#include "App.hpp"
#include "Engine.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "FrameBuffer.hpp"
#include "SceneManager.hpp"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}


void Renderer::Refresh()
{
	if (Engine::Instance().AppInstance().MainWnd()->Active())
	{
		Engine::Instance().SceneManagerInstance()->Update();		
	}
}

void Renderer::CreateRenderContext()
{
	this->DoCreateRenderContext();	
}
