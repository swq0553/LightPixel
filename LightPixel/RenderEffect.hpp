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
class Program;
typedef std::shared_ptr<Program> ProgramPtr;
class RenderPass
{
public:
	RenderPass(void);
	~RenderPass(void);

	void Bind();
	void UnBind();
	void SetProgram(ProgramPtr);
	ProgramPtr GetProgram(){ return mProgram; }
private:
	ProgramPtr mProgram;
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
	
	void   compileShader(const char * fileName, ShaderType type);
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
	void   setUniform1fv(const char *name, int count, float* v);
	void   setUniform3fv(const char *name, int count, float* v);

	int    getUniformLocation(const char * name);	
	int    getGetAttribLocation(const char * name);
private:
	int  handle;
	bool linked;
	std::string logString;
};

