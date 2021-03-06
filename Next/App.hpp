#ifndef _APPFRAMEWORK_HPP
#define _APPFRAMEWORK_HPP
#pragma once

#include <PreDeclare.hpp>

namespace LightPixel
{
	class Application
	{
	public:
		explicit Application(std::string const & name);
		Application(std::string const & name, void* native_wnd);
		virtual ~Application();

		void Create();
		void Destroy();
		void Suspend();
		void Resume();
		void Refresh();

		std::string const & Name() const
		{
			return name_;
		}

		WindowPtr MakeWindow(std::string const & name, int w, int h, bool full_screen);
		WindowPtr MakeWindow(std::string const & name, void* native_wnd);
		WindowPtr const & MainWnd() const
		{
			return main_wnd_;
		}

		virtual bool ConfirmDevice() const
		{
			return true;
		}

		//Camera const & ActiveCamera() const;
		CameraPtr ActiveCamera();

		uint32_t TotalNumFrames() const;
		float FPS() const;
		float AppTime() const;
		float FrameTime() const;

		void Run();
		void Quit();

		virtual void OnResize(uint32_t width, uint32_t height);

	protected:	
		void LookAt(const Vec3 &eye, const Vec3 & lookAt, const Vec3 & up);
		void Proj(float nearPlane, float farPlane);

	protected:
		void Update();
		void UpdateStats();

	private:
		virtual void OnCreate()
		{
		}
		virtual void OnDestroy()
		{
		}
		virtual void OnSuspend()
		{
		}
		virtual void OnResume()
		{
			
		}

	//	virtual void DoUpdateOverlay() = 0;
		virtual uint32_t DoUpdate() = 0;

	protected:
		std::string name_;

		// Stats
		uint32_t total_num_frames_;
		float	fps_;
		float	accumulate_time_;
		uint32_t num_frames_;

		//Timer timer_;
		float app_time_;
		float frame_time_;

		WindowPtr main_wnd_;
	};
}
#endif