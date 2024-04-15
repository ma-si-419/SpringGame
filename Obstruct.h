#pragma once
#include "DxLib.h"
class Player;
class Obstruct
{
public:
	Obstruct(VECTOR pos);
	~Obstruct();

	void Init();
	void Update(Player& player);
	void Draw();

private:

	//•`‰æˆÊ’u
	VECTOR m_pos;
	//‰æ‘œƒnƒ“ƒhƒ‹
	int m_handle;
};

