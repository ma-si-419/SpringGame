#include "Obstruct.h"
#include "Data.h"
#include "Player.h"

namespace
{
	constexpr float kScrollEnd = -400.0f;
}
Obstruct::Obstruct(VECTOR pos):
	m_pos(pos)
{
	// �R�c���f���̓ǂݍ���
	m_handle = MV1LoadModel("data/model/Grass.mv1");
	if (m_handle < 0)
	{
		printfDx("�f�[�^�ǂݍ��݂Ɏ��s");
	}

}

Obstruct::~Obstruct()
{
	MV1DeleteModel(m_handle);
}

void Obstruct::Init()
{
	MV1SetPosition(m_handle, m_pos);
}

void Obstruct::Update(Player& player)
{

	if (m_pos.x < kScrollEnd + player.GetPos().x)
	{
		m_pos.x = 1750 + player.GetPos().x;
	}
	MV1SetPosition(m_handle, m_pos);
}

void Obstruct::Draw()
{
	MV1DrawModel(m_handle);
}
