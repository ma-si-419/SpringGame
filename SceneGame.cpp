#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneFailed.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
SceneGame::SceneGame(SceneManager& sceneManager) :
	SceneBase(sceneManager)
{
	m_pPlayer = new Player();
	m_pEnemy.resize(10);
	m_pEnemy[0] = std::make_shared<Enemy>();
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_pPlayer->Init();
	m_pEnemy[0]->Init();
}

void SceneGame::Update()
{
	m_pPlayer->Update();
	m_pEnemy[0]->Update();
	if (CheckHitKey(KEY_INPUT_C))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneClear>(m_sceneManager));
	}
	if (GetHit(m_pPlayer,m_pEnemy[0]))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneFailed>(m_sceneManager));
	}
}

void SceneGame::Draw()
{
	m_pPlayer->Draw();
	m_pEnemy[0]->Draw();
	DrawString(0, 0, "SceneGame", GetColor(255, 255, 255));
}

void SceneGame::End()
{
}

bool SceneGame::GetHit(Player* player, shared_ptr<Enemy> enemy)
{
	VECTOR langeVec = VSub(enemy->GetPos(), player->GetPos());
	float ans = VSize(langeVec);
	//“–‚½‚è”»’è‚Ì‘å‚«‚³‚æ‚è‚à‹——£‚ª‹ß‚©‚Á‚½‚ç
	if (player->GetScale() + enemy->GetScale() > ans)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
