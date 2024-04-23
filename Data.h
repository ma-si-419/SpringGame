#pragma once
//全体で共有する定数を保存する
namespace Data
{
	//移動速度
	constexpr float kScrollSpeed = 5.0f;
	//当たり判定の大きさ
	constexpr float kHitScale = 64.0f;
	//プレイヤーの当たり判定の高さ
	constexpr float kPlayerHeight = 96;
	//画面の大きさ
	constexpr int kScreenHeight = 500;
	constexpr int kScreenWidth = 650;
};