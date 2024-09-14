#pragma once
#include "ggl.h"

#define SKYBOX_SIZE 0.5f	//��պеĴ�С

class SkyBox {
	GLuint mTextures[6];				//��պе�����
	GLuint mFastDrawCall;				//��ʾ�б�
public:
	void Init(const char* imageDir);	//��ʼ����պ�
	void DrawCommand();					//��ָ��װ����ʾ�б���
	void Draw(float x,float y,float z);	//����պн��л���
};