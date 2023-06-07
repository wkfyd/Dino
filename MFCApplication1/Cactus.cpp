#include "pch.h"
#include "Cactus.h"

Cactus::Cactus() {
	x = startX;
	y = 350;
	width = 60;
	height = 100;

	two_X = startX + 500;
	two_Y = 350;
	two_Width = 120;
	two_Height = 100;
	speed = 16;
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
	x -= speed;
	two_X -= speed;

	if (x <= -100) {
		x = startX;
	}

	if (two_X <= -100) {
		two_X = startX;
	}

}

void Cactus::GetRect(CRect& rect) {

	rect.SetRect(x, y, x + width, y + height);
}

void Cactus::GetRect01(CRect& rect) {

	rect.SetRect(two_X, two_Y, two_X + two_Width, two_Y + two_Height);
}