#pragma once
#include "SceneBase.h"
class SceneTitle : public SceneBase
{
public:
	SceneTitle(SceneManager& sceneManager);
	~SceneTitle();
	//初期化処理
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//シーンを抜けるときの処理
	void End();
};

