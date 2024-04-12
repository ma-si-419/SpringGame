#pragma once
#include "DxLib.h"
class Obstruct
{
public:
	Obstruct(VECTOR pos);
	~Obstruct();

	void Init();
	bool Update();
	void Draw();

private:

	//描画位置
	VECTOR m_pos;
	//画像ハンドル
	int m_handle;
};

