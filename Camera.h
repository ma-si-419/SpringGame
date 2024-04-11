#pragma once
#include "DxLib.h"
#include <memory>
using namespace std;
class Player;
class Camera
{
public:
	Camera();
	~Camera();

	void Update(shared_ptr<Player> player);
	void Draw();
private:
	VECTOR m_pos;

	float m_hRota;
	float m_vRota;
	float m_tRota;
};

