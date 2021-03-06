#ifndef _RENDERER_HPP
#define _RENDERER_HPP
#pragma once

#include <PreDeclare.hpp>

namespace LightPixel
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		
		void Init();

		void Refresh();
		void CreateRenderWindow();

		const FrameBufferPtr & CurFrameBuffer() const;
		void BindFrameBuffer(const FrameBufferPtr  & fb);
	private:
		FrameBufferPtr cur_frame_buffer_;
		FrameBufferPtr screen_frame_buffer_;
	};
}

#endif
