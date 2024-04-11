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

	//•`‰æˆÊ’u
	VECTOR m_pos;
	//‰æ‘œƒnƒ“ƒhƒ‹
	int m_handle;
};

