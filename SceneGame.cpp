#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneFailed.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Obstruct.h"
#include "Data.h" 
#include "Map.h"
#include "ProgressString.h"
namespace
{
	constexpr int kGroundObstructNum = 10;
	constexpr double kCountDownScaleMax = 4.0;
	constexpr double kCountDownScaleMin = 1.0;
}
SceneGame::SceneGame(SceneManager& sceneManager, DataManager& dataManager) :
	SceneBase(sceneManager, dataManager),
	m_timeCount(0),
	m_appTime(0),
	m_countDownCount(3),
	m_startFlag(false),
	m_countDownScale(kCountDownScaleMax),
	m_countDownTimer(0)
{
	m_progressStringHandle[0] = LoadGraph("data/image/20s.png");
	m_progressStringHandle[1] = LoadGraph("data/image/40s.png");
	m_progressStringHandle[2] = LoadGraph("data/image/60s.png");
	m_progressStringHandle[3] = LoadGraph("data/image/80s.png");

	m_timerMap['0'] = LoadGraph("data/image/0.png");
	m_timerMap['1'] = LoadGraph("data/image/1.png");
	m_timerMap['2'] = LoadGraph("data/image/2.png");
	m_timerMap['3'] = LoadGraph("data/image/3.png");
	m_timerMap['4'] = LoadGraph("data/image/4.png");
	m_timerMap['5'] = LoadGraph("data/image/5.png");
	m_timerMap['6'] = LoadGraph("data/image/6.png");
	m_timerMap['7'] = LoadGraph("data/image/7.png");
	m_timerMap['8'] = LoadGraph("data/image/8.png");
	m_timerMap['9'] = LoadGraph("data/image/9.png");

	m_bgmHandle = LoadSoundMem("data/sound/gameBgm.mp3");
	m_timerSeHandle = LoadSoundMem("data/sound/timerSe.mp3");

	ChangeVolumeSoundMem(170, m_bgmHandle);

	m_pPlayer = std::make_shared<Player>();
	m_pEnemy.resize(100);
	m_pCamera = std::make_shared<Camera>();
	//	m_pBg = std::make_shared<Bg>();
	m_pObstruct.resize(100);
	m_enemyPopData = dataManager.GetData();
	m_pStoneMap = make_shared<Map>();
	m_pStoneMap->Load();
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
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
	for (int i = 0; i < kGroundObstructNum; i++)
	{
		float posX = (2150 / kGroundObstructNum) * i - 250;
		CreateObstruct(VGet(posX, 100, 0));
		CreateObstruct(VGet(posX, 100, 400));
	}
	for (auto& obstruct : m_pObstruct)
	{
		if (obstruct)
		{
			obstruct->Init();
		}
	}
}

void SceneGame::Update()
{
	if (!m_startFlag)
	{
		StartCountDown();
	}
	if (m_startFlag)
	{
		m_pStoneMap->Update(*m_pPlayer);
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
			StopSoundMem(m_bgmHandle);
			m_sceneManager.ChangeScene(std::make_shared<SceneClear>(m_sceneManager, m_dataManager));
			return;
		}
		for (int i = 0; i < m_pEnemy.size(); i++)
		{
			if (m_pEnemy[i] && GetHit(m_pPlayer, m_pEnemy[i]))
			{
				StopSoundMem(m_bgmHandle);
				m_sceneManager.ChangeScene(std::make_shared<SceneFailed>(m_sceneManager, m_dataManager));
			}
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
		if (m_appTime % 20 == 0 && m_appTime != 0)
		{
			PlaySoundMem(m_timerSeHandle, DX_PLAYTYPE_BACK);
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
	m_pStoneMap->Draw();
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
	if (!m_startFlag)
	{
		DrawRotaGraph(Data::kScreenWidth / 2, Data::kScreenHeight / 2,
			m_countDownScale, 0.0, m_timerMap[m_countDownNum], true);
	}
}

void SceneGame::End()
{
}

bool SceneGame::GetHit(shared_ptr<Player> player, shared_ptr<Enemy> enemy)
{
	VECTOR playerPos = player->GetPos();
	playerPos.y += Data::kPlayerHeight;
	VECTOR langeVec = VSub(enemy->GetPos(), playerPos);
	float ans = VSize(langeVec);
	//“–‚½‚è”»’è‚Ì‘å‚«‚³‚æ‚è‚à‹——£‚ª‹ß‚©‚Á‚½‚ç
	if (Data::kHitScale * 2 > ans)
	{
		StopSoundMem(player->GetLoopSe());
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

void SceneGame::StartCountDown()
{
	m_countDownNum = '0' + m_countDownCount;
	m_countDownTimer++;
	if (m_countDownTimer > 90)
	{
		m_countDownCount--;
		if (m_countDownCount == 0)
		{
			m_startFlag = true;
		}
		m_countDownScale = kCountDownScaleMax;
		m_countDownTimer = 0;
	}
	if (m_countDownScale > kCountDownScaleMin)
	{
		m_countDownScale -= 0.2;
	}
}
