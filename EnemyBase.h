#pragma once
#include"acllib.h"
#include "SpBase.h"


//怪兽基本属性
class EnemyBase :
	public SpBase
{
private:
	int tag;
public:
	EnemyBase(int x, int y, int dx, int dy,int width, int height, ACL_Image* img,border bd,int tag);
	~EnemyBase();

	void move();  //移动
	border getBord();
	int getTag();
};

