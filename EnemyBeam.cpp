#include "EnemyBeam.h"
#include "DxLib.h"

namespace
{
	const int ENEMY_BEAM_IMAGE_WIDTH = 11; // �e�̉摜�̕�
	const int ENEMY_BEAM_IMAGE_HEIGHT = 21; // �e�̉摜�̍���
	const float ENEMY_BEAM_INIT_SPEED = 250.0f; // �e�̏����ړ����x

}


EnemyBeam::EnemyBeam()
	:GameObject(), hImage_(-1), pos_({ -10,-10 }), 
	speed_(ENEMY_BEAM_INIT_SPEED), isFired_(true),
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT }) // �����T�C�Y��ݒ�
{
	hImage_ = LoadGraph("Assets\\ebeams.png"); // �e�̉摜��ǂݍ���

	AddGameObject(this); // �e�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
}

EnemyBeam::EnemyBeam(float x, float y)
	:GameObject(), hImage_(-1), pos_({x, y}),
	speed_(ENEMY_BEAM_INIT_SPEED), isFired_(true),//��ŏ���������I
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT })
{

	hImage_ = LoadGraph("Assets\\ebeams.png"); // �e�̉摜��ǂݍ���

	AddGameObject(this); // �e�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
}

EnemyBeam::EnemyBeam(Point pos_)
	:GameObject(), hImage_(-1), pos_({ pos_.x, pos_.y }),
	speed_(ENEMY_BEAM_INIT_SPEED), isFired_(true),
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH, ENEMY_BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\ebeams.png"); // �e�̉摜��ǂݍ���

	AddGameObject(this); // �e�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
}

EnemyBeam::~EnemyBeam()
{
	if (hImage_ != -1) {
		DeleteGraph(hImage_); // �摜�̉��
	}
	hImage_ = -1; // �摜�n���h���𖳌���
}

void EnemyBeam::Update()
{
	float dt = GetDeltaTime();
	pos_.y = pos_.y + speed_ * dt; // �e�̈ړ�
	if (pos_.y > WIN_HEIGHT) {
		isFired_ = false; // ��ʊO�ɏo���珀����Ԃɖ߂�
		SetAlive(false); // �Q�[���I�u�W�F�N�g���A�N�e�B�u�ɂ���
	}
}

void EnemyBeam::Draw()
{
	// ���˂���Ă�����`��
	if (isFired_)
	{
		DrawExtendGraphF(pos_.x, pos_.y, 
			pos_.x + imageSize_.x, pos_.y + imageSize_.y,
			hImage_, TRUE);
	}
}
