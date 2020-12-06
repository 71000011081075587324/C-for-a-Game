#include "userBase.h"

userBase::userBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd) :SpBase(x, y,  dx, dy, width, height, img, bd) {
}

userBase::userBase(int x, int y, int dx, int dy, int width, int height, ACL_Image* img, border bd,int life) :SpBase(x, y,  dx, dy, width, height, img, bd) {
	this->life = life;
}
userBase::~userBase() {

}

void userBase::move(int mx, int my) {
	x = mx;
	y = my;

	//碰到边界不再移动
	if (x < bd.x) {
		x = bd.x;
	}
	if (x > (bd.x + bd.width - width)) {
		x = bd.x + bd.width - width;
	}
	if (y < bd.y) {
		y = bd.y;
	}
	if (y > (bd.y + bd.height - height)) {
		y = bd.y + bd.height - height;
	}
}

void userBase::move(int key) {
	switch (key) {
	case VK_UP:
		y = y - dy;
		if (y < bd.y) {
			y = bd.y;
		}

		break;
	case VK_DOWN:
		y = y + dy;
		if (y > (bd.y + bd.height - height)) {
			y = bd.y + bd.height - height;
		}
		break;
	case VK_LEFT:
		x = x - dx;
		if (x < bd.x) {
			x = bd.x;
		}
		break;
	case VK_RIGHT:
		x = x + dx;
		if (x > (bd.x + bd.width - width)) {
			x = bd.x + bd.width - width;
		}
		break;
	}
}


int userBase::collision(border bd) {
	int b = 1;

	if (this) {
		border t = { x,y, width, height };
		if (t.x < bd.x && t.x + t.width >bd.x) {
			if (t.y > bd.y && t.y < bd.y + bd.height) {
				return b;
			}
			if (t.y <bd.y && t.y + t.height >bd.y) {
				return b;
			}
		}
		else {
			if (t.x > bd.x && bd.x + bd.width > t.x)
			{
				if (t.y > bd.y && t.y < bd.y + bd.height)return b;
				if (t.y <bd.y && t.y + t.height >bd.y)return b;
			}
		}
	}
	b = 0;
	return b;
}

int userBase::getLife() {
	return life;
}

void userBase::setLite(int l) {
	life = l;
}
