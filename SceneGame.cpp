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
#include "Map.h"
#include "ProgressString.h"
namespace
{
	constexpr int kGroundObstructNum = 10;
}
SceneGame::SceneGame(SceneManager& sceneManager, DataManager& dataManager) :
	SceneBase(sceneManager, dataManager),
	m_timeCount(0),
	m_appTime(10)
{
	m_numberHandle[0] = LoadGraph("data/image/0.png");
	m_numberHandle[1] = LoadGraph("data/image/1.png");
	m_numberHandle[2] = LoadGraph("data/image/2.png");
	m_numberHandle[3] = LoadGraph("data/image/3.png");
	m_numberHandle[4] = LoadGraph("data/image/4.png");
	m_numberHandle[5] = LoadGraph("data/image/5.png");
	m_numberHandle[6] = LoadGraph("data/image/6.png");
	m_numberHandle[7] = LoadGraph("data/image/7.png");
	m_numberHandle[8] = LoadGraph("data/image/8.png");
	m_numberHandle[9] = LoadGraph("data/image/9.png");

	m_progressStringHandle[0] = LoadGraph("data/image/20s.png");
	m_progressStringHandle[1] = LoadGraph("data/image/40s.png");
	m_progressStringHandle[2] = LoadGraph("data/image/60s.png");
	m_progressStringHandle[3] = LoadGraph("data/image/80s.png");

	m_timerMap['0'] = m_numberHandle[0];
	m_timerMap['1'] = m_numberHandle[1];
	m_timerMap['2'] = m_numberHandle[2];
	m_timerMap['3'] = m_numberHandle[3];
	m_timerMap['4'] = m_numberHandle[4];
	m_timerMap['5'] = m_numberHandle[5];
	m_timerMap['6'] = m_numberHandle[6];
	m_timerMap['7'] = m_numberHandle[7];
	m_timerMap['8'] = m_numberHandle[8];
	m_timerMap['9'] = m_numberHandle[9];

	m_pPlayer = std::make_shared<Player>();
	m_pEnemy.resize(100);
	m_pCamera = std::make_shared<Camera>();
	//	m_pBg = std::make_shared<Bg>();
	m_pObstruct.resize(100);
	m_enemyPopData = dataManager.GetData();
	m_pMap = make_shared<Map>();
	m_pMap->Load();
	m_pProgressString.resize(20);
	for (int i = 0; i < m_pProgressString.size(); i++)
	{
		m_pProgressString[i] = std::make_shared<ProgressString>();
	}

	SetFogEnable(true);
	SetFogStartEnd(1000, 2000);
	SetFogColor(0, 0, 0);
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
	m_pMap->Update(*m_pPlayer);
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
	if (m_appTime == 90)
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
		if (m_enemyPopData[m_appTime].left)
		{
			CreateEnemy(false);
		}
		if (m_enemyPopData[m_appTime].right)
		{
			CreateEnemy(true);
		}
	}
	if (m_appTime % 20 == 0)
	{
		if (m_appTime == 20)
		{
			for (int i = 0; i < m_pProgressString.size(); i++)
			{
				m_pProgressString[i]->Init(m_progressStringHandle[0]);
			}
		}
		if (m_appTime == 40)
		{
			for (int i = 0; i < m_pProgressString.size(); i++)
			{
				m_pProgressString[i]->Init(m_progressStringHandle[1]);
			}
		}
		if (m_appTime == 60)
		{
			for (int i = 0; i < m_pProgressString.size(); i++)
			{
				m_pProgressString[i]->Init(m_progressStringHandle[2]);
			}
		}
		if (m_appTime == 80)
		{
			for (int i = 0; i < m_pProgressString.size(); i++)
			{
				m_pProgressString[i]->Init(m_progressStringHandle[3]);
			}
		}
	}

	for (auto& progressString : m_pProgressString)
	{
		if (progressString)
		{
			progressString->Update();
		}
	}
}

void SceneGame::Draw()
{
	//	m_pBg->Draw();
	for (auto& progressString : m_pProgressString)
	{
		if (progressString)
		{
			progressString->Draw();
		}
	}
	m_pMap->Draw();
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
	DrawTimer();
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
			m_pEnemy[i] = std::make_shared<Enemy>(right, m_pPlayer->GetPos().x);
			m_pEnemy[i]->Init();
			return;
		}
	}
}

void SceneGame::DrawTimer()
{

	string timeNumber = to_string(m_appTime);

	char temp = timeNumber.at(0);

	if (m_appTime < 10)
	{
		DrawGraph(250, 0, m_timerMap[temp], true);
	}
	else
	{
		char temp2 = timeNumber.at(1);
		DrawGraph(225, 0, m_timerMap[temp], true);
		DrawGraph(275, 0, m_timerMap[temp2], true);
	}

}
