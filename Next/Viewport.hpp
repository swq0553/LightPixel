#ifndef _VIEWPORT_HPP
#define _VIEWPORT_HPP
#pragma once

#include <PreDeclare.hpp>

namespace LightPixel
{
	class Viewport
	{
	public:
		Viewport();
		Viewport(int _left, int _top, int _width, int _height);

		int left;
		int top;
		int width;
		int height;

		CameraPtr camera;
	};
}
#endif