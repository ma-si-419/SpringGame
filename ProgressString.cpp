#include "ProgressString.h"
#include "Data.h"
ProgressString::ProgressString() :
	m_handle(-1)
{
	m_speed = 3.0f;
}

ProgressString::~ProgressString()
{
}

void ProgressString::Init(int num)
{
	m_handle = num;
	m_pos = VGet(Data::kScreenWidth + GetRand(300), GetRand(Data::kScreenHeight) - 50, 0);
}

void ProgressString::Update()
{
	m_pos.x -= m_speed;
}

void ProgressString::Draw()
{
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}
