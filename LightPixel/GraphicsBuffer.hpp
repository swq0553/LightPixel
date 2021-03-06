#pragma once
class GraphicsBuffer
{
public:
	enum Type
	{
		VertexBuffer  = 0x8892, // GL_ARRAY_BUFFER
		IndexBuffer   = 0x8893, // GL_ELEMENT_ARRAY_BUFFER
		UniformBuffer = 0x8A11 // GL_UNIFORM_BUFFER		
	};
	enum Usage
	{
		StreamDraw = 0x88E0, // GL_STREAM_DRAW
		StreamRead = 0x88E1, // GL_STREAM_READ
		StreamCopy = 0x88E2, // GL_STREAM_COPY
		StaticDraw = 0x88E4, // GL_STATIC_DRAW
		StaticRead = 0x88E5, // GL_STATIC_READ
		StaticCopy = 0x88E6, // GL_STATIC_COPY
		DynamicDraw = 0x88E8, // GL_DYNAMIC_DRAW
		DynamicRead = 0x88E9, // GL_DYNAMIC_READ
		DynamicCopy = 0x88EA  // GL_DYNAMIC_COPY
	};

	enum Access
	{
		ReadOnly = 0x88B8, // GL_READ_ONLY
		WriteOnly = 0x88B9, // GL_WRITE_ONLY
		ReadWrite = 0x88BA  // GL_READ_WRITE
	};

public:
	GraphicsBuffer();
	explicit GraphicsBuffer(Type type);
	~GraphicsBuffer();

	Type BufferType() const;
	Usage BufferUsage() const;
	void SetUsagePattern(Usage value);

	bool Create();
	bool isCreated() const;

	void Destroy();

	void Bind();
	void Release();
	static void Release(Type type);

	uint32_t BufferId() const;
	uint32_t Size() const;

	bool Read(int offset, void *data, int count);
	void Write(int offset, const void *data, int count);

	void Allocate(const void *data, int count);
	void Allocate(int count);

	void *Map(Access access);
	bool unMap();
private:
	Type     mType;
	Usage    mUsage;
	uint32_t mBufferID;
};

