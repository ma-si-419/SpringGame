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

	//�`��ʒu
	VECTOR m_pos;
	//�摜�n���h��
	int m_handle;
};

