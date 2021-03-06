#pragma once

#include "GLFrameBuffer.hpp"
class GLRenderWindow:public GLFrameBuffer
{
public:
	GLRenderWindow();
	~GLRenderWindow();
	void OnActive(bool active);
	void OnPaint();
	void OnEnterSizeMove();
	void OnExitSizeMove();
	void OnSize(bool active);;
	void OnClose();

	void WindowMovedOrResized();
	void Reposition(uint32_t left, uint32_t top);
	void SwapBuffers();
	bool Ready() const
	{
		return ready_;
	}

	void Ready(bool ready)
	{
		ready_ = ready;
	}
	bool Active()
	{
		return active_;
	}


private:

	HWND	hWnd_;
	HGLRC	hRC_;
	HDC		hDC_;


	bool	ready_;
	bool	active_;
};

