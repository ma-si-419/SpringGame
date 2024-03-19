#pragma once
#include "SceneBase.h"
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
};

