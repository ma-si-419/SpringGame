#include "Player.h"
#include "Data.h"
namespace
{
	//�����鑬�x�̍ő呬�x
	constexpr float kMaxFallSpeed = -40.0f;
	//�n�ʂ̍���
	constexpr float kGroundHeight = 198.0f;
	//�����[���̍��W
	constexpr float kLeftLanePosZ = 300.0f;
	//���胂�[�V����
	constexpr int kRunAnimNumber = 11;
	//�W�����v���[�V����
	constexpr int kJumpAnimNumber = 6;
	//�؋󃂁[�V����
	constexpr int kJumpIdleAnimNumber = 7;
}

Player::Player() :
	m_isJump(false),
	m_isAirJump(false),
	m_jumpSpeed(0),
	m_handle(-1),
	m_isSpace(true),
	m_isRightLane(true),
	m_isMoveLane(false),
	m_animTime(0),
	m_animTotalTime(0),
	m_attachAnim(0),
	m_isJumpIdle(false)
{
	m_status.pos = VGet(0.0f, 0.0f, 0.0f);
	m_status.angle = VGet(0.0f, (DX_PI_F / 180) * 270, 0.0f);
	m_status.scale = 60.0f;
	m_status.jumpPower = 30.0f;
	m_status.speed = 2.0f;
	m_status.fallSpeed = 1.2f;

	m_jumpSeHandle = LoadSoundMem("data/sound/jumpSe.mp3");
	m_secondJumpSeHandle = LoadSoundMem("data/sound/secondJumpSe.mp3");

	// �R�c���f���̓ǂݍ���
	m_handle = MV1LoadModel("data/model/Player.mv1");
	ChangeAnim(kRunAnimNumber);
	if (m_handle < 0)
	{
		printfDx("�f�[�^�ǂݍ��݂Ɏ��s");
	}
}

Player::~Player()
{
}

void Player::Init()
{
	m_status.pos = VGet(100.0f, kGroundHeight, 0.0f);
	MV1SetPosition(m_handle, m_status.pos);
	MV1SetRotationXYZ(m_handle, m_status.angle);
}

void Player::Update()
{

	m_status.pos.x += m_status.speed;
	if (!m_isSpace)
	{
		if (CheckHitKey(KEY_INPUT_SPACE))
		{

			//�W�����v���Ă��Ȃ��Ƃ���SPACE�������ꂽ��
			if (!m_isJump)
			{
				PlaySoundMem(m_jumpSeHandle, DX_PLAYTYPE_BACK);
				m_isJump = true;
				m_jumpSpeed = m_status.jumpPower;
				m_isSpace = true;
				ChangeAnim(kJumpAnimNumber);
			}
			//�󒆂ŃW�����v������
			else if (!m_isAirJump)
			{
				if (m_isRightLane && CheckHitKey(KEY_INPUT_LEFT))
				{
					m_isRightLane = false;
					m_jumpSpeed = m_status.jumpPower;
					m_isMoveLane = true;
				}
				else if (!m_isRightLane && CheckHitKey(KEY_INPUT_RIGHT))
				{
					m_isRightLane = true;
					m_jumpSpeed = m_status.jumpPower;
					m_isMoveLane = true;
				}
				PlaySoundMem(m_secondJumpSeHandle, DX_PLAYTYPE_LOOP);
				m_isAirJump = true;
				m_jumpSpeed = m_status.jumpPower;
				m_isSpace = true;
			}
		}
	}
	else
	{
		if (!CheckHitKey(KEY_INPUT_SPACE))
		{
			m_isSpace = false;
		}
	}
	//�W�����v���̏���
	if (m_isJump)
	{
		m_animTime += 0.5f;
		if (m_animTotalTime <= m_animTime)
		{
			m_animTime = 0;
			m_isJumpIdle = true;
		}
		if (m_isJumpIdle)
		{
			ChangeAnim(kJumpIdleAnimNumber);
			m_isJumpIdle = false;
		}
		m_status.pos.y += m_jumpSpeed;
		if (m_jumpSpeed > kMaxFallSpeed)
		{
			m_jumpSpeed -= m_status.fallSpeed;
		}
	}
	//�W�����v���Ă��Ȃ��Ƃ��̏���
	else if (m_isRightLane)
	{
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			m_isRightLane = false;
			m_isJump = true;
			m_jumpSpeed = m_status.jumpPower;
			m_isMoveLane = true;
			PlaySoundMem(m_jumpSeHandle, DX_PLAYTYPE_BACK);
			ChangeAnim(kJumpAnimNumber);
		}
	}
	else
	{
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			m_isRightLane = true;
			m_isJump = true;
			m_jumpSpeed = m_status.jumpPower;
			m_isMoveLane = true;
			PlaySoundMem(m_jumpSeHandle, DX_PLAYTYPE_BACK);
			ChangeAnim(kJumpAnimNumber);
		}
	}
	//��i�W�����v���킩��₷�����邽�߂�
	if (m_isAirJump)
	{
		m_status.angle.x -= 0.5f;
	}
	//���E�ړ����̏���
	if (m_isMoveLane)
	{
		//�E�Ɉړ���
		if (m_isRightLane)
		{
			m_status.pos.z -= 7.0f;
			if (m_status.pos.z < 0)
			{
				m_status.pos.z = 0;
			}
		}
		//���Ɉړ���
		else
		{
			m_status.pos.z += 7.0f;
			if (m_status.pos.z > kLeftLanePosZ)
			{
				m_status.pos.z = kLeftLanePosZ;
			}
		}
	}
	//�n�ʂɂ������̏���
	if (m_status.pos.y < kGroundHeight)
	{
		m_status.pos.y = kGroundHeight;
		m_status.angle.x = 0;
		m_isJump = false;
		m_isAirJump = false;
		m_isMoveLane = false;
		StopSoundMem(m_secondJumpSeHandle);
		ChangeAnim(kRunAnimNumber);
	}
	//�n�ʂɑ������Ă���Ƃ��̏���
	if (!m_isJump)
	{
		m_animTime += 0.5f;
		if (m_animTotalTime <= m_animTime)
		{
			m_animTime = 0;
		}
	}

	MV1SetAttachAnimTime(m_handle,m_attachAnim,m_animTime);
	MV1SetPosition(m_handle, m_status.pos);
	MV1SetRotationXYZ(m_handle, m_status.angle);
}

void Player::Draw()
{
	MV1DrawModel(m_handle);

	VECTOR colPos = m_status.pos;
	colPos.y += Data::kPlayerHeight;
//	DrawSphere3D(colPos, Data::kHitScale, 64, GetColor(0, 255, 0), GetColor(0, 0, 255), true);
}

void Player::ChangeAnim(int animNum)
{
	MV1DetachAnim(m_handle, m_attachAnim);
	m_attachAnim = MV1AttachAnim(m_handle, animNum);
	m_animTime = 0;
	m_animTotalTime = MV1GetAnimTotalTime(m_handle, animNum);
}
