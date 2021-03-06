#pragma once
#include "FrameBuffer.hpp"
class GLFrameBuffer:public FrameBuffer
{
public:
	GLFrameBuffer(bool off_screen);
	~GLFrameBuffer();

	void OnBind();

	void Clear(uint32_t flags, Color const & clr, float depth, int32_t stencil);	

	GLuint OGLFbo() const
	{
		return fbo_;
	}

protected:
	GLuint fbo_;
};

typedef std::shared_ptr<GLFrameBuffer> GLFrameBufferPtr;