#include "pch.h"
#include "Cactus.h"

Cactus::Cactus() {
	x = startX;
	y = 380;
	width = 40;
	height = 80;

	two_X = startX + 600;
	two_Y = 380;
	two_Width = 80;
	two_Height = 80;
	speed = 16;
	speedRate = 0;
}

void Cactus::ImageLoadCactus() {
	image[0].Load(L"images\\Cactus.png");
	image[1].Load(L"images\\CactusDouble.png");
}

void Cactus::DrawCactus(CDC& dc) {
	image[0].Draw(dc, x, y, width, height);
	image[1].Draw(dc, two_X, two_Y, two_Width, two_Height);
}

void Cactus::Tick() {
	x -= speed + speedRate;
	two_X -= speed + speedRate;

	if (x <= -100) {
		x = startX;
	}

	if (two_X <= -100) {
		two_X = startX;
	}
}

void Cactus::GetRect(CRect& rect) {

	rect.SetRect(x+20, y+20, x + width, y + height);
}

void Cactus::GetRect01(CRect& rect) {

	rect.SetRect(two_X+20, two_Y+20, two_X + two_Width, two_Y + two_Height);
}