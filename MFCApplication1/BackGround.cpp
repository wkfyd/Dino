#include "pch.h"
#include "BackGround.h"

BackGround::BackGround() {
	x = 0;
	y = 0;
	width = 1150;
	height = 500;

	two_X = startX;
	two_Y = 0;
	two_Width = 1150;
	two_Height = 500;

	speed = 16;
	startX;
}

void BackGround::ImageLoadBackGround() {
	image[0].Load(L"images\\BackGround_01.png");
	image[1].Load(L"images\\BackGround_02.png");
}

void BackGround::DrawBackGround(CDC& dc) {
	image[0].Draw(dc, x, y, width, height);
	image[1].Draw(dc, two_X, two_Y, two_Width, two_Height);
}

void BackGround::Tick() {
	x -= speed;
	two_X -= speed;

	if (x <= -1150) {
		x = startX;
	}

	if (two_X <= -1150) {
		two_X = startX;
	}
}