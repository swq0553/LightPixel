#ifndef _FRAMEBUFFER_HPP
#define _FRAMEBUFFER_HPP
#pragma once

namespace LightPixel
{
	class FrameBuffer
	{
	public:
		enum Attachment
		{
			ATT_DepthStencil,
			ATT_Color0,
			ATT_Color1,
			ATT_Color2,
			ATT_Color3,
			ATT_Color4,
			ATT_Color5,
			ATT_Color6,
			ATT_Color7
		};

		enum ClearBufferMask
		{
			CBM_Color = 1UL << 0,
			CBM_Depth = 1UL << 1,
			CBM_Stencil = 1UL << 2
		};
	public:
		FrameBuffer(bool off_screen);
		~FrameBuffer();

		uint32_t Left() const;
		uint32_t Top() const;
		uint32_t Width() const;
		uint32_t Height() const;

	
		ViewportPtr& GetViewport();
		void SetViewport(const ViewportPtr & viewport);

		void Clear(uint32_t flags, const Color  & clr, float depth, int32_t stencil);
		void Discard(uint32_t flags);

		virtual void OnBind();
		virtual void OnUnbind();

		virtual void SwapBuffers();
		

	protected:
		uint32_t	left_;
		uint32_t	top_;
		uint32_t	width_;
		uint32_t	height_;

		ViewportPtr viewport_;

	protected:
		GLuint fbo_;

// 		std::vector<RenderViewPtr> clr_views_;
// 		RenderViewPtr rs_view_;
// 		std::vector<UnorderedAccessViewPtr> ua_views_;
// 		bool views_dirty_;
	};
}
#endif