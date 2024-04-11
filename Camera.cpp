#include "Camera.h"
#include "Player.h"

Camera::Camera():
	m_hRota(),
	m_vRota(),
	m_tRota()
{
	SetCameraNearFar(0.1f, 10000.0f);
	// z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
	m_pos = VGet(-320.0f, 490.0f, -590.0f);
}

Camera::~Camera()
{
}

void Camera::Update(shared_ptr<Player> player)
{
	//// カメラに位置を反映.
	//if (CheckHitKey(KEY_INPUT_UP))
	//{
	//	m_pos.y += 10;
	//}
	//if (CheckHitKey(KEY_INPUT_DOWN))
	//{
	//	m_pos.y -= 10;
	//}
	//if (CheckHitKey(KEY_INPUT_RIGHT))
	//{
	//	m_pos.x += 10;
	//}
	//if (CheckHitKey(KEY_INPUT_LEFT))
	//{
	//	m_pos.x -= 10;
	//}
	//if (CheckHitKey(KEY_INPUT_W))
	//{
	//	m_pos.z += 10;
	//}
	//if (CheckHitKey(KEY_INPUT_S))
	//{
	//	m_pos.z -= 10;
	//}
	//if (CheckHitKey(KEY_INPUT_1))
	//{
	//	m_hRota += 0.01f;
	//}
	//if (CheckHitKey(KEY_INPUT_2))
	//{
	//	m_hRota -= 0.01f;
	//}
	//if (CheckHitKey(KEY_INPUT_3))
	//{
	//	m_vRota += 0.01f;
	//}
	//if (CheckHitKey(KEY_INPUT_4))
	//{
	//	m_vRota -= 0.01f;
	//}
	//if (CheckHitKey(KEY_INPUT_5))
	//{
	//	m_tRota += 0.01f;
	//}
	//if (CheckHitKey(KEY_INPUT_6))
	//{
	//	m_tRota -= 0.01f;
	//}

	SetCameraPositionAndAngle(m_pos, m_hRota, 0.77, m_tRota);
}

void Camera::Draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "%f %f %f", m_pos.x,m_pos.y,m_pos.z);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "%f", m_hRota);
	DrawFormatString(100, 300, GetColor(255, 255, 255), "%f", m_vRota);
	DrawFormatString(100, 400, GetColor(255, 255, 255), "%f", m_tRota);
}


