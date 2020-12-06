#include "EnemyBase.h"


EnemyBase::EnemyBase(int x, int y, int dx, int dy,int width, int height, ACL_Image* img,border bd,int tag):SpBase(x, y, dx, dy, width, height, img, bd) {
	this->tag = tag;
}
EnemyBase::~EnemyBase() {

}

void EnemyBase::move() {
	x = dx + x;
	y = dy + y;

	//Åö×²µ½±ß½ç·´µ¯
	if (x < bd.x || x >(bd.x + bd.width - width)) {
		dx = dx * (-1);
	}
	if (y < bd.y || y >(bd.y + bd.height - height)) {
		dy = dy * (-1);
	}
}

border EnemyBase::getBord() {
	border bd = { x, y, width, height };
	return bd;
}

int EnemyBase::getTag() {
	return tag;
}