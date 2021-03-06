#include "LightPixel.hpp"
#include "FrameBuffer.hpp"

#include "Engine.hpp"
#include "Util.hpp"
#include "Renderer.hpp"

	FrameBuffer::FrameBuffer(bool off_screen)		
	{
		left_ = 0;
		top_ = 0;		
	}


	FrameBuffer::~FrameBuffer()
	{
		
	}

	uint32_t FrameBuffer::Left() const
	{
		return left_;
	}

	uint32_t FrameBuffer::Top() const
	{
		return top_;
	}

	uint32_t FrameBuffer::Width() const
	{
		return width_;
	}

	uint32_t FrameBuffer::Height() const
	{
		return height_;
	}

	

	void FrameBuffer::OnBind()
	{

	}

	void FrameBuffer::OnUnbind()
	{

	}

	void FrameBuffer::SwapBuffers()
	{

	}


