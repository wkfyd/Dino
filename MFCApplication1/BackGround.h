#pragma once
class BackGround
{
	int x, y, width, height;
	int two_X, two_Y, two_Width, two_Height;
	int speed, startX = 1150;

	CImage image[2];

public:
	BackGround();

	void ImageLoadBackGround();
	void DrawBackGround(CDC& dc);
	void Tick();
};

