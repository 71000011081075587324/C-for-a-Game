#pragma once
#include"acllib.h"

//碰撞边界
typedef struct border {
	int x, y;    //可移动到的左边界的坐标
	int width, height;   //可移动的视图的宽度和高度

} border;

class SpBase
{
protected:
	int x, y;   //坐标位置
	int dx, dy;  //移动的方向
	int width, height;  //判定宽度和高度
	ACL_Image* img; //图片
	border bd;  //碰撞边界

public:
	SpBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd);
	~SpBase();

	void move();  //移动
	void drawSpirit(int width, int height);  //大小变化绘制
	void drawSpirit();   //大小不变绘制
};

