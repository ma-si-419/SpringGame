// 2023 Takeru Yui All Rights Reserved.
#pragma once
#include <vector>

class WorldSprite;
class Player;

/// <summary>
/// 2Dの背景マップ
/// </summary>
class Map
{
public:
	Map();
	~Map();

	void Load();
	void Update(Player& player);
	void Draw();

	// マップチップのサイズ
	static const float	ChipSize;
	static const int	ChipPixelSize;
	static const int	StageDataColNum = 12;		// マップ行
	static const int	StageDataRowNum = 15;		// マップ列

private:
	static const int Stage1Data[StageDataColNum][StageDataRowNum];

	std::vector<WorldSprite*> sprites;
	WorldSprite* bgSprite;
	int chipGraph;
//	int bgGraph;
};

