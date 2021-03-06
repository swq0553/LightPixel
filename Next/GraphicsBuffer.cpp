#include "Next.hpp"
#include "GraphicsBuffer.h"
namespace LightPixel
{ 
	GraphicsBuffer::GraphicsBuffer(BufferUsage usage, uint32_t access_hint)
		: usage_(usage), access_hint_(access_hint), size_in_byte_(0), hw_buff_size_(0)
	{
	}


	GraphicsBuffer::~GraphicsBuffer()
	{
	}

	void GraphicsBuffer::Resize(uint32_t size_in_byte)
	{
		size_in_byte_ = size_in_byte;
		if (size_in_byte_ > hw_buff_size_)
		{
			this->DoResize();
			hw_buff_size_ = size_in_byte_;
		}
	}
}