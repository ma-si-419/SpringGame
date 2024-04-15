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

	//描画位置
	VECTOR m_pos;
	//画像ハンドル
	int m_handle;
};

