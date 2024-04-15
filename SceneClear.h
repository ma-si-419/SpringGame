#pragma once
#include "SceneBase.h"
class SceneClear : public SceneBase
{
public:
	SceneClear(SceneManager& sceneManager,DataManager& dataManager);
	~SceneClear();
	//初期化処理
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//シーンを抜けるときの処理
	void End();
private:
	int m_handle;
};

