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
/// �R���X�g���N�^
/// </summary>
Map::Map()
	: chipGraph(-1)
{
	// �����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
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
/// ���[�h
/// </summary>
void Map::Load()
{
	// �Ƃ肠�����}�b�v���[�h
	chipGraph = LoadGraph("data/image/rock.png");
//	bgGraph = LoadGraph("data/image/bgGraph.jpg");

	// WorldSprite���̐ݒ�ƈʒu������
	VECTOR chipLeftTopPos = VGet(0, StageDataColNum * ChipSize, 0);			// �}�b�v�̕`��J�n�ʒu�i����j
//	VECTOR bgPos = VGet(0, 0, 100);
	for (int i = 0; i < StageDataColNum; i++)
	{
		for (int j = 0; j < StageDataRowNum; j++)
		{
			auto sprite = new WorldSprite();
			sprite->Init(chipGraph, ChipPixelSize, Stage1Data[i][j]);
			VECTOR chipHalfOffset = VGet(-Map::ChipSize * 0.5f, -Map::ChipSize * 0.5f, 0);					// �}�b�v�`�b�v�̔����T�C�Y�����ɂ��炷�I�t�Z�b�g
			VECTOR chipPos = VAdd(VGet(j * Map::ChipSize, (-i - 1) * Map::ChipSize, 0), chipHalfOffset);	// �^�񒆃s�{�b�g�Ȃ̂Ń}�b�v�`�b�v�����T�C�Y���炷+�n�ʂȂ̂ň����
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
/// �X�V
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
/// �`��
/// </summary>
void Map::Draw()
{
	// �䂭�䂭�̓J�����������Ă��āA�J�����͈͈ȊO�\�����Ȃ��悤��
	for (const auto& sprite : sprites)
	{
		sprite->Draw();
	}
}


