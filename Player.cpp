#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"


namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; // �v���C���[�̏����ړ����x;
	const int PLAYER_IMAGE_WIDTH = 48; // �v���C���[�̉摜�̕�;
	const int PLAYER_IMAGE_HEIGHT = 48; // �v���C���[�̉摜�̍���;
	const int PLAYER_BASE_MARGIN = 32; // �v���C���[�̊�}�[�W��;

	const float PLAYER_INIT_X = WIN_WIDTH/2 - PLAYER_IMAGE_WIDTH/2; // �v���C���[�̏���X���W;
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN; // �v���C���[�̏���Y���W;
}



Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // �v���C���[�̉摜��ǂݍ���
	if (hImage_ == -1) {
		// �摜�̓ǂݍ��݂Ɏ��s�����ꍇ�̃G���[�n���h�����O
		// �G���[��Ԃ��ăQ�[���I��
	}
	x_ = PLAYER_INIT_X; // �������W
	y_ = PLAYER_INIT_Y; // �������W
	speed_ = PLAYER_INIT_SPEED; // �ړ����x
}

Player::~Player()
{
}

void Player::Update()
{
	float dt = GetDeltaTime(); // �t���[���Ԃ̎��ԍ����擾
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		x_ =  x_  - speed_ * dt; // ���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		x_ = x_ + speed_ * dt; // �E�Ɉړ�
	}
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT,
		hImage_, TRUE);
}
