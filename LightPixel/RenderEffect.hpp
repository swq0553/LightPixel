#pragma once
class RenderEffect
{
public:
	RenderEffect();
	~RenderEffect();
};



class Program;
typedef std::vector<RenderPassPtr> PassVec;

class RenderTechnique
{
public:
	RenderTechnique(void);
	~RenderTechnique(void);
	RenderPassPtr GetPass(int);
	void AddPass(RenderPassPtr);
private:
	PassVec mPasses;
};

//应包含shader对象和渲染状态
class RenderPass
{
public:
	RenderPass(void);
	~RenderPass(void);

	void Bind();
	void UnBind();
	void SetProgram(Program*);
	Program* GetProgram(){ return mProgram; }
private:
	Program* mProgram;
	bool     mCompile;
};
class Program
{
public:
	enum ShaderType {
		VS, PS, GS,
		TSC, TSE
	};
public:
	Program(void);
	~Program(void);

	bool   compileShader(const std::string & source, ShaderType type);
	bool   link();
	bool   validate();
	void   use();

	int    getHandle();
	bool   isLinked();

	void   bindAttribLocation(GLuint location, const char * name);
	void   bindFragDataLocation(GLuint location, const char * name);

	void   setUniform(const char *name, float x, float y, float z);
	void   setUniform(const char *name, const glm::vec3 & v);
	void   setUniform(const char *name, const glm::vec4 & v);
	void   setUniform(const char *name, const glm::mat4 & m);
	void   setUniform(const char *name, const glm::mat3 & m);
	void   setUniform(const char *name, float val);
	void   setUniform(const char *name, int val);
	void   setUniform(const char *name, bool val);
	int    getUniformLocation(const char * name);
private:
	int  handle;
	bool linked;
	std::string logString;
};

