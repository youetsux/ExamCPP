#pragma once
#include "GameObject.h"



class Player :
    public GameObject
{
	int hImage_;  //�v���C���[�̉摜�n���h��
	float x_, y_; //�v���C���[�̍��W
	float speed_; //�v���C���[�̈ړ����x
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
};

