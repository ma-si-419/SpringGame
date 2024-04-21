#pragma once
#pragma once
#include "DxLib.h"
class Player
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();
	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//���W���擾����
	VECTOR GetPos() { return m_status.pos; }
	//�����蔻��̑傫�����擾����
	float GetScale() { return m_status.scale; }
	//�A�j���[�V������ύX����
	void ChangeAnim(int animNum);
	//���[�v����Se��Ԃ�
	int GetLoopSe() { return m_secondJumpSeHandle; }
private:
	struct Status
	{
		VECTOR pos;
		VECTOR angle;
		float scale;
		float speed;
		float jumpPower;
		float fallSpeed;
	};

	Status m_status;
	float m_jumpSpeed;
	bool m_isJump;
	bool m_isAirJump;
	bool m_isSpace;
	int m_handle;
	bool m_isRightLane;
	bool m_isMoveLane;
	bool m_isJumpIdle;
	float m_animTime;
	float m_animTotalTime;
	int m_attachAnim;
	int m_jumpSeHandle;
	int m_secondJumpSeHandle;

};