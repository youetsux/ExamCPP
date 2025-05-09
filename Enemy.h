#pragma once
#include "GameObject.h"


class Enemy :
    public GameObject
{
	int hImage_;  //�G�̉摜�n���h��
	float x_, y_; //�G�̍��W
	float speed_; //�G�̈ړ����x
	bool isAlive_; //�G�̐���
public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	void SetPos(float x, float y) { x_ = x; y_ = y; } //�G�̍��W��ݒ�
};

