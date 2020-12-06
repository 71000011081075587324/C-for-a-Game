#include "Others.h"


Others::Others(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd,int tag):EnemyBase(x,y,dx,dy, width, height, img, bd, tag) {

}

Others::~Others() {

}

void Others::move() {
	x = dx + x;
	y = dy + y;

	//Åö×²µ½±ß½ç·´µ¯
	if (x < bd.x || x >(bd.x + bd.width - width)) {
		dx = dx * (-1);
		numBord = numBord + 1;
	}
	if (y < bd.y || y >(bd.y + bd.height - height)) {
		dy = dy * (-1);
		numBord = numBord + 1;
	}
}

int Others::getNumBord() {
	return numBord;
}