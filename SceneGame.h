#pragma once
#include "SceneBase.h"
#include "DxLib.h"
#include "Data.h"
#include <memory>
#include <vector>
#include <map>

using namespace std;

class Enemy;
class Player;
class Camera;
class Obstruct;
class Bg;
class Map;
class ProgressString;
class SceneGame : public SceneBase
{
public:
	SceneGame(SceneManager& sceneManager, DataManager& dataManager);
	~SceneGame();
	//初期化処理
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//シーンを抜けるときの処理
	void End();
private:
	//当たり判定をとる関数
	bool GetHit(shared_ptr<Player> player, shared_ptr<Enemy> enemy);
	//地面を生成する関数
	void CreateObstruct(VECTOR pos);
	//エネミーを生成する関数
	void CreateEnemy(bool right);
	//タイマーを表示する
	void DrawTimer();

	shared_ptr<Player> m_pPlayer;
	vector<shared_ptr<Enemy>> m_pEnemy;
	shared_ptr<Camera> m_pCamera;
	vector<shared_ptr<Obstruct>> m_pObstruct;
	vector<PopData> m_enemyPopData;
	shared_ptr<Map> m_pMap;
	//	shared_ptr<Bg> m_pBg;

	int m_timeCount;
	int m_appTime;
	int m_numberHandle[10];
	int m_progressStringHandle[4];
	map<char, int> m_timerMap;
	vector<shared_ptr<ProgressString>> m_pProgressString;

};

