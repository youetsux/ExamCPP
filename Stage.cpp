#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10 * 7; // �G�̐�
	const int ENEMY_COL_SIZE = 10; // �G�̗�
	const int ENEMY_ROW_SIZE = 7; // �G�̍s��
}

Stage::Stage()
	:GameObject(), player_(nullptr)
{
	AddGameObject(this); // �X�e�[�W�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
	player_ = new Player(); // �v���C���[�I�u�W�F�N�g�̐���
	enemy_ = std::vector<Enemy*>(ENEMY_NUM); // �G�I�u�W�F�N�g�̐���
	for (int i = 0; i < ENEMY_NUM; i++) {
		int col = i % ENEMY_COL_SIZE; // ��
		int row = i / ENEMY_COL_SIZE; // �s
		ETYPE enemyType[ENEMY_ROW_SIZE] = {BOSS, KNIGHT, MID, ZAKO, ZAKO, ZAKO, ZAKO }; // �G�̎��
		enemy_[i] = new Enemy(i, enemyType[row]); // �G�I�u�W�F�N�g�̐���

		enemy_[i]->SetPos(col * 55.0f, row * 50.0f); // �G�̏����ʒu��ݒ�

	}
}

Stage::~Stage()
{
}

void Stage::Update()
{

}

void Stage::Draw()
{

}
