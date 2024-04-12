#include "Enemy.h"
#include "math.h"
#include "Data.h"

Enemy::Enemy():
	m_shakePosY(),
	m_handle(-1)
{
	m_status.pos = VGet(0.0f, 0.0f, 0.0f);
	m_status.scale = 60.0f;
	m_status.speed = 8.0f;
	// ３Ｄモデルの読み込み
	m_handle = MV1LoadModel("data/model/Enemy.mv1");
	if (m_handle < 0)
	{
		printfDx("データ読み込みに失敗");
	}
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	m_status.pos = VGet(600.0f, 198.0f, 0.0f);
	MV1SetRotationXYZ(m_handle, VGet(0,(DX_PI_F / 180) * 90,0));
}

void Enemy::Update()
{
	m_shakePosY += static_cast<float>((DX_PI / 180) * 5);

	m_status.pos.y += sinf(m_shakePosY) * 3;
	//m_status.pos.x -= m_status.speed;
	MV1SetPosition(m_handle, m_status.pos);
}

void Enemy::Draw()
{
	MV1DrawModel(m_handle);
	DrawSphere3D(m_status.pos, Data::kHitScale, 64, GetColor(0, 255, 0), GetColor(0, 0, 255), true);
}
