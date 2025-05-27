#include "Enemy.h"
#include "DxLib.h"
#include <string>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48; // �G�̉摜�̕�;
	const int ENEMY_IMAGE_HEIGHT = 48; // �G�̉摜�̍���;

	const float ENEMY_INIT_X = 100; // �G�̏���X���W;
	const float ENEMY_INIT_Y = 100; // �G�̏���Y���W;
	const float ENEMY_INIT_SPEED = 100.0f; // �G�̏����ړ����x;
}


Enemy::Enemy()
	:GameObject(), 
	 hImage_(-1), 
	 x_(0), y_(0), 
	 speed_(0) 
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png"); // �G�̉摜��ǂݍ���
	if (hImage_ == -1) {
		// �摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		// �G���[��Ԃ��ăQ�[���I��
	}
	x_ = ENEMY_INIT_X; // �������W
	y_ = ENEMY_INIT_Y; // �������W
	speed_ = ENEMY_INIT_SPEED; // �ړ����x
	//id��type�����Ă�����Ȃ������Ƃ��̂����������ɏ����˂�
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	ID_(id), type_(type)

{	
	//ETYPE::ZAKO =>  "Assets/tiny_ship10.png"
	//ETYPE::MID = > "Assets/tiny_ship18.png"
	//ETYPE::KNIGHT = > "Assets/tiny_ship16.png"
	//ETYPE::BOSS = > "Assets/tiny_ship9.png"
	// �摜�̓ǂݍ���
	std::string imagePath[MAX_ETYPE] = {
		"Assets\\tiny_ship10.png", // ZAKO
		"Assets\\tiny_ship18.png", // MID
		"Assets\\tiny_ship16.png", // KNIGHT
		"Assets\\tiny_ship9.png"   // BOSS
	};

	hImage_ = LoadGraph( imagePath[type_].c_str() ); // �G�̉摜��ǂݍ���
	if (hImage_ == -1) {
		// �摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		// �G���[��Ԃ��ăQ�[���I��
	}
	x_ = ENEMY_INIT_X; // �������W
	y_ = ENEMY_INIT_Y; // �������W
	speed_ = ENEMY_INIT_SPEED; // �ړ����x
	AddGameObject(this); // �G�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
}

Enemy::~Enemy()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_); // �摜�̃n���h�������
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	//��ʂ̍���ɓG�摜��\��
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT,
		hImage_, TRUE);
}
