#pragma once
#include "DxLib.h"
class Obstruct
{
public:
	Obstruct();
	~Obstruct();

	void Init();
	void Update();
	void Draw();

private:

	//描画位置
	VECTOR m_pos;
	//画像ハンドル
	int m_handle;
};

