#pragma once
#include <memory>
#include "SceneManager.h"
#include "DataManager.h"
class SceneBase
{
public:
	SceneBase(SceneManager& sceneManager,DataManager& dataManager);
	virtual ~SceneBase() {}
	//����������
	virtual void Init() = 0;	
	//�X�V����
	virtual void Update() = 0;	
	//�`�揈��
	virtual void Draw() = 0;
	//�V�[���𔲂���Ƃ��̏���
	virtual void End() = 0;		
protected:

	SceneManager& m_sceneManager;

	DataManager& m_dataManager;


};
