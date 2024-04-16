#pragma once
#include "SceneBase.h"
#include "DxLib.h"
#include "Data.h"
#include <memory>
#include <vector>
#include <map>

using namespace std;

class Enemy;
class Player;
class Camera;
class Obstruct;
class Bg;
class Map;
class ProgressString;
class SceneGame : public SceneBase
{
public:
	SceneGame(SceneManager& sceneManager, DataManager& dataManager);
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
	//�G�l�~�[�𐶐�����֐�
	void CreateEnemy(bool right);
	//�^�C�}�[��\������
	void DrawTimer();

	shared_ptr<Player> m_pPlayer;
	vector<shared_ptr<Enemy>> m_pEnemy;
	shared_ptr<Camera> m_pCamera;
	vector<shared_ptr<Obstruct>> m_pObstruct;
	vector<PopData> m_enemyPopData;
	shared_ptr<Map> m_pMap;
	//	shared_ptr<Bg> m_pBg;

	int m_timeCount;
	int m_appTime;
	int m_numberHandle[10];
	int m_progressStringHandle[4];
	map<char, int> m_timerMap;
	vector<shared_ptr<ProgressString>> m_pProgressString;

};

