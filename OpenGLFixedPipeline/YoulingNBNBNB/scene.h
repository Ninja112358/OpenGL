#pragma once
#include "ggl.h"

void Init(float windowWidth, float windowHeight);	//��ʼ������
void Draw();		//���ƺ���
void DrawModel();	//����ģ��
void InitLight();	//��ʼ���ƹ⣬�����ǹ̶����ߵĵƹ⣨����
void OnKeyDown(char code);							//���¼��̵��¼�
void OnKeyUp(char code);							//̧����̵��¼�
void OnMouseMove(float deltaX, float deltaY);		//�ƶ������¼�