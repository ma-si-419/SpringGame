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

	//�`��ʒu
	VECTOR m_pos;
	//�摜�n���h��
	int m_handle;
};

