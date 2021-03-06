#ifndef _GRAPHICSBUFFER_HPP
#define _GRAPHICSBUFFER_HPP
#pragma once

namespace LightPixel
{ 
	enum BufferUsage
	{
		BU_Static,
		BU_Dynamic
	};
	enum BufferAccess
	{
		BA_Read_Only,
		BA_Write_Only,
		BA_Read_Write,
		BA_Write_No_Overwrite
	};

	class GraphicsBuffer
	{
	public:
		class Mapper
		{
			friend class GraphicsBuffer;

		public:
			Mapper(GraphicsBuffer& buffer, BufferAccess ba)
				: buffer_(buffer)
			{
				data_ = buffer_.Map(ba);
			}
			~Mapper()
			{
				buffer_.Unmap();
			}

			template <typename T>
			const T* Pointer() const
			{
				return static_cast<T*>(data_);
			}
			template <typename T>
			T* Pointer()
			{
				return static_cast<T*>(data_);
			}

		private:
			GraphicsBuffer& buffer_;
			void* data_;
		};
	public:
		explicit GraphicsBuffer(BufferUsage usage, uint32_t access_hint);
		virtual ~GraphicsBuffer();
		void Resize(uint32_t size_in_byte);
		uint32_t Size() const
		{
			return size_in_byte_;
		}

		BufferUsage Usage() const
		{
			return usage_;
		}

		uint32_t AccessHint() const
		{
			return access_hint_;
		}

		virtual void CopyToBuffer(GraphicsBuffer& rhs) = 0;

	private:
		virtual void DoResize() = 0;

		virtual void* Map(BufferAccess ba) = 0;
		virtual void Unmap() = 0;

	protected:
		BufferUsage usage_;
		uint32_t access_hint_;

		uint32_t size_in_byte_;
		uint32_t hw_buff_size_;
	};
}
#endif
