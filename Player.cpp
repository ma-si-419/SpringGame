#include "Player.h"

namespace
{
	//�����鑬�x�̍ő呬�x
	constexpr float kMaxFallSpeed = -20.0f;
	//�n�ʂ̍���
	constexpr float kGroundHeight = 100.0f;
}

Player::Player() :
	m_isJump(false),
	m_jumpSpeed(0)
{
	m_status.pos = VGet(0.0f, 0.0f, 0.0f);
	m_status.scale = 20.0f;
	m_status.jumpPower = 25.0f;
	m_status.fallSpeed = 1.0f;
}

Player::~Player()
{
}

void Player::Init()
{
	m_status.pos = VGet(100.0f, kGroundHeight, 0.0f);
}

void Player::Update()
{
	//�W�����v���Ă��Ȃ��Ƃ���SPACE�������ꂽ��
	if (CheckHitKey(KEY_INPUT_SPACE) && !m_isJump)
	{
		m_isJump = true;
		m_jumpSpeed = m_status.jumpPower;
	}
	//�W�����v���̏���
	if (m_isJump)
	{
		m_status.pos.y += m_jumpSpeed;
		if (m_jumpSpeed > kMaxFallSpeed)
		{
			m_jumpSpeed -= m_status.fallSpeed;
		}
	}
	//�n�ʂ������ɍs���Ȃ��悤��
	if (m_status.pos.y < kGroundHeight)
	{
		m_status.pos.y = kGroundHeight;
		m_isJump = false;
	}
}

void Player::Draw()
{
	DrawSphere3D(m_status.pos, m_status.scale, 32, 
		GetColor(255, 255, 255), GetColor(100, 100, 100), true);
}
