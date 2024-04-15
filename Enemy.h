#pragma once
#include "DxLib.h"
class Enemy
{
public:
	//コンストラクタ
	Enemy(bool right);
	//デストラクタ
	~Enemy();
	//初期化処理
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//座標を取得する
	VECTOR GetPos() { return m_status.pos; }
	//当たり判定の大きさを取得する
	float GetScale() { return m_status.scale; }
private:
	struct Status
	{
		VECTOR pos;
		float scale;
		float speed;
	};
	Status m_status;
	int m_handle;
	float m_shakePosY;
};

