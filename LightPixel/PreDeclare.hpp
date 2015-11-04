#ifndef _PREDECLARE_HPP
#define _PREDECLARE_HPP

#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>


class Application;


class Config;
typedef std::shared_ptr<Config> ConfigPtr;

class SceneManager;
typedef std::shared_ptr<SceneManager> SceneManagerPtr;

class Window;
typedef std::shared_ptr<Window> WindowPtr;
class FrameBuffer;
typedef std::shared_ptr<FrameBuffer> FrameBufferPtr;

class Renderer;
typedef std::shared_ptr<Renderer> RendererPtr;
class GraphicsBuffer;
typedef std::shared_ptr<GraphicsBuffer> GraphicsBufferPtr;

class RenderEffect;
typedef std::shared_ptr<RenderEffect> RenderEffectPtr;
class RenderTechnique;
typedef std::shared_ptr<RenderTechnique> RenderTechniquePtr;
class RenderPass;
typedef std::shared_ptr<RenderPass> RenderPassPtr;

class BoundingBox;
typedef std::shared_ptr<BoundingBox> BoundingBoxPtr;

class Camera;
typedef std::shared_ptr<Camera> CameraPtr;

typedef glm::vec3 Vec3;
typedef glm::vec4 Vec4;
typedef Vec4      Color;
typedef glm::mat3 Mat3;
typedef glm::mat4 Mat4;

#endif