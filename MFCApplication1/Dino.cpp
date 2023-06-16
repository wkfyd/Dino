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
	JumpCount = 0;

	isJump = false;
	isDoubleJump = false;
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

		if (JumpCount == 2 && isDoubleJump) { // 2단 점프가 가능하고 더블 점프가 요청된 경우
			JumpPower = max_JumpPower;
			y -= JumpPower;
			JumpPower -= 4;

			// 더블 점프 한 번 사용했으므로 상태 초기화
			isDoubleJump = false;
		}

		if (y >= ground) {
			y = ground;
			JumpPower = max_JumpPower;
			JumpCount = 0;
			isJump = false;
			isDoubleJump = false;
		}
	}
}

void Dino::StartJump() {
	if (JumpCount < Max_Jump_Count) {
		isJump = true;
		JumpCount++;

		if (JumpCount == 1) { // 첫 번째 점프 이후에만 더블 점프 가능
			isDoubleJump = true;
		}
	}
}

bool Dino::Collider(Cactus* cactus) {
	CRect cacRect;
	CRect cacDoubleRect;
	CRect cacThreeRect;

	cactus->GetRect(cacRect);
	cactus->GetRect01(cacDoubleRect);
	cactus->GetRect02(cacThreeRect);

	CRect dinoRect(x, y, x + width, y + height);
	CRect diff;

	return diff.IntersectRect(&cacRect, &dinoRect) || diff.IntersectRect(&cacDoubleRect, &dinoRect) ||
			diff.IntersectRect(&cacThreeRect, &dinoRect);
}