#pragma once
class GLRenderContext
{
public:
	GLRenderContext();
	~GLRenderContext();
	void OnActive(bool active);
	void OnPaint();
	void OnEnterSizeMove();
	void OnExitSizeMove();
	void OnSize(bool active);;
	void OnClose();

	void WindowMovedOrResized();
	void Reposition(uint32_t left, uint32_t top);
	void SwapBuffers();

	bool Active()
	{
		return active_;
	}


private:

	HWND	hWnd_;
	HGLRC	hRC_;
	HDC		hDC_;

	bool	active_;

	uint32_t left_ ;
	uint32_t top_;
	uint32_t width_; 
	uint32_t height_;
};

typedef std::shared_ptr<GLRenderContext> GLRenderContextPtr;