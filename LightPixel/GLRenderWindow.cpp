#include "LightPixel.hpp"
#include "GLRenderWindow.hpp"

#include "App.hpp"
#include "Window.hpp"
#include "Engine.hpp"
#include "SceneManager.hpp"

GLRenderWindow::GLRenderWindow()
	:GLFrameBuffer(false)
{
	WindowPtr win = Engine::Instance().AppInstance().MainWnd();

	//callback 				
	win->PaintEvent.connect(std::bind(&GLRenderWindow::OnPaint, this));
	win->CloseEvent.connect(std::bind(&GLRenderWindow::OnClose, this));
	win->ExitSizeMoveEvent.connect(std::bind(&GLRenderWindow::OnExitSizeMove, this));
	win->EnterSizeMoveEvent.connect(std::bind(&GLRenderWindow::OnEnterSizeMove, this));
	win->SizeEvent.connect(std::bind(&GLRenderWindow::OnSize, this, std::placeholders::_1));
	win->ActiveEvent.connect(std::bind(&GLRenderWindow::OnActive, this, std::placeholders::_1));

	hWnd_ = win->HWnd();
	hDC_ = ::GetDC(hWnd_);

	left_ = 0;
	top_ = 0;
	width_ = win->Width();
	height_ = win->Height();

	int style = WS_OVERLAPPEDWINDOW;

	RECT rc = { 0, 0, static_cast<LONG>(width_), static_cast<LONG>(height_) };
	::AdjustWindowRect(&rc, style, false);

	::SetWindowLongPtrW(hWnd_, GWL_STYLE, style);
	::SetWindowPos(hWnd_, nullptr, left_, top_, width_, height_, SWP_SHOWWINDOW | SWP_NOZORDER);

	// there is no guarantee that the contents of the stack that become
	// the pfd are zeroed, therefore _make sure_ to clear these bits.
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = static_cast<BYTE>(32);
	pfd.cDepthBits = static_cast<BYTE>(24);
	pfd.cStencilBits = static_cast<BYTE>(8);
	pfd.iLayerType = PFD_MAIN_PLANE;

	int pixelFormat = ::ChoosePixelFormat(hDC_, &pfd);
	//static_assert(, L"sd");

	::SetPixelFormat(hDC_, pixelFormat, &pfd);

	HGLRC tempContext = ::wglCreateContext(hDC_);
	::wglMakeCurrent(hDC_, tempContext);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		printf("GLEW is not initialized!");
	}

	int OpenGLVersion[2];
	glGetIntegerv(GL_MAJOR_VERSION, &OpenGLVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &OpenGLVersion[1]);

	int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, OpenGLVersion[0],
		WGL_CONTEXT_MINOR_VERSION_ARB, OpenGLVersion[1],
		WGL_CONTEXT_FLAGS_ARB, 0,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
		0
	};

	if (wglewIsSupported("WGL_ARB_create_context") == 1)
	{
		hRC_ = wglCreateContextAttribsARB(hDC_, 0, attribs);
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(tempContext);
		wglMakeCurrent(hDC_, hRC_);
	}
	else
	{
		hRC_ = tempContext;
	}

	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);



	//::ShowWindow(hWnd_, SW_SHOWNORMAL);
	::UpdateWindow(hWnd_);
}


GLRenderWindow::~GLRenderWindow()
{
}

void GLRenderWindow::OnActive(bool active)
{
	active_ = active;
}

void GLRenderWindow::OnPaint()
{
	if (this->Active() && this->Ready())
	{
		Engine::Instance().SceneManagerInstance()->Update();
		this->SwapBuffers();
	}
}

void GLRenderWindow::OnEnterSizeMove()
{
	this->Ready(false);
}

void GLRenderWindow::OnExitSizeMove()
{
	this->WindowMovedOrResized();
	this->Ready(true);
}

void GLRenderWindow::OnSize(bool active)
{
	if (!active)
	{
		active_ = false;
	}
	else
	{
		active_ = true;
		if (this->Ready())
		{
			this->WindowMovedOrResized();
		}
		glViewport(left_, top_, width_, height_);
	}
}

void GLRenderWindow::OnClose()
{

}

void GLRenderWindow::SwapBuffers()
{
	::SwapBuffers(hDC_);
}

void GLRenderWindow::WindowMovedOrResized()
{
	::RECT rect;
	::GetClientRect(hWnd_, &rect);

	uint32_t new_left = rect.left;
	uint32_t new_top = rect.top;
	if ((new_left != left_) || (new_top != top_))
	{
		this->Reposition(new_left, new_top);
	}
	width_ = rect.right;
	height_ = rect.bottom;

}

void GLRenderWindow::Reposition(uint32_t left, uint32_t top)
{
	left_ = left;
	top_ = top;
}