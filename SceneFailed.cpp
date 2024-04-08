#include "SceneFailed.h"
#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneGame.h"

SceneFailed::SceneFailed(SceneManager& sceneManager):
	SceneBase(sceneManager)
{
}

SceneFailed::~SceneFailed()
{
}

void SceneFailed::Init()
{
}

void SceneFailed::Update()
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneTitle>(m_sceneManager));
	}
	if (CheckHitKey(KEY_INPUT_G))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneGame>(m_sceneManager));
	}
}

void SceneFailed::Draw()
{
	DrawString(0, 0, "SceneFailed", GetColor(255, 255, 255));

	DrawBox(100, 100, 500, 500, GetColor(100, 100, 100), true);
}

void SceneFailed::End()
{
}
