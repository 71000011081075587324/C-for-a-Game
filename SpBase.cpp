#include "SpBase.h"

SpBase::SpBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->width = width;
	this->height = height;
	this->img = img;
	this->bd = bd;
}


SpBase::~SpBase() {

}

void SpBase :: move() {

}

void SpBase::drawSpirit(int width, int height) {
	putImageScale(img, x, y, width, height);
}
void SpBase::drawSpirit() {
	putImageScale(img, x, y, width, height);
}