#pragma once
class Cloud
{
	int x, y, width, height;
	int two_X, two_Y, two_Width, two_Height;
	int three_X, three_Y, three_Width, three_Height;

	int speed, startX;

	CImage image[3];

public:
	Cloud();

	void ImageLoadCloud();
	void DrawCloud(CDC &dc);
	void Tick();
};

