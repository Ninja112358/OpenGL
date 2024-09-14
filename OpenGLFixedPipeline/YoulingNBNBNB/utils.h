#pragma once
#include "ggl.h"

unsigned char* LoadFileContent(const char* path,int& fileSize);						//��ȡ�ļ�������
unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height);		//����bmp
GLuint CreateTexture2D(unsigned char* pixelData,int width,int height,GLenum type);	//����һ��Texture����
GLuint CreateTexture2DFromBMP(const char* bmpPath);									//��װһ�´���Texture�ķ���
GLuint CreateDisplayList(std::function<void()>foo);									//��ʾ�б�ķ�װ
float GetFrameTime();																//��ȡһ֡��ʱ��(��λ:��