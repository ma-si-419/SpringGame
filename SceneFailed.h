#pragma once
#include "SceneBase.h"
class SceneFailed : public SceneBase
{
public:
	SceneFailed(SceneManager& sceneManager);
	~SceneFailed();
	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�V�[���𔲂���Ƃ��̏���
	void End();
};

