#include "Camera.h"
#include "Player.h"

Camera::Camera():
	m_hRota(),
	m_vRota(),
	m_tRota()
{
	SetCameraNearFar(10.0f, 2000.0f);
	// z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
	m_pos = VGet(-320.0f, 490.0f, -590.0f);
	SetCameraPositionAndAngle(m_pos, m_hRota, 0.77, m_tRota);
}

Camera::~Camera()
{
}

void Camera::Update(shared_ptr<Player> player)
{
	m_pos.x += 2.0f;
	SetCameraPositionAndAngle(m_pos, m_hRota, 0.77, m_tRota);
}

void Camera::Draw()
{
}


