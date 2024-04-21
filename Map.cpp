// 2023 Takeru Yui All Rights Reserved.
#include<vector>
#include "Map.h"
#include "Player.h"
#include "DxLib.h"
#include "WorldSprite.h"

const int Map::Stage1Data[StageDataColNum][StageDataRowNum] =
{
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1, 0, 1,-1, 0, 1,-1,-1, 0, 1,-1,-1, 0, 1},
	{-1,-1, 2, 3,-1, 2, 3,-1,-1, 2, 3,-1,-1, 2, 3},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
};

const float Map::ChipSize = 200.0f;
const int Map::ChipPixelSize = 400;

/// <summary>
/// コンストラクタ
/// </summary>
Map::Map()
	: chipGraph(-1)
{
	// 処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
Map::~Map()
{
	for (const auto& sprite : sprites)
	{
		if (sprite != nullptr)
		{
			delete sprite;
		}
	}
	sprites.clear();
}

/// <summary>
/// ロード
/// </summary>
void Map::Load()
{
	// とりあえずマップロード
	chipGraph = LoadGraph("data/image/rock.png");
//	bgGraph = LoadGraph("data/image/bgGraph.jpg");

	// WorldSprite実体設定と位置初期化
	VECTOR chipLeftTopPos = VGet(0, StageDataColNum * ChipSize, 0);			// マップの描画開始位置（左上）
//	VECTOR bgPos = VGet(0, 0, 100);
	for (int i = 0; i < StageDataColNum; i++)
	{
		for (int j = 0; j < StageDataRowNum; j++)
		{
			auto sprite = new WorldSprite();
			sprite->Init(chipGraph, ChipPixelSize, Stage1Data[i][j]);
			VECTOR chipHalfOffset = VGet(-Map::ChipSize * 0.5f, -Map::ChipSize * 0.5f, 0);					// マップチップの半分サイズ左下にずらすオフセット
			VECTOR chipPos = VAdd(VGet(j * Map::ChipSize, (-i - 1) * Map::ChipSize, 0), chipHalfOffset);	// 真ん中ピボットなのでマップチップ半分サイズずらす+地面なので一つ下に
			chipPos = VAdd(chipPos, chipLeftTopPos);
			sprite->SetTransform(chipPos, Map::ChipSize);
			sprites.push_back(sprite);
		}
	}
	//auto sprite = new WorldSprite();
	//sprite->Init(bgGraph,0,0);
	//sprite->SetTransform(bgPos,0);
	//bgSprite.push_back(sprite);

}

/// <summary>
/// 更新
/// </summary>
void Map::Update(Player& player)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i]->GetPos().x < player.GetPos().x - 500) 
		{
			auto temp = sprites[i]->GetPos();
			temp.x += 3000;
			sprites[i]->SetTransform(temp, Map::ChipSize);
		}
	}
}

/// <summary>
/// 描画
/// </summary>
void Map::Draw()
{
	// ゆくゆくはカメラを持ってきて、カメラ範囲以外表示しないように
	for (const auto& sprite : sprites)
	{
		sprite->Draw();
	}
}


