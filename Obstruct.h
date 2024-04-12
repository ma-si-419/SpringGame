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

	//•`‰æˆÊ’u
	VECTOR m_pos;
	//‰æ‘œƒnƒ“ƒhƒ‹
	int m_handle;
};

