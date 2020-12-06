#pragma once
#include "EnemyBase.h"
class Others :
    public EnemyBase
{
private:
	int numBord = 0;
public:
	Others(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd,int tag);
	~Others();
	void move();  //ÒÆ¶¯
	int getNumBord();
};

