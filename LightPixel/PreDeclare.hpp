#ifndef _PREDECLARE_HPP
#define _PREDECLARE_HPP

#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>


class Application;


class Config;
typedef std::shared_ptr<Config> ConfigPtr;

class Input;
typedef std::shared_ptr<Input> InputPtr;

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

class Renderable;
typedef std::shared_ptr<Renderable> RenderablePtr;
class RenderableHelper;
typedef std::shared_ptr<RenderableHelper> RenderableHelperPtr;
class RenderablePoint;
typedef std::shared_ptr<RenderablePoint> RenderablePointPtr;
class RenderableLine;
typedef std::shared_ptr<RenderableLine> RenderableLinePtr;
class RenderableTriangle;
typedef std::shared_ptr<RenderableTriangle> RenderableTrianglePtr;
class RenderableTriBox;
typedef std::shared_ptr<RenderableTriBox> RenderableTriBoxPtr;
class RenderableLineBox;
typedef std::shared_ptr<RenderableLineBox> RenderableLineBoxPtr;
class RenderableSkyBox;
typedef std::shared_ptr<RenderableSkyBox> RenderableSkyBoxPtr;
class RenderablePlane;
typedef std::shared_ptr<RenderablePlane> RenderablePlanePtr;

class RenderLayout;
typedef std::shared_ptr<RenderLayout> RenderLayoutPtr;

class BoundingBox;
typedef std::shared_ptr<BoundingBox> BoundingBoxPtr;

class Camera;
typedef std::shared_ptr<Camera> CameraPtr;

typedef glm::vec3 Vec3;
typedef glm::vec4 Vec4;
typedef Vec4      Color;
typedef glm::mat3 Mat3;
typedef glm::mat4 Mat4;

typedef rapidxml::file<>           XmlFile;
typedef rapidxml::xml_document<>   XmlDoc;
typedef rapidxml::xml_node<>       XmlNode;
typedef rapidxml::xml_attribute<>  XmlAttr;
#endif