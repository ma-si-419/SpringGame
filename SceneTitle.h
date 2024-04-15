#pragma once
#include "SceneBase.h"
class SceneTitle : public SceneBase
{
public:
	SceneTitle(SceneManager& sceneManager, DataManager& dataManager);
	~SceneTitle();
	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�V�[���𔲂���Ƃ��̏���
	void End();
private:
	int m_titleHandle;
	float m_boxScale;
	float m_boxMag;
};

