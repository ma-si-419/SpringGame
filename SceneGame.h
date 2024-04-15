#pragma once
#include "SceneBase.h"
#include "DxLib.h"
#include <memory>
#include <vector>

using namespace std;

class Enemy;
class Player;
class Camera;
class Obstruct;
class Bg;
class SceneGame : public SceneBase
{
public:
	SceneGame(SceneManager& sceneManager);
	~SceneGame();
	//����������
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�V�[���𔲂���Ƃ��̏���
	void End();
private:
	//�����蔻����Ƃ�֐�
	bool GetHit(shared_ptr<Player> player, shared_ptr<Enemy> enemy);
	//�n�ʂ𐶐�����֐�
	void CreateObstruct(VECTOR pos);
	
	shared_ptr<Player> m_pPlayer;
	vector<shared_ptr<Enemy>> m_pEnemy;
	shared_ptr<Camera> m_pCamera;
	vector<shared_ptr<Obstruct>> m_pObstruct;
//	shared_ptr<Bg> m_pBg;

	int m_count;
	int m_timeCount;
	int m_appTime;
};

