#pragma once
class Cactus
{
	//�� �� ¥��
	int width, height, x, y;

	//�� �� ¥��
	int two_Width, two_Height, two_X, two_Y;

	int speed;
	int startX = 1150;

	CRect rect;
	CImage image[2];


public:
	Cactus();

	int speedRate;
	void ImageLoadCactus();
	void DrawCactus(CDC& dc);
	void Tick();
	void GetRect(CRect& rect);
	void GetRect01(CRect& rect);
};

