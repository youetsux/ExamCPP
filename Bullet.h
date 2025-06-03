#pragma once
#include "GameObject.h"
#include "globals.h"


class Bullet :
    public GameObject
{
public:
	Bullet();
	Bullet(float x, float y);
	~Bullet();
	void Update() override;
	void Draw() override;

	void SetPos(float x, float y);
	void SetFired(bool fired) { isFired_ = fired; } // ���ˏ�Ԃ�ݒ�
	bool IsFired() const { return isFired_; } // ���ˏ�Ԃ��擾
	Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y  }; } // �e�̋�`���擾
protected:

private:
	int hImage_;  //�e�̉摜�n���h��
	float x_, y_; //�e�̍��W
	float speed_; //�e�̈ړ����x
	Point imageSize_;
	//int isize_x, isize_y; //�e�̕\���T�C�Y
	bool isFired_;  //���˂���Ă��邩�ǂ��� true: ���˂���Ă���, false: ���˂���Ă��Ȃ�
};

