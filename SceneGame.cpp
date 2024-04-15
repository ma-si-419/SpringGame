#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneFailed.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Obstruct.h"
#include "Data.h"
#include "Bg.h" 
namespace
{
	constexpr int kGroundObstructNum = 10;
}
SceneGame::SceneGame(SceneManager& sceneManager, DataManager& dataManager) :
	SceneBase(sceneManager, dataManager),
	m_timeCount(0),
	m_appTime(0)
{
	m_pPlayer = std::make_shared<Player>();
	m_pEnemy.resize(100);
	m_pCamera = std::make_shared<Camera>();
	//	m_pBg = std::make_shared<Bg>();
	m_pObstruct.resize(100);
	m_enemyPopData = dataManager.GetData();
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_pPlayer->Init();

}

void SceneGame::Update()
{
	m_pPlayer->Update();
	for (auto& enemy : m_pEnemy)
	{
		if (enemy)
		{
			enemy->Update();
		}

	}
	for (auto& obstruct : m_pObstruct)
	{
		if (obstruct)
		{
			obstruct->Update(*m_pPlayer);
		}
	}
	m_pCamera->Update(m_pPlayer);
	if (CheckHitKey(KEY_INPUT_C))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneClear>(m_sceneManager, m_dataManager));
		return;
	}
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i] && GetHit(m_pPlayer, m_pEnemy[i]))
		{
			m_sceneManager.ChangeScene(std::make_shared<SceneFailed>(m_sceneManager, m_dataManager));
		}
	}
	for (int i = 0; i < kGroundObstructNum; i++)
	{
		float posX = (2150 / kGroundObstructNum) * i - 250;
		CreateObstruct(VGet(posX, 100, 0));
		CreateObstruct(VGet(posX, 100, 400));
	}

	m_timeCount++;
	if (m_timeCount > 60)
	{
		m_timeCount = 0;
		m_appTime++;
		/*if (m_enemyPopData[m_appTime].left)
		{
			CreateEnemy(false);
		}
		if (m_enemyPopData[m_appTime].right)
		{
			CreateEnemy(true);
		}*/
	}
}

void SceneGame::Draw()
{
	//	m_pBg->Draw();
	for (auto& obstruct : m_pObstruct)
	{
		if (obstruct)
		{
			obstruct->Draw();
		}
	}
	for (auto& enemy : m_pEnemy)
	{
		if (enemy)
		{
			enemy->Draw();
		}
	}
	m_pPlayer->Draw();
	m_pCamera->Draw();
	DrawString(0, 0, "SceneGame", GetColor(255, 255, 255));
	DrawFormatString(300, 0, GetColor(255, 255, 255), "%d,%d", m_timeCount, m_appTime);
}

void SceneGame::End()
{
}

bool SceneGame::GetHit(shared_ptr<Player> player, shared_ptr<Enemy> enemy)
{
	VECTOR langeVec = VSub(enemy->GetPos(), player->GetPos());
	float ans = VSize(langeVec);
	//“–‚½‚è”»’è‚Ì‘å‚«‚³‚æ‚è‚à‹——£‚ª‹ß‚©‚Á‚½‚ç
	if (Data::kHitScale * 2 > ans)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

void SceneGame::CreateObstruct(VECTOR pos)
{
	for (int i = 0; i < m_pObstruct.size(); i++)
	{
		if (!m_pObstruct[i])
		{
			m_pObstruct[i] = std::make_shared<Obstruct>(pos);
			return;
		}
	}
}

void SceneGame::CreateEnemy(bool right)
{
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i])
		{
			m_pEnemy[i] = std::make_shared<Enemy>(right);
			m_pEnemy[i]->Init();
			return;
		}
	}
}
