#include "Obstruct.h"
#include "Data.h"

namespace
{
	constexpr float kScrollEnd = -500.0f;
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

}

bool Obstruct::Update()
{
	m_pos.x -= Data::kScrollSpeed;
	if (m_pos.x < kScrollEnd)
	{
		MV1DeleteModel(m_handle);
		return true;
	}
	MV1SetPosition(m_handle, m_pos);
	return false;
}

void Obstruct::Draw()
{
	MV1DrawModel(m_handle);
}
