#include "camera.h"
#include "quaternion.h"

Camera::Camera():mPos(0.0f,5.0f,0.0f),mViewCenter(0.0f,5.0f,-1.0f),mUp(0.0f,1.0f,0.0f){
	mbMoveLeft = false;
	mbMoveRight = false;
	mbMoveForward = false;
	mbMoveBack = false; 
	mbMoveUp = false;
	mbMoveDown = false;
}

void Camera::Update(float deltaTime) {
	float moveSpeed = this->moveSpeed;

	Vector3f forwardDirection = mViewCenter - mPos;
	forwardDirection.Normalize();
	Vector3f rightDirection = forwardDirection ^ mUp;
	rightDirection.Normalize();
	if (mbMoveUp) {
		float delta = deltaTime * moveSpeed;
		mPos.y += delta;
		mViewCenter.y += delta;
	}if (mbMoveDown) {
		float delta = deltaTime * moveSpeed;
		mPos.y -= delta;
		mViewCenter.y -= delta;
	}
	if (mbMoveLeft) {
		Vector3f delta = rightDirection * deltaTime * moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;
	}if (mbMoveRight) {
		Vector3f delta = rightDirection * deltaTime * moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;
	}if (mbMoveForward) {
		Vector3f delta = forwardDirection * deltaTime * moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;
	}if (mbMoveBack) {
		Vector3f delta = forwardDirection * deltaTime * moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;
	}
	glLoadIdentity();
	gluLookAt(mPos.x, mPos.y, mPos.z,					//���������������ϵ�ľ���λ��
		mViewCenter.x, mViewCenter.y, mViewCenter.z,	//�۾������ľ���λ��
		mUp.x, mUp.y, mUp.z);
}
void Camera::Pitch(float angle) {
	Vector3f viewDirection = mViewCenter - mPos;
	viewDirection.Normalize();
	Vector3f rightDirection = viewDirection ^ mUp;
	rightDirection.Normalize();
	RotateView(angle, rightDirection.x, rightDirection.y, rightDirection.z);
}
float sum = 0;
void Camera::Yaw(float angle) {
	RotateView(angle, mUp.x, mUp.y, mUp.z);
}
void Camera::RotateView(float angle, float x, float y, float z) {
	////������ת���������ת����
	//Vector3f viewDirection = mViewCenter - mPos;
	//Vector3f newDirection(0.0f, 0.0f, 0.0f);
	//float C = cosf(angle);
	//float S = sinf(angle);
	////����Ϊ�˼򻯴������ô����,����ĵײ����ת������һ����
	//Vector3f tempX(C + x * x * (1 - C), x * y * (1 - C) - z * S, x * z * (1 - C) + y * S);
	//Vector3f tempY(x * y * (1 - C) + z * S, C + y * y * (1 - C), y * z * (1 - C) - x * S);
	//Vector3f tempZ(x * z * (1 - C) - y * S, y * z * (1 - C) + x * S, C + z * z * (1 - C));

	//newDirection.x = tempX * viewDirection;
	//newDirection.y = tempY * viewDirection;
	//newDirection.z = tempZ * viewDirection;

	//mViewCenter = newDirection + mPos;


	//������Ԫ��������ת�Ĳ���
	Vector3f viewDirection = mViewCenter - mPos;
	//�����ʾ����ŷ����
	Vector3f EulerAngle(angle * x * ROTATION_SPEED, angle * y * ROTATION_SPEED, angle * z * ROTATION_SPEED);
	Quaternion q = EulerToQuaternion(EulerAngle);
	Matrix3x3 rotationMatrix;
	QuaternionToMatrix(q, rotationMatrix);
	Vector3f newDirection = viewDirection * rotationMatrix;

	mViewCenter = newDirection + mPos;

	//������Ԫ���;����õ��Ĳ�������Ҫ��ִ��InitConsole()�Ż���Ч��
	//�����������ͷ����λ��
	printf("\n�����λ��(%f,%f,%f)\n", mPos.x, mPos.y, mPos.z);
	printf("��������ӿ�����(%f,%f,%f)\n", newDirection.x, newDirection.y, newDirection.z);
	printf("Up����(%f,%f,%f)\n", mUp.x, mUp.y, mUp.z);

}