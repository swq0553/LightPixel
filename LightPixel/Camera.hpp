#ifndef Camera_HPP
#define Camera_HPP
#pragma once

#include <PreDeclare.hpp>

//namespace LightPixel
//{
	class Camera
	{
	public:
		Camera();
		~Camera();
		void LookAt(const Vec3 &eye, const Vec3 & lookAt, const Vec3 & up);
		void Project(float fov, float aspect, float near, float far);
		const Mat4 GetViewMatrix();
		const Mat4 GetProjMatrix();

		void Forward();
		Vec3 Eye();
		Vec3 Tareget();
		Vec3 UpVec();
		Vec3 ViewVec();
	private:
		Mat4 mModelView;
		Mat4 mProjView;
		Vec3 mEye, mTarget, mUp, mViewVec;
	};

	class  CameraController
	{
	public:
		CameraController();
		virtual ~CameraController();


		virtual void AttachCamera(Camera* camera);
		void DetachCamera();
		void Scalers(float rotationScaler, float moveScaler);

	protected:
		Camera*		mCamera;
		float		mRotationScaler;	// Scaler for rotation
		float		mMoveScaler;		// Scaler for movement
	};
	class TrackballCameraController : public CameraController
	{
	public:
		TrackballCameraController();

		virtual void AttachCamera(Camera* camera);
		void Move(float x, float y);
		void Zoom(float x, float y);
		void Track(float x, float y);
	private:
		Vec3 mTarget;
		Vec3 mRight;
		bool mReverseTarget;
	};
//}
#endif