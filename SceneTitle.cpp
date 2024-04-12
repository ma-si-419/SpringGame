#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"
SceneTitle::SceneTitle(SceneManager& sceneManager):
	SceneBase(sceneManager)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_G))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneGame>(m_sceneManager));
	}
}

void SceneTitle::Draw()
{
	DrawString(0, 0, "‚¶‚á‚ñ‚Õ‚ ‚­‚µ‚å‚ñ", GetColor(255, 255, 255));
}

void SceneTitle::End()
{
}
