#include <LightPixel.hpp>
#include <Window.hpp>

#include <Util.hpp>
#include <Input.hpp>

#include <windowsx.h>
//namespace LightPixel
//{
	LRESULT Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
#pragma warning(push)
#pragma warning(disable: 4312)
		Window* win = reinterpret_cast<Window*>(::GetWindowLongPtrW(hWnd, GWLP_USERDATA));
#pragma warning(pop)

		if (win != nullptr)
		{
			return win->MsgProc(hWnd, uMsg, wParam, lParam);
		}
		else
		{
			return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}

	Window::Window(std::string const & name, int w, int h, bool full_screen)
		: active_(false), ready_(false), closed_(false)
	{
		HINSTANCE hInst = ::GetModuleHandle(nullptr);

		// Register the window class
		Convert(wname_, name);
		
		WNDCLASSEXW wc;
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(this);
		wc.hInstance = hInst;
		wc.hIcon = nullptr;
		wc.hCursor = ::LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = static_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = wname_.c_str();
		wc.hIconSm = nullptr;
		::RegisterClassExW(&wc);

		uint32_t style;		
		if (full_screen)
		{
			style = WS_POPUP;
		}
		else
		{
			style = WS_OVERLAPPEDWINDOW;
		}

		RECT rc = { 0, 0, w, h };
		::AdjustWindowRect(&rc, style, false);

		// Create our main window
		// Pass pointer to self
		wnd_ = ::CreateWindowW(wname_.c_str(), wname_.c_str(),
			style, 0, 0,
			rc.right - rc.left, rc.bottom - rc.top, 0, 0, hInst, nullptr);

		default_wnd_proc_ = ::DefWindowProc;
		external_wnd_ = false;

		::GetClientRect(wnd_, &rc);
		left_ = 0;
		top_ = 0;
		width_ = rc.right - rc.left;
		height_ = rc.bottom - rc.top;


#pragma warning(push)
#pragma warning(disable: 4244)
		::SetWindowLongPtrW(wnd_, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
#pragma warning(pop)


		::ShowWindow(wnd_, SW_HIDE);
		::UpdateWindow(wnd_);
	}

	Window::Window(std::string const & name, void* native_wnd)
	{

	}

	Window::~Window()
	{
		if (wnd_ != nullptr)
		{
#pragma warning(push)
#pragma warning(disable: 4244)
			::SetWindowLongPtrW(wnd_, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(nullptr));
#pragma warning(pop)

			if (!external_wnd_)
			{
				::DestroyWindow(wnd_);
			}

			wnd_ = nullptr;
		}
	}

	void Window::Recreate()
	{
		if (!external_wnd_)
		{
			HINSTANCE hInst = ::GetModuleHandle(nullptr);

			uint32_t style = static_cast<uint32_t>(::GetWindowLongPtrW(wnd_, GWL_STYLE));
			RECT rc = { 0, 0, static_cast<LONG>(width_), static_cast<LONG>(height_) };
			::AdjustWindowRect(&rc, style, false);

			::DestroyWindow(wnd_);

			wnd_ = ::CreateWindowW(wname_.c_str(), wname_.c_str(),
				style, left_, top_,
				rc.right - rc.left, rc.bottom - rc.top, 0, 0, hInst, nullptr);

			::GetClientRect(wnd_, &rc);
			width_ = rc.right - rc.left;
			height_ = rc.bottom - rc.top;


#pragma warning(push)
#pragma warning(disable: 4244)
			::SetWindowLongPtrW(wnd_, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
#pragma warning(pop)


			::ShowWindow(wnd_, SW_SHOWNORMAL);
			::UpdateWindow(wnd_);
		}
	}

	LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_ACTIVATE:
			active_ = (WA_INACTIVE != LOWORD(wParam));
			this->ActiveEvent(/**this,*/ active_);
			break;

		case WM_ERASEBKGND:
			return 1;

		case WM_PAINT:
			this->PaintEvent();
			break;

		case WM_ENTERSIZEMOVE:
			// Previent rendering while moving / sizing
			ready_ = false;
			this->EnterSizeMoveEvent();
			break;

		case WM_EXITSIZEMOVE:
			this->ExitSizeMoveEvent();
			ready_ = true;
			break;

		case WM_SIZE:
			// Check to see if we are losing or gaining our window.  Set the
			// active flag to match
			if ((SIZE_MAXHIDE == wParam) || (SIZE_MINIMIZED == wParam))
			{
				active_ = false;
				this->SizeEvent( false);
			}
			else
			{
				active_ = true;
				this->SizeEvent(true);
			}
			break;

		case WM_GETMINMAXINFO:
			// Prevent the window from going smaller than some minimu size
			reinterpret_cast<MINMAXINFO*>(lParam)->ptMinTrackSize.x = 100;
			reinterpret_cast<MINMAXINFO*>(lParam)->ptMinTrackSize.y = 100;
			break;

		case WM_SETCURSOR:
			this->SetCursorEvent();
			break;

		case WM_CHAR:
			this->CharEvent(static_cast<wchar_t>(wParam));
			break;

		case WM_INPUT:
			this->RawInputEvent(reinterpret_cast<HRAWINPUT>(lParam));
			break;

	//Mouse
		case WM_LBUTTONDBLCLK:		
			this->MouseStateEvent(Input::BUTTON_DCLICK);
			this->MouseButtonEvent(Input::BUTTON_LEFT);
			break;		
		case WM_LBUTTONDOWN:			
			this->MouseStateEvent(Input::BUTTON_DOWN);
			this->MouseButtonEvent(Input::BUTTON_LEFT);
			break;			
		case WM_LBUTTONUP:
			this->MouseStateEvent(Input::BUTTON_UP);
			this->MouseButtonEvent(Input::BUTTON_LEFT);
			break;
		case WM_RBUTTONDBLCLK:
			this->MouseStateEvent(Input::BUTTON_DCLICK);
			this->MouseButtonEvent(Input::BUTTON_RIGHT);
			break;
		case WM_RBUTTONDOWN:
			this->MouseStateEvent(Input::BUTTON_DOWN);
			this->MouseButtonEvent(Input::BUTTON_RIGHT);
			break;
		case WM_RBUTTONUP:
			this->MouseStateEvent(Input::BUTTON_UP);
			this->MouseButtonEvent(Input::BUTTON_RIGHT);
			break;
		case WM_MBUTTONDBLCLK:
			this->MouseStateEvent(Input::BUTTON_DCLICK);
			this->MouseButtonEvent(Input::BUTTON_MIDDLE);
			break;
		case WM_MBUTTONDOWN:
			this->MouseStateEvent(Input::BUTTON_DOWN);
			this->MouseButtonEvent(Input::BUTTON_MIDDLE);
			break;
		case WM_MBUTTONUP:
			this->MouseStateEvent(Input::BUTTON_UP);
			this->MouseButtonEvent(Input::BUTTON_MIDDLE);
			break;

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8)
		case WM_POINTERDOWN:
		{
			POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
			::ScreenToClient(this->HWnd(), &pt);
			//this->PointerDowEvent(*this, int2(pt.x, pt.y), GET_POINTERID_WPARAM(wParam));
		}
			break;

		case WM_POINTERUP:
		{
			POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
			::ScreenToClient(this->HWnd(), &pt);
			//this->PointerUpEvent(*this, int2(pt.x, pt.y), GET_POINTERID_WPARAM(wParam));
		}
			break;

		case WM_POINTERUPDATE:
		{
			POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
			::ScreenToClient(this->HWnd(), &pt);
			//this->PointerUpdateEvent(*this, int2(pt.x, pt.y), GET_POINTERID_WPARAM(wParam),
			//						 IS_POINTER_INCONTACT_WPARAM(wParam));
		}
			break;

		case WM_POINTERWHEEL:
		{
			POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
			::ScreenToClient(this->HWnd(), &pt);
			//this->PointerWheelEvent(*this, int2(pt.x, pt.y), GET_POINTERID_WPARAM(wParam),
			//						GET_WHEEL_DELTA_WPARAM(wParam));
		}
			break;

#elif (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
		case WM_TOUCH:
			//this->TouchEvent(*this, reinterpret_cast<HTOUCHINPUT>(lParam), LOWORD(wParam));
			break;
#endif

		case WM_CLOSE:
			this->CloseEvent(*this);
			active_ = false;
			ready_ = false;
			closed_ = true;
			::PostQuitMessage(0);
			return 0;
		}

		return default_wnd_proc_(hWnd, uMsg, wParam, lParam);
	}
//}