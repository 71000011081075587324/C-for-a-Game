#pragma once
#include"acllib.h"
#include "SpBase.h"

//玩家基本属性
class userBase:
	public SpBase
{
private:
	int life;  //生命值
public:
	userBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd);
	userBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd,int life);
	~userBase();

	void move(int mx,int my);  //移动
	void move(int key);
	int collision(border bd);  //碰撞判定
	int getLife();
	void setLite(int l);
};

