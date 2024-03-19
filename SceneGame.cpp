#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
SceneGame::SceneGame(SceneManager& sceneManager):
	SceneBase(sceneManager)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
}

void SceneGame::Update()
{
	if (CheckHitKey(KEY_INPUT_Z))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneTitle>(m_sceneManager));
	}
}

void SceneGame::Draw()
{
	DrawString(0, 0, "SceneGame", GetColor(255, 255, 255));

	DrawBox(100, 100, 500, 500, GetColor(255, 0, 0), true);
}

void SceneGame::End()
{
}
