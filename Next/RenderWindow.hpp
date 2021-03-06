#ifndef _RENDERWINDOW_HPP
#define _RENDERWINDOW_HPP
#pragma once


#include <PreDeclare.hpp>
#include <windows.h>
#include "FrameBuffer.hpp"
namespace LightPixel
{
	class RenderWindow:public FrameBuffer
	{
	public:
		RenderWindow();
		~RenderWindow();

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
}
#endif

