#include "pch.h"
#include "math.h"
#include "Cactus.h"
#include "MFCApplication1Dlg.h"

Cactus::Cactus() {
	x = startX;
	y = 380;
	width = 40;
	height = 80;

	two_Width = 80;
	two_Height = 80;

	three_Width = 120;
	three_Height = 80;

	speed = 16;
	speedRate = 0;
	srand((unsigned int)time(NULL));
	randNum = GenerateRandomNumber();

	//시간에 따른 속도 조절 실패...
	//CMFCApplication1Dlg dlg; // 대화 상자 객체 생성
	//int value = dlg.score; // 변수 읽기

	//if (dlg.score == 180) {
	//	speedRate += 10;
	//}
	//if (dlg.score == 420) {
	//	speedRate += 10;
	//}
}

int Cactus::GenerateRandomNumber() {
	return randNum = rand() % 3;
}

void Cactus::ImageLoadCactus() {
	switch (randNum)
	{
	case 0:
		image.Load(L"images\\Cactus.png");
		break;

	case 1:
		image.Load(L"images\\CactusDouble.png");
		break;

	case 2:
		image.Load(L"images\\CactusThree.png");
		break;
	}
}

void Cactus::DrawCactus(CDC& dc) {
	image.Draw(dc, x, y, GetImageWidth(), GetImageHeight());
}

void Cactus::Tick() {
	x -= speed + speedRate;
}

int Cactus::GetImageWidth() {
	switch (randNum)
	{
	case 0:
		return width;

	case 1:
		return two_Width;

	case 2:
		return three_Width;
	}

	return 0;
}

int Cactus::GetImageHeight() {
	switch (randNum)
	{
	case 0:
		return height;

	case 1:
		return two_Height;

	case 2:
		return three_Height;
	}

	return 0;
}

void Cactus::GetRect(CRect& rect) {
	rect.SetRect(x + 20, y + 20, x + width, y + height);
}

void Cactus::GetRect01(CRect& rect) {

	rect.SetRect(x + 20, y + 20, x + two_Width, y + two_Height);
}

void Cactus::GetRect02(CRect& rect) {

	rect.SetRect(x + 20, y + 20, x + three_Width, y + three_Height);
}