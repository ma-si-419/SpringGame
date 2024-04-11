#include "Obstruct.h"

Obstruct::Obstruct():
	m_pos()
{
	// ‚R‚cƒ‚ƒfƒ‹‚Ì“Ç‚İ‚İ
	m_handle = MV1LoadModel("data/model/Grass.mv1");
	if (m_handle < 0)
	{
		printfDx("ƒf[ƒ^“Ç‚İ‚İ‚É¸”s");
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
