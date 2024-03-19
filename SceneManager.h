#pragma once
#include<memory>
class SceneBase;
class SceneManager
{
public:
	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager();

	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�ʂ̃V�[���Ɉړ�����ۂɎg�p����֐�
	void ChangeScene(std::shared_ptr<SceneBase> next);
private:
	std::shared_ptr<SceneBase> m_pScene;
};

