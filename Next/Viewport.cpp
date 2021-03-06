#include "Next.hpp"
#include "Viewport.hpp"

#include <Util.hpp>
#include <Camera.hpp>


namespace LightPixel
{
	Viewport::Viewport()
		: camera(MakeSharedPtr<Camera>())
	{
	}

	Viewport::Viewport(int _left, int _top, int _width, int _height)
		: left(_left), top(_top),
		width(_width), height(_height),
		camera(MakeSharedPtr<Camera>())
	{
	}
}