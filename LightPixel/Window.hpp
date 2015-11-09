#ifndef _WINDOW_HPP
#define _WINDOW_HPP
#pragma once

#include <windows.h>
#include <stdint.h>
#include <string>
#include "Signals.hpp"


//namespace LightPixel 
//{	
	class Window
	{
	public:
		Window(std::string const & name,int w,int h,bool full_screen);
		Window(std::string const & name, void* native_wnd);
		~Window();

		void Recreate();

		HWND HWnd() const
		{
			return wnd_;
		}

		int32_t Left() const
		{
			return left_;
		}
		int32_t Top() const
		{
			return top_;
		}

		uint32_t Width() const
		{
			return width_;
		}
		uint32_t Height() const
		{
			return height_;
		}

		bool Active() const
		{
			return active_;
		}
		void Active(bool active)
		{
			active_ = active;
		}
		bool Ready() const
		{
			return ready_;
		}
		void Ready(bool ready)
		{
			ready_ = ready;
		}
		bool Closed() const
		{
			return closed_;
		}
		void Closed(bool closed)
		{
			closed_ = closed;
		}

	public:
		Signal<bool> ActiveEvent;
		Signal<> PaintEvent;
		Signal<> EnterSizeMoveEvent;
		Signal<> ExitSizeMoveEvent;
		Signal<bool> SizeEvent;
		Signal<> SetCursorEvent;
		Signal<wchar_t > CharEvent;
		Signal<HRAWINPUT > RawInputEvent;
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
		Signal<Window const & , HTOUCHINPUT , uint32_t > TouchEvent;
#endif
		Signal<int> MouseStateEvent;
		Signal<int> MouseButtonEvent;
		
		//Signal<ivec2 const & , uint32_t > PointerDownEvent;
		//Signal<Window const & , int2 const & , uint32_t > PointerUpEvent;
		//Signal<Window const & , int2 const & , uint32_t , bool > PointerUpdateEvent;
		//Signal<Window const & , int2 const & , uint32_t , int32_t > PointerWheelEvent;
		Signal<Window const & > CloseEvent;

	private:
		LRESULT MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		static 
		LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,WPARAM wParam, LPARAM lParam);

	private:
		int32_t  left_;
		int32_t  top_;
		uint32_t width_;
		uint32_t height_;

		bool active_;
		bool ready_;
		bool closed_;
		bool hide_;
		
		std::wstring wname_;

		HWND wnd_;
		WNDPROC default_wnd_proc_;

		bool external_wnd_;
	};
//}
#endif
