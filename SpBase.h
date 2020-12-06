#pragma once
#include"acllib.h"

//��ײ�߽�
typedef struct border {
	int x, y;    //���ƶ�������߽������
	int width, height;   //���ƶ�����ͼ�Ŀ�Ⱥ͸߶�

} border;

class SpBase
{
protected:
	int x, y;   //����λ��
	int dx, dy;  //�ƶ��ķ���
	int width, height;  //�ж���Ⱥ͸߶�
	ACL_Image* img; //ͼƬ
	border bd;  //��ײ�߽�

public:
	SpBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd);
	~SpBase();

	void move();  //�ƶ�
	void drawSpirit(int width, int height);  //��С�仯����
	void drawSpirit();   //��С�������
};

