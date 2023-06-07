#include "pch.h"
#include "Cloud.h"

Cloud::Cloud() {
	x = 1200;
	y = 100;
	width = 30;
	height = 10;

	two_X = 1200;
	two_Y = 170;
	two_Width = 50;
	two_Height = 20;

	three_X = 1200;
	three_Y = 230;
	three_Width = 120;
	three_Height = 90;

	speed = 8;
	startX = 1150;
}

void Cloud::ImageLoadCloud() {
	image[0].Load(L"images\\Cloud.png");
	image[1].Load(L"images\\Cloud.png");
	image[2].Load(L"images\\Cloud.png");
}

void Cloud::DrawCloud(CDC& dc) {
	image[0].Draw(dc, x, y, x + width, y + height);
	image[1].Draw(dc, two_X, two_Y, two_X + two_Width, two_Y + two_Height);
	image[2].Draw(dc, three_X, three_Y, three_X + three_Width, three_Y + three_Height);
}

void Cloud::Tick() {
	x -= speed;
	two_X -= speed;
	three_Y -= speed;

	if (x <= -100) {
		x = startX;
	}

	if (two_X <= -100) {
		two_X = startX;
	}

	if (three_X <= -100) {
		three_X = startX;
	}
}