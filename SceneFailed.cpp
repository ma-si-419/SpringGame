#include "SceneFailed.h"
#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneGame.h"

SceneFailed::SceneFailed(SceneManager& sceneManager, DataManager& dataManager):
	SceneBase(sceneManager,dataManager),
	m_failedImage(-1)
{
	m_failedImage = LoadGraph("data/image/FailedImage.png");
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
		m_sceneManager.ChangeScene(std::make_shared<SceneTitle>(m_sceneManager, m_dataManager));
	}
	if (CheckHitKey(KEY_INPUT_R))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneGame>(m_sceneManager, m_dataManager));
	}
}

void SceneFailed::Draw()
{
	DrawString(0, 0, "SceneFailed", GetColor(255, 255, 255));

	DrawGraph(0, 0, m_failedImage, true);

}

void SceneFailed::End()
{
}
