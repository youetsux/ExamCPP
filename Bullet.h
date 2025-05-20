#pragma once
#include "GameObject.h"


class Bullet :
    public GameObject
{
private:
	int hImage_;  //�e�̉摜�n���h��
	float x_, y_; //�e�̍��W
	float speed_; //�e�̈ړ����x
	int isize_x, isize_y; //�e�̕\���T�C�Y
public:
	Bullet();
	Bullet(float x, float y);
	~Bullet();
	void Update() override;
	void Draw() override;

	void SetPos(float x, float y);
};

