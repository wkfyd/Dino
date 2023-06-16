#pragma once
class BackGround
{
	int x, y, width, height;
	int two_X, two_Y, two_Width, two_Height;
	int speed;
	int startX = 1150;

	CImage image[2];

public:
	BackGround();

	int speedRate;
	void ImageLoadBackGround();
	void DrawBackGround(CDC& dc);
	void Tick();
};

