#include "Obstruct.h"

Obstruct::Obstruct():
	m_pos()
{
	// ３Ｄモデルの読み込み
	m_handle = MV1LoadModel("data/model/Grass.mv1");
	if (m_handle < 0)
	{
		printfDx("データ読み込みに失敗");
	}
	m_pos = VGet(100,100,0);
}

Obstruct::~Obstruct()
{
	MV1DeleteModel(m_handle);
}

void Obstruct::Init()
{

}

void Obstruct::Update()
{
	MV1SetPosition(m_handle, m_pos);
}

void Obstruct::Draw()
{
	MV1DrawModel(m_handle);
}
