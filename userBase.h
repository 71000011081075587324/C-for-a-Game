#pragma once
#include"acllib.h"
#include "SpBase.h"

//��һ�������
class userBase:
	public SpBase
{
private:
	int life;  //����ֵ
public:
	userBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd);
	userBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd,int life);
	~userBase();

	void move(int mx,int my);  //�ƶ�
	void move(int key);
	int collision(border bd);  //��ײ�ж�
	int getLife();
	void setLite(int l);
};

