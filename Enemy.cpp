#include "Enemy.h"

Enemy::Enemy()
{
	m_status.pos = VGet(0.0f, 0.0f, 0.0f);
	m_status.scale = 20.0f;
	m_status.speed = 5.0f;
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	m_status.pos = VGet(600.0f, 100.0f, 0.0f);
}

void Enemy::Update()
{
	m_status.pos.x -= m_status.speed;
}

void Enemy::Draw()
{
	DrawSphere3D(m_status.pos, m_status.scale, 32,
		GetColor(255, 0, 0), GetColor(255, 0, 0), true);
}
