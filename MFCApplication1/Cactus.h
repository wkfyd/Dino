#pragma once
class Cactus
{
	//한 개
	int width, height, y;

	//두 개
	int two_Width, two_Height;

	//세개 개
	int three_Width, three_Height;

	int speed;
	int startX = 1150;
	int randNum;

	CRect rect;
	CImage image;


public:
	Cactus();

	int x;
	int speedRate;
	int GenerateRandomNumber();
	void ImageLoadCactus();
	void DrawCactus(CDC& dc);
	void Tick();
	int Cactus::GetImageWidth();
	int Cactus::GetImageHeight();
	void GetRect(CRect& rect);
	void GetRect01(CRect& rect);
	void GetRect02(CRect& rect);
};

