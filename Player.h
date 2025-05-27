#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet; // �O���錾

class Player :
    public GameObject
{
	int hImage_;  //�v���C���[�̉摜�n���h��
	float x_, y_; //�v���C���[�̍��W
	float speed_; //�v���C���[�̈ړ����x
	std::vector<Bullet *> bullets_; // �v���C���[�����˂����e�̃x�N�^�[
	Bullet* GetActiveBullet();
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void Shoot(); // �e�𔭎˂���֐�
	Rect GetRect() const { return { x_, y_, PLAYER_IMAGE_WIDTH, PLAYER_IMAGE_HEIGHT }; } // �v���C���[�̋�`���擾
	std::vector<Bullet*> GetAllBullets() const { return bullets_; } // �S�Ă̒e���擾
};

