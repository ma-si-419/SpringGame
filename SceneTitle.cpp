#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"
#include "Data.h"
namespace
{
	constexpr int kBoxWidth = 230;
	constexpr int kBoxHeight = 50;

	constexpr int kBoxPosY = 300;
	constexpr int kTitleUiPosX = 200;
	constexpr int kTitleUiPosY = 215;

	constexpr int kBoxStartPosX = 300 - kBoxWidth;
	constexpr int kBoxStartPosY = 325 - kBoxHeight;
	constexpr int kBoxEndPosX = 350 + kBoxWidth;
	constexpr int kBoxEndPosY = 350 + kBoxHeight;
}
SceneTitle::SceneTitle(SceneManager& sceneManager,DataManager& dataManager) :
	SceneBase(sceneManager,dataManager),
	m_boxScale(0),
	m_boxMag(0)
{
	m_titleHandle = LoadGraph("data/image/TitleImage.png");
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneGame>(m_sceneManager,m_dataManager));
	}

	m_boxScale += static_cast<float>((DX_PI / 180) * 5);

	m_boxMag = sinf(m_boxScale) * 5;
}

void SceneTitle::Draw()
{
	DrawString(0, 0, "‚¶‚á‚ñ‚Õ‚ ‚­‚µ‚å‚ñ", GetColor(255, 255, 255));

	DrawGraph(0, 0, m_titleHandle, true);
	DrawBox(kBoxStartPosX - m_boxMag, kBoxStartPosY - m_boxMag,
		kBoxEndPosX + m_boxMag, kBoxEndPosY + m_boxMag, GetColor(0, 0, 0), false);
}

void SceneTitle::End()
{
}
