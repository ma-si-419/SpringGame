#pragma once
#include "DxLib.h"
class Enemy
{
public:
	//�R���X�g���N�^
	Enemy(bool right,int posX);
	//�f�X�g���N�^
	~Enemy();
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
private:

	void ChangeAnim(int animNum);

	struct Status
	{
		VECTOR pos;
		float scale;
		float speed;
	};
	Status m_status;
	int m_handle;
	float m_shakePosY;
	int m_attachAnim;
	float m_animTime;
	float m_animTotalTime;
};

