#include "Player.h"
#include "Data.h"
namespace
{
	//落ちる速度の最大速度
	constexpr float kMaxFallSpeed = -20.0f;
	//地面の高さ
	constexpr float kGroundHeight = 198.0f;
	//左レーンの座標
	constexpr float kLeftLanePosZ = 300.0f;
}

Player::Player() :
	m_isJump(false),
	m_isAirJump(false),
	m_jumpSpeed(0),
	m_handle(-1),
	m_isSpace(false),
	m_isRightLane(true)
{
	m_status.pos = VGet(0.0f, 0.0f, 0.0f);
	m_status.angle = VGet(0.0f, (DX_PI_F / 180) * 270, 0.0f);
	m_status.scale = 60.0f;
	m_status.jumpPower = 30.0f;
	m_status.fallSpeed = 1.0f;
	// ３Ｄモデルの読み込み
	m_handle = MV1LoadModel("data/model/Player.mv1");
	if (m_handle < 0)
	{
		printfDx("データ読み込みに失敗");
	}
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

	if (!m_isSpace)
	{
		if (CheckHitKey(KEY_INPUT_SPACE))
		{

			//ジャンプしていないときにSPACEが押されたら
			if (!m_isJump)
			{
				m_isJump = true;
				m_jumpSpeed = m_status.jumpPower;
				m_isSpace = true;
			}
			//空中でジャンプしたら
			else if (!m_isAirJump)
			{
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
	//ジャンプ中の処理
	if (m_isJump)
	{
		m_status.pos.y += m_jumpSpeed;
		if (m_jumpSpeed > kMaxFallSpeed)
		{
			m_jumpSpeed -= m_status.fallSpeed;
		}
	}
	//ジャンプしていないときの処理
	else if (m_isRightLane)
	{
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			m_isRightLane = false;
			m_isJump = true;
			m_jumpSpeed = m_status.jumpPower;
			m_isMoveLane = true;
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
		}
	}
	//二段ジャンプをわかりやすくするために
	if (m_isAirJump)
	{
		m_status.angle.x -= 0.5f;
	}
	//左右移動中の処理
	if (m_isMoveLane)
	{
		//右に移動中
		if (m_isRightLane)
		{
			m_status.pos.z -= 5.0f;
			if (m_status.pos.z < 0)
			{
				m_status.pos.z = 0;
			}
		}
		//左に移動中
		else
		{
			m_status.pos.z += 5.0f;
			if (m_status.pos.z > kLeftLanePosZ)
			{
				m_status.pos.z = kLeftLanePosZ;
			}
		}
	}
	//地面についた時の処理
	if (m_status.pos.y < kGroundHeight)
	{
		m_status.pos.y = kGroundHeight;
		m_status.angle.x = 0;
		m_isJump = false;
		m_isAirJump = false;
		m_isMoveLane = false;
	}
	MV1SetPosition(m_handle, m_status.pos);
	MV1SetRotationXYZ(m_handle, m_status.angle);
}

void Player::Draw()
{
	MV1DrawModel(m_handle);
	DrawSphere3D(m_status.pos, Data::m_HitScale, 64, GetColor(0, 255, 0), GetColor(0, 0, 255), true);
}
