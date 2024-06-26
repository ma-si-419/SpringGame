#pragma once
#pragma once
#include "DxLib.h"
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
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
	//アニメーションを変更する
	void ChangeAnim(int animNum);
	//ループするSeを返す
	int GetLoopSe() { return m_secondJumpSeHandle; }
private:
	struct Status
	{
		VECTOR pos;
		VECTOR angle;
		float scale;
		float speed;
		float jumpPower;
		float fallSpeed;
	};

	Status m_status;
	float m_jumpSpeed;
	bool m_isJump;
	bool m_isAirJump;
	bool m_isSpace;
	int m_handle;
	bool m_isRightLane;
	bool m_isMoveLane;
	bool m_isJumpIdle;
	float m_animTime;
	float m_animTotalTime;
	int m_attachAnim;
	int m_jumpSeHandle;
	int m_secondJumpSeHandle;

};