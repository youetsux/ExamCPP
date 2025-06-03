#include <DxLib.h>
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

namespace
{
	const int ENEMY_NUM = 10 * 7; // �G�̐�
	const int ENEMY_COL_SIZE = 10; // �G�̗�
	const int ENEMY_ROW_SIZE = 7; // �G�̍s��
	bool IntersectRect(const Rect &_a, const Rect &_b)
	{
		// X�������̏d�Ȃ�𔻒�
		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);

		// Y�������̏d�Ȃ�𔻒�
		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);

		// X����Y���̗����ŏd�Ȃ��Ă���ΏՓ˂��Ă���
		return xOverlap && yOverlap;
	}
}

Stage::Stage()
	:GameObject(), player_(nullptr), hBackground(-1)
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
	hBackground = LoadGraph("Assets\\bg.png");
}

Stage::~Stage()
{
}

void Stage::Update()
{
	//�����ɓ����蔻���`�������I
	std::vector<Bullet*> bullets = player_->GetAllBullets();
	for (auto& e : enemy_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFired() && e->IsAlive()) {
				if (IntersectRect(e->GetRect(), b->GetRect()))
				{
					if (b->IsFired())
						b->SetFired(false);
					if (e->IsAlive())
						e->SetAlive(false);
				}
			}
		}
	}

}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackground, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
