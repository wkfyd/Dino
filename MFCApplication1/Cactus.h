#pragma once
class Cactus
{
	//�� ��
	int width, height, y;

	//�� ��
	int two_Width, two_Height;

	//���� ��
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

