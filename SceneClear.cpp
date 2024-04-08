#include "SceneClear.h"
#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneGame.h"

SceneClear::SceneClear(SceneManager& sceneManager):
	SceneBase(sceneManager)
{
}

SceneClear::~SceneClear()
{
}

void SceneClear::Init()
{
}

void SceneClear::Update()
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

void SceneClear::Draw()
{
	DrawString(0, 0, "SceneClear", GetColor(255, 255, 255));

	DrawBox(100, 100, 500, 500, GetColor(0, 255, 0), true);
}

void SceneClear::End()
{
}
