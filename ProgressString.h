#pragma once
#include "DxLib.h"
class ProgressString
{
public:
	ProgressString();
	~ProgressString();

	void Init(int num);
	void Update();
	void Draw();

private:
	VECTOR m_pos;
	int m_handle;
	float m_speed;

};

