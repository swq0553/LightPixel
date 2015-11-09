#include "LightPixel.hpp"
#include "RenderEffect.hpp"
#include <sstream>
#include <fstream>

RenderEffect::RenderEffect()
{
}


RenderEffect::~RenderEffect()
{
}


RenderTechnique::RenderTechnique(void)
{
}

RenderTechnique::~RenderTechnique(void)
{
}

RenderPassPtr RenderTechnique::GetPass(int index)
{
	return mPasses[index];
}

void RenderTechnique::AddPass(RenderPassPtr pass)
{
	mPasses.push_back(pass);
}

//pass
RenderPass::RenderPass(void)
	: mCompile(false)
{
}


RenderPass::~RenderPass(void)
{
}

void RenderPass::Bind()
{
	if (!mCompile)
	{
		mCompile = true;
		mProgram->link();
	}

	mProgram->use();

}

void RenderPass::UnBind()
{
	glUseProgram(0);
}

void RenderPass::SetProgram(ProgramPtr program)
{
	mProgram = program;
}

//program
Program::Program(void)
	: handle(0)
	, linked(false)
{

}

Program::~Program(void)
{

}
bool Program::compileShader(const std::string & source, ShaderType type)
{
	if (handle <= 0) {
		handle = glCreateProgram();
		if (handle == 0) {
			logString = "Unable to create shader program.";
			return false;
		}
	}

	GLuint shaderHandle = 0;

	switch (type) {
	case VS:
		shaderHandle = glCreateShader(GL_VERTEX_SHADER);
		break;
	case PS:
		shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	case GS:
		shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case TSC:
		shaderHandle = glCreateShader(GL_TESS_CONTROL_SHADER);
		break;
	case TSE:
		shaderHandle = glCreateShader(GL_TESS_EVALUATION_SHADER);
		break;
	default:
		return false;
	}

	const char * c_code = source.c_str();
	glShaderSource(shaderHandle, 1, &c_code, NULL);

	// Compile the shader
	glCompileShader(shaderHandle);

	// Check for errors
	int result;
	glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &result);
	if (GL_FALSE == result) {
		// Compile failed, store log and return false
		int length = 0;
		logString = "";
		glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &length);
		if (length > 0) {
			char * c_log = new char[length];
			int written = 0;
			glGetShaderInfoLog(shaderHandle, length, &written, c_log);
			printf(c_log);
			logString = c_log;
			delete[] c_log;
		}

		return false;
	}
	else
	{
		// Compile succeeded, attach shader and return true
		glAttachShader(handle, shaderHandle);
		return true;
	}
}

void Program::compileShader(const char * fileName, ShaderType type)
{
	std::ifstream inFile(fileName, std::ios::in);
	if (inFile)
	{
		// Get file contents
		std::stringstream code;
		code << inFile.rdbuf();
		inFile.close();

		compileShader(code.str(), type);
	}

	
}

bool Program::link()
{
	if (linked) return true;
	if (handle <= 0) return false;

	glLinkProgram(handle);

	int status = 0;
	glGetProgramiv(handle, GL_LINK_STATUS, &status);
	if (GL_FALSE == status)
	{
		// Store log and return false
		int length = 0;
		logString = "";

		glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length);

		if (length > 0)
		{
			char * c_log = new char[length];
			int written = 0;
			glGetProgramInfoLog(handle, length, &written, c_log);
			logString = c_log;
			delete[] c_log;
		}

		return false;
	}
	else
	{
		linked = true;
		return linked;
	}
}
bool Program::validate()
{
	if (!isLinked()) return false;

	GLint status;
	glValidateProgram(handle);
	glGetProgramiv(handle, GL_VALIDATE_STATUS, &status);

	if (GL_FALSE == status)
	{
		// Store log and return false
		int length = 0;
		logString = "";

		glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length);

		if (length > 0)
		{
			char * c_log = new char[length];
			int written = 0;
			glGetProgramInfoLog(handle, length, &written, c_log);
			logString = c_log;
			delete[] c_log;
		}

		return false;
	}
	else
	{
		return true;
	}
}
void Program::use()
{
	if (handle <= 0 || (!linked)) return;
	glUseProgram(handle);
}

int Program::getHandle()
{
	return handle;
}

bool Program::isLinked()
{
	return linked;
}

void Program::bindAttribLocation(GLuint location, const char * name)
{
	glBindAttribLocation(handle, location, name);
}

void Program::bindFragDataLocation(GLuint location, const char * name)
{
	glBindFragDataLocation(handle, location, name);
}

void Program::setUniform(const char *name, float x, float y, float z)
{
	int loc = getUniformLocation(name);
	if (loc >= 0) {
		glUniform3f(loc, x, y, z);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform(const char *name, const glm::vec3 & v)
{
	this->setUniform(name, v.x, v.y, v.z);
}

void Program::setUniform(const char *name, const glm::vec4 & v)
{
	int loc = getUniformLocation(name);
	if (loc >= 0) {
		glUniform4f(loc, v.x, v.y, v.z, v.w);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform(const char *name, const glm::mat4 & m)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniformMatrix4fv(loc, 1, GL_FALSE, &m[0][0]);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform(const char *name, const glm::mat3 & m)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniformMatrix3fv(loc, 1, GL_FALSE, &m[0][0]);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform(const char *name, float val)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniform1f(loc, val);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform(const char *name, int val)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniform1i(loc, val);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform(const char *name, bool val)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniform1i(loc, val);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

int Program::getUniformLocation(const char * name)
{
	return glGetUniformLocation(handle, name);
}
int Program::getGetAttribLocation(const char * name)
{
	return glGetAttribLocation(handle, name);
}
void Program::setUniform3fv(const char *name, int count, float* v)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniform3fv(loc,count,v);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}

void Program::setUniform1fv(const char *name, int count, float* v)
{
	int loc = getUniformLocation(name);
	if (loc >= 0)
	{
		glUniform1fv(loc, count, v);
	}
	else {
		printf("Uniform: %s not found.\n", name);
	}
}