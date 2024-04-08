#pragma once
#include "SceneBase.h"
#include <memory>
#include <vector>

using namespace std;

class Enemy;
class Player;
class SceneGame : public SceneBase
{
public:
	SceneGame(SceneManager& sceneManager);
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
	bool GetHit(Player* player, shared_ptr<Enemy> enemy);
	Player* m_pPlayer;
	vector<shared_ptr<Enemy>> m_pEnemy;
};

