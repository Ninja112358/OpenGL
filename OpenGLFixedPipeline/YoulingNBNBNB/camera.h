#pragma once
#include "vector3f.h"
#include "ggl.h"
class Camera {
public:
	float moveSpeed = MOVE_SPEED;
	Camera();
	//mPos:���������
	//mViewCenter:��������ӿ����ĵ�λ��
	//mUp:�������ͷ���ķ�������
	Vector3f mPos, mViewCenter, mUp;
	bool mbMoveLeft, mbMoveRight, mbMoveForward, mbMoveBack, mbMoveUp, mbMoveDown;
	void Update(float deltaTime);		//ʵʱ����
	void Pitch(float angle);			//����ת��
	void Yaw(float angle);				//����ת��
	void RotateView(float angle, float x, float y, float z);	//��ת�ӿ�

};