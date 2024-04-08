#pragma once
#include "SceneBase.h"
#include <memory>
#include <vector>

using namespace std;

class Enemy;
class Player;
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
	bool GetHit(Player* player, shared_ptr<Enemy> enemy);
	Player* m_pPlayer;
	vector<shared_ptr<Enemy>> m_pEnemy;
};

