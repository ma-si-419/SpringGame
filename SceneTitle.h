#pragma once
#include "SceneBase.h"
class SceneTitle : public SceneBase
{
public:
	SceneTitle(SceneManager& sceneManager, DataManager& dataManager);
	~SceneTitle();
	//初期化処理
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//シーンを抜けるときの処理
	void End();
private:
	int m_titleHandle;
	float m_boxScale;
	float m_boxMag;
};

