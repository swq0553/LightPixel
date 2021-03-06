#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();

	void Refresh();
	void CreateRenderContext();
	virtual void ClearColor(const Color& clr) = 0;
private:
	virtual void DoCreateRenderContext() = 0;
	
private:
	FrameBufferPtr cur_frame_buffer_;
	FrameBufferPtr screen_frame_buffer_;
};

