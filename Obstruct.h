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

	//�`��ʒu
	VECTOR m_pos;
	//�摜�n���h��
	int m_handle;
};

