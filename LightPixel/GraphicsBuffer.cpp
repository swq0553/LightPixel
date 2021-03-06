#include "LightPixel.hpp"
#include "GraphicsBuffer.hpp"


GraphicsBuffer::GraphicsBuffer()
:mType(VertexBuffer)
, mUsage(StaticDraw)
, mBufferID(0)
{
}

GraphicsBuffer::GraphicsBuffer(Type type)
: mType(type)
, mUsage(StaticDraw)
, mBufferID(0)
{

}


GraphicsBuffer::~GraphicsBuffer()
{
}

GraphicsBuffer::Type GraphicsBuffer::BufferType() const
{
	return mType;
}

GraphicsBuffer::Usage GraphicsBuffer::BufferUsage() const
{
	return mUsage;
}

void GraphicsBuffer::SetUsagePattern(Usage value)
{
	mUsage = value;
}


bool GraphicsBuffer::Create()
{
	glGenBuffers(1, &mBufferID);
	return mBufferID > 0;
}

bool GraphicsBuffer::isCreated() const
{
	return mBufferID != 0;
}

void GraphicsBuffer::Destroy()
{
	glDeleteBuffers(1, &mBufferID);
}

void GraphicsBuffer::Bind()
{
	glBindBuffer(mType, mBufferID);
}

void GraphicsBuffer::Release()
{
	glBindBuffer(mType, 0);
}

void GraphicsBuffer::Release(Type type)
{
	glBindBuffer(type, 0);
}

uint32_t GraphicsBuffer::BufferId() const
{
	return mBufferID;
}

uint32_t GraphicsBuffer::Size() const
{
	GLint value = -1;
	glGetBufferParameteriv(mType, GL_BUFFER_SIZE, &value);
	return value;
}

bool GraphicsBuffer::Read(int offset, void *data, int count)
{
	while (glGetError() != GL_NO_ERROR); // Clear error state.
	glGetBufferSubData(mType, offset, count, data);
	return glGetError() == GL_NO_ERROR;
}

void GraphicsBuffer::Write(int offset, const void *data, int count)
{
	glBufferSubData(mType, offset, count, data);
}

void GraphicsBuffer::Allocate(const void *data, int count)
{
	glBufferData(mType, count, data, mUsage);
}

void GraphicsBuffer::Allocate(int count)
{
	Allocate(0, count);
}

void * GraphicsBuffer::Map(Access access)
{
	if (mBufferID)
		return glMapBuffer(mType, access);
	else
		return 0;
}

bool GraphicsBuffer::unMap()
{
	return glUnmapBuffer(mType) == GL_TRUE;
}
