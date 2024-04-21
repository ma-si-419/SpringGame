// 2023 Takeru Yui All Rights Reserved.
#pragma once
#include <vector>

class WorldSprite;
class Player;

/// <summary>
/// 2D�̔w�i�}�b�v
/// </summary>
class Map
{
public:
	Map();
	~Map();

	void Load();
	void Update(Player& player);
	void Draw();

	// �}�b�v�`�b�v�̃T�C�Y
	static const float	ChipSize;
	static const int	ChipPixelSize;
	static const int	StageDataColNum = 12;		// �}�b�v�s
	static const int	StageDataRowNum = 15;		// �}�b�v��

private:
	static const int Stage1Data[StageDataColNum][StageDataRowNum];

	std::vector<WorldSprite*> sprites;
	WorldSprite* bgSprite;
	int chipGraph;
//	int bgGraph;
};

