#include <LightPixel.hpp>
#include "Camera.hpp"

//namespace LightPixel
//	{
	Camera::Camera()
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::LookAt(const Vec3& eye,const Vec3& lookAt,const Vec3& up )
	{
		mModelView = glm::lookAt(eye,lookAt,up);
		float* t = &mModelView[0][0];
		mEye     = eye;
		mTarget  = lookAt;
		mUp      = up;
		mViewVec = glm::normalize(mTarget-mEye);
	}

	void Camera::Project(float fov, float aspect, float zNear, float zFar )
	{
		mProjView = glm::perspective(fov,  aspect,  zNear, zFar);
	}

	const Mat4 Camera::GetViewMatrix()
	{
		float* tt = &mModelView[0][0];
		return mModelView;
	}

	const Mat4 Camera::GetProjMatrix()
	{
		return mProjView;
	}

	void Camera::Forward()
	{
		//Vec3 forword = 
	}

	Vec3 Camera::Eye()
	{
		return mEye;
	}

	Vec3 Camera::Tareget()
	{
		return mTarget;
	}

	Vec3 Camera::UpVec()
	{
		return mUp;
	}

	Vec3 Camera::ViewVec()
	{
		return mViewVec;
	}

	CameraController::CameraController()
	: mRotationScaler(0.05f)
	, mMoveScaler(1)
	, mCamera(NULL)
	{
	}

	CameraController::~CameraController()
	{
	}

	void CameraController::Scalers(float rotationScaler, float moveScaler)
	{
		mRotationScaler = rotationScaler;
		mMoveScaler = moveScaler;
	}
	void CameraController::AttachCamera(Camera* camera)
	{
		mCamera = camera;
	}

	void CameraController::DetachCamera()
	{
		mCamera = NULL;
	}

	TrackballCameraController::TrackballCameraController()
	: mReverseTarget(false)
	{

	}

	void TrackballCameraController::AttachCamera( Camera* camera )
	{
		CameraController::AttachCamera( camera);
		mTarget = camera->Tareget();
		mRight = glm::normalize(glm::cross(Vec3(0, 1, 0), -camera->Eye()));
	}

	void TrackballCameraController::Move( float x,float y )
	{
		Vec3 offset = mRight * (x*mMoveScaler*2);
		Vec3 pos = mCamera->Eye() + offset;
		mTarget += offset;

		offset = (mCamera->UpVec()) * (y *mMoveScaler* 2);
		pos += offset;
		mTarget += offset;

		mCamera->LookAt(pos, mTarget, mCamera->UpVec());
	
	}

	void TrackballCameraController::Zoom(float x,float y)
	{
		Vec3 offset = mCamera->ViewVec() * ((x + y)* mMoveScaler*2);
		Vec3 pos    = mCamera->Eye() + offset;

		 if (glm::dot(mTarget-pos,mCamera->ViewVec()) <= 0)
 		{
 			mReverseTarget = true;
 		}
 		else
 		{
 			mReverseTarget = false;
 		}

		mCamera->LookAt(pos, pos + mCamera->ViewVec(), mCamera->UpVec());
	}
	void TrackballCameraController::Track(float x,float y)
	{

	// 
	// 	Mat4 mat(1.0);
	// 	mat = glm::rotate(mat,y*mRotationScaler,mRight); 
	// 	mat = glm::rotate(mat,x*mRotationScaler,Vec3(0.0f, glm::dot(mCamera->UpVec(), Vec3(0, 1, 0)) < 0 ? -1.0f : 1.0f, 0.0f));
	// 	Vec3 pos    = (mCamera->Eye())*Mat3(mat);
	// 	Vec3 target = mCamera->Tareget()*Mat3(mat);
	// 	Vec3     up = Vec3(0.0f, glm::dot(mCamera->UpVec(), Vec3(0, 1, 0)) < 0 ? -1.0f : 1.0f, 0.0f);
	// 	mRight = glm::normalize(glm::cross(up, -pos));
	// 	mCamera->LookAt(pos, target, mCamera->UpVec());

		/*Quat q = MathLib::rotation_axis(mRight, y * mRotationScaler);
		Mat4 mat = MathLib::transformation(mTarget, q);
		Vec3 pos = MathLib::transform_coord(mCamera->Eye(), mat);

		q = MathLib::rotation_axis(Vec3(0.0f, glm::dot(mCamera->UpVec(), Vec3(0, 1, 0)) < 0 ? -1.0f : 1.0f, 0.0f), x * mRotationScaler);
		mat = MathLib::transformation(mTarget, q);
		pos = MathLib::transform_coord(pos, mat);

		mRight = MathLib::transform_quat(mRight, q);

		Vec3 dir;
		if (mReverseTarget)
		{
			dir = pos - mTarget;
		}
		else
		{
			dir = mTarget - pos;
		}
		dir = glm::normalize(dir);
		Vec3 up = glm::cross(dir, mRight);

		mCamera->LookAt(pos, pos + dir, up);*/

	
		Mat4 mat,matx,maty;
		mat = matx = maty = Mat4(1.0);
		matx = glm::rotate(matx,x*mRotationScaler,Vec3(0,1,0));
		maty = glm::rotate(matx,y*mRotationScaler,Vec3(1,0,0));
		mat = matx*maty;
		Vec3 pos    = (mCamera->Eye())*Mat3(mat);
		Vec3 target = mCamera->Tareget()*Mat3(mat);
		Vec3 up = mCamera->UpVec()*Mat3(mat);
		//Vec3 up = Vec3(0.0f, glm::dot(mCamera->UpVec(), Vec3(0, 1, 0)) < 0 ? -1.0f : 1.0f, 0.0f);
		//mRight = glm::normalize(glm::cross(up, -pos));
		mCamera->LookAt(pos, target,up);
	}
//}