#pragma once

#include "Cactus.h"

//¼±¾ð¸¸
class Dino
{
	int count;

	int ground = 385; //¶¥
	int x, y;
	int width, height, JumpPower, Max_Jump_Count;
	int max_JumpPower = 33;
	bool isJump;

	CImage images[4];

public:
	Dino();

	void ImageLoad();
	void DrawDino(CDC& dc);
	void Tick();
	void StartJump();
	bool Collider(Cactus* cactus);
};

