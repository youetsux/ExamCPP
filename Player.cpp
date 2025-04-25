#include "Player.h"
#include "DxLib.h"

namespace
{
	const float PLAYER_INIT_X = 0.0f; // プレイヤーの初期X座標;
	const float PLAYER_INIT_Y = 0.0f; // プレイヤーの初期Y座標;
	const float PLAYER_INIT_SPEED = 5.0f; // プレイヤーの初期移動速度;
	const int PLAYER_IMAGE_WIDTH = 64; // プレイヤーの画像の幅;
	const int PLAYER_IMAGE_HEIGHT = 64; // プレイヤーの画像の高さ;
}



Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // プレイヤーの画像を読み込む
	if (hImage_ == -1) {
		// 画像の読み込みに失敗した場合のエラーハンドリング
		// エラーを返してゲーム終了
	}
	x_ = PLAYER_INIT_X; // 初期座標
	y_ = PLAYER_INIT_Y; // 初期座標
	speed_ = PLAYER_INIT_SPEED; // 移動速度
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT,
		hImage_, TRUE);
}
