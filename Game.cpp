#include"acllib.h"
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include"EnemyBase.h"
#include<time.h>
#include"userBase.h"
#include "Others.h"

int temp;
const int MAX_NUM = 6; //怪兽数量
const int NUM = 3;	//药剂数量
const int TAG1 = 1; 
const int TAG2 = 2;
const int TAG3 = 3;
const int TAG4 = 4;
const int OTHERSWIDTH = 40;
const int OTHERSHEIGHT = 40;
const int WIN_WIDTH = 800, WIN_HEIGHT = 600;
const int LIFE = 3;
border winbd;
EnemyBase* enemy[MAX_NUM] = {0};  //示例化怪兽
userBase* user = NULL;  //实例化用户
Others* OthersIns[NUM] = { 0 };
int spriteWidth = 40;   //怪兽的宽
int spriteHeight = 40;  //怪兽的高
int userWidth = 45;		//用户的宽
int userHeight = 45;	//用户的高
ACL_Image imgenemy1;    //怪兽的图片
ACL_Image imguser1;     //用户的样子
ACL_Image imgbackground;	//背景图案
ACL_Image imghuixue;    //药剂图片
ACL_Image imgyaoji1;    //药剂图片
ACL_Image imgyaoji;	//药剂图片
int nowNum = 0;


void timerEvent(int id);
void keyEvent(int key, int event);
void paint();

int Setup() {
	winbd.x = DEFAULT;
	winbd.y = DEFAULT;
	winbd.height = WIN_HEIGHT;
	winbd.width = WIN_WIDTH;
	initWindow("GAME", DEFAULT,DEFAULT,WIN_WIDTH,WIN_HEIGHT); 
	srand((unsigned)time(NULL));
	int x = rand() % WIN_WIDTH - spriteWidth;
	if (x < 0) {
		x = 0;
	}
	int y = rand() % WIN_HEIGHT - spriteHeight;
	if (y < 0) {
		y = 0;
	}
	int dx = rand() % 3 + 1;
	int dy = rand() % 3 + 1;
	loadImage("mingren.bmp", &imgenemy1);
	loadImage("you.bmp", &imguser1);
	loadImage("background.bmp", &imgbackground);
	loadImage("huixue.bmp", &imghuixue);
	loadImage("yaoji.bmp", &imgyaoji);
	loadImage("yaoji2.bmp", &imgyaoji1);
	enemy[nowNum] = new EnemyBase(x, y,dx*8, dy*8, spriteWidth, spriteHeight, &imgenemy1,winbd,TAG1);
	user = new userBase(x, y, dx*10, dy*10,userWidth, userHeight, &imguser1, winbd,LIFE);
	registerKeyboardEvent(keyEvent);
	registerTimerEvent(timerEvent);
	startTimer(0, 150);
	startTimer(1, 1000);
	return 0;
}

void paint() {
	beginPaint();
	clearDevice();
	putImageScale(&imgbackground, 0, 0, WIN_WIDTH, WIN_HEIGHT);
	int i = 0;
	for (i = 0; i < nowNum; i++) {
		if (enemy[i]) {
			enemy[i]->drawSpirit(spriteWidth, spriteHeight);
		}
	}
	for (i = 0; i < NUM; i++) {
		if (OthersIns[i]) {
			OthersIns[i]->drawSpirit();
		}
	}
	if (user) {
		for (int i = 0; i < nowNum; ++i)
		{
			if (enemy[i])
			{
				if (user->collision(enemy[i]->getBord()))
				{
					if (user) {
						user->setLite(user->getLife() - 1);
						if (!(user->getLife())) {
							delete(user);
							user = NULL;
						}
					}
				}
			}
		}
		for (int i = 0; i < NUM; ++i)
		{
			if (OthersIns[i])
			{
				if (user->collision(OthersIns[i]->getBord()))
				{
					if (user) {
						switch (OthersIns[i]->getTag()) {
							case 2:
								user->setLite(user->getLife() + 1);
								delete(OthersIns[i]);
								OthersIns[i] = NULL;
							break;
							case 3:
								spriteWidth = spriteWidth + 10;   //怪兽的宽
								spriteHeight = spriteHeight + 10;  //怪兽的高
								delete(OthersIns[i]);
								OthersIns[i] = NULL;
								break;
							case 4:
								spriteWidth = spriteWidth - 6;   //怪兽的宽
								spriteHeight = spriteHeight - 6;  //怪兽的高
								delete(OthersIns[i]);
								OthersIns[i] = NULL;
								break;

						}
					}
				}
			}
			if (OthersIns[i]) {
				if (OthersIns[i]->getNumBord() == 2) {
					delete(OthersIns[i]);
					OthersIns[i] = NULL;
				}
			}
		}
	}
	if (user) {
		user->drawSpirit();
	}
	if (user) {
		char t[10];
		char e[30];
		sprintf_s(t, "%d", user->getLife());
		sprintf_s(e, "%.10s%.10s", "YOU LIFE ", t);
		setTextSize(20);
		paintText(10, 10, e);
	}
	else {
		char e[25] = {"YOU LIFE 0 YOU DIE!"};
		setTextSize(20);
		paintText(10, 10, e);
	}

	endPaint();
}

void keyEvent(int key, int event) {
	if (user) {
		if (event != KEY_DOWN) {
			return;
		}
		user->move(key);
	}
	paint();
}

void timerEvent(int id) {
	int i = 0;
	switch(id) {
	case 0:
		for (i = 0; i < NUM; i++) {
			if (OthersIns[i]) {
				OthersIns[i]->move();
			}
		}
		for (i = 0; i < nowNum; i++) {
			if (enemy[i]) {
				enemy[i]->move();
			}
		}
		break;
	case 1:
		int x = rand() % WIN_WIDTH - spriteWidth;
		if (x < 0) {
			x = 0;
		}
		int y = rand() % WIN_HEIGHT - spriteHeight;
		if (y < 0) {
			y = 0;
		}
		int dx = rand() % 3 + 1;
		int dy = rand() % 3 + 1;
		if (nowNum < MAX_NUM) {
			enemy[nowNum++] = new EnemyBase(x, y, spriteHeight, spriteWidth, dx, dy, &imgenemy1, winbd,TAG1);
		}
		if (rand() % 14 == 1) {
			if (!OthersIns[0]) {
				OthersIns[0] = new Others(x, y, dx*3, dy*3, OTHERSWIDTH, OTHERSHEIGHT, &imghuixue, winbd, TAG2);
			}
		}
		if (rand() % 14 == 2) {
			if (!OthersIns[1]) {
				OthersIns[1] = new Others(x, y, dx*3, dy*3, OTHERSWIDTH, OTHERSHEIGHT, &imgyaoji, winbd, TAG3);
			}
		}
		if (rand() % 14 == 3) {
			if (!OthersIns[2]) {
				OthersIns[2] = new Others(x, y, dx*3, dy*3, OTHERSWIDTH, OTHERSHEIGHT, &imgyaoji1, winbd, TAG4);
			}
		}
		break;
	}
	paint();
}