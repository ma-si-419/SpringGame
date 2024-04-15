#include "Bg.h"
#include "DxLib.h"
#include "Data.h"

Bg::Bg()
{
	m_mainBgHandle = LoadGraph("data/image/mainBg.png");
}

Bg::~Bg()
{
}

void Bg::Init()
{
}

void Bg::Update()
{
}

void Bg::Draw()
{
	DrawExtendGraph(0, 0, Data::kScreenWidth, Data::kScreenHeight, m_mainBgHandle, true);
}
