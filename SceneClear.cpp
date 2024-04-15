#include "SceneClear.h"
#include "DxLib.h"
#include "SceneTitle.h"

SceneClear::SceneClear(SceneManager& sceneManager, DataManager& dataManager):
	SceneBase(sceneManager,dataManager)
{
	m_handle = LoadGraph("data/image/ClearImage.png");
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
		m_sceneManager.ChangeScene(std::make_shared<SceneTitle>(m_sceneManager, m_dataManager));
	}
}

void SceneClear::Draw()
{
	DrawGraph(0, 0, m_handle, true);
}

void SceneClear::End()
{
}
