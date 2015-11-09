#include "LightPixel.hpp"
#include "Input.hpp"

#include "App.hpp"
#include "Engine.hpp"
#include "Window.hpp"
#include "Signals.hpp"
Input::Input()
{
	
}


void Input::Init()
{
	WindowPtr win = Engine::Instance().AppInstance().MainWnd();

	//callback 				
	win->MouseStateEvent.connect(std::bind(&Input::SetMouseState, this, std::placeholders::_1));
	win->MouseButtonEvent.connect(std::bind(&Input::SetMouseButton, this, std::placeholders::_1));
}

Input::~Input()
{
}

int Input::GetMouseX()
{
	return mouse_x;
}

int Input::GetMouseY()
{
	return mouse_y;
}

void Input::SetMouse(int x, int y)
{

}

int Input::GetMouseWheel()
{
	return mouse_wheel;
}

void Input::SetMouseWheel(int wheel)
{

}

int Input::GetMouseButton()
{
	return mouse_button;
}

void Input::SetMouseButton(int button)
{
	mouse_button = button;
}

int Input::GetMouseState()
{
	return mouse_state;
}

void Input::SetMouseState(int state)
{
	mouse_state = state;
}
