#pragma once
#include "SceneBase.h"
class SceneClear : public SceneBase
{
public:
	SceneClear(SceneManager& sceneManager);
	~SceneClear();
	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�V�[���𔲂���Ƃ��̏���
	void End();
};
