#ifndef _PREDECLARE_HPP
#define _PREDECLARE_HPP

#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>
namespace LightPixel
{
	class Application;
	class Window;
	typedef std::shared_ptr<Window> WindowPtr;

	class SceneManager;
	typedef std::shared_ptr<SceneManager> SceneManagerPtr;
	
	class Renderer;
	typedef std::shared_ptr<Renderer> RendererPtr;

	class RenderWindow;
	typedef std::shared_ptr<RenderWindow> RenderWindowPtr;
	class FrameBuffer;
	typedef std::shared_ptr<FrameBuffer> FrameBufferPtr;

	class Renderable;
	typedef std::shared_ptr<Renderable> RenderablePtr;
	
	class Camera;
	typedef std::shared_ptr<Camera> CameraPtr;
	class  CameraController;
	typedef std::shared_ptr<CameraController> CameraControllerPtr;
	class TrackballCameraController;
	typedef std::shared_ptr<TrackballCameraController> TrackballCameraControllerPtr;

	class Viewport;
	typedef std::shared_ptr<Viewport> ViewportPtr;


	typedef glm::vec3 Vec3;
	typedef glm::vec4 Vec4;
	typedef Vec4      Color;
	typedef glm::mat3 Mat3;
	typedef glm::mat4 Mat4;
}

#endif