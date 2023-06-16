#include "pch.h"
#include "Dino.h"

Dino::Dino() {
	count = 0;

	x = 150;
	y = ground;
	width = 60;
	height = 60;

	Max_Jump_Count = 2;
	JumpPower = max_JumpPower;

	isJump = false;
}

void Dino::ImageLoad() {
	//L, _T string 쓰기전에 앞에 붙여야됨 아무튼그럼
	images[0].Load(L"images\\Dino01.png");
	images[1].Load(L"images\\Dino02.png");
	images[2].Load(L"images\\Dino03.png");
	images[3].Load(L"images\\Dino04.png");
}

void Dino::DrawDino(CDC& dc) {
	images[count % 4].Draw(dc, x, y, width, height);
}

void Dino::Tick() {
	count++;

	if (isJump) {
		y -= JumpPower;
		JumpPower -= 4;

		if (y >= ground) {
			y = ground;
			JumpPower = max_JumpPower;

			isJump = false;
		}
	}
}

void Dino::StartJump() {
	isJump = true;
}

bool Dino::Collider(Cactus* cactus) {
	CRect cacRect;
	CRect cacDoubleRect;
	cactus->GetRect(cacRect);
	cactus->GetRect01(cacDoubleRect);

	CRect dinoRect(x, y, x + width, y + height);
	CRect diff;

	return diff.IntersectRect(&cacRect, &dinoRect) || diff.IntersectRect(&cacDoubleRect, &dinoRect);
}