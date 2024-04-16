#include "Enemy.h"
#include "math.h"
#include "Data.h"

Enemy::Enemy(bool right,int posX) :
	m_shakePosY(),
	m_handle(-1)
{
	if (right)
	{
		m_status.pos = VGet(1700.0f + posX, 198.0f, 0.0f);
	}
	else
	{
		m_status.pos = VGet(1700.0f + posX, 198.0f, 300.0f);
	}
	m_status.scale = 60.0f;
	m_status.speed = 8.0f;
	// ‚R‚cƒ‚ƒfƒ‹‚Ì“Ç‚İ‚İ
	m_handle = MV1LoadModel("data/model/Enemy.mv1");
	if (m_handle < 0)
	{
		printfDx("ƒf[ƒ^“Ç‚İ‚İ‚É¸”s");
	}
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	MV1SetRotationXYZ(m_handle, VGet(0, (DX_PI_F / 180) * 90, 0));
}

void Enemy::Update()
{
	m_shakePosY += static_cast<float>((DX_PI / 180) * 5);

	m_status.pos.y += sinf(m_shakePosY) * 3;
	m_status.pos.x -= m_status.speed;
	if (m_status.pos.x < -300.0f)
	{
		
	}
	MV1SetPosition(m_handle, m_status.pos);
}

void Enemy::Draw()
{
	MV1DrawModel(m_handle);
//	DrawSphere3D(m_status.pos, Data::kHitScale, 64, GetColor(0, 255, 0), GetColor(0, 0, 255), true);
}
