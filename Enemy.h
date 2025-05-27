#pragma once
#include "GameObject.h"
#include "globals.h"

enum ETYPE 
{
	ZAKO, MID, KNIGHT, BOSS, MAX_ETYPE
};


class Enemy :
    public GameObject
{
	int hImage_;  //�G�̉摜�n���h��
	float x_, y_; //�G�̍��W
	float speed_; //�G�̈ړ����x

	int ID_; //�G��ID
	ETYPE type_; //�G�̎��
public:
	Enemy(int id, ETYPE type);
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	void SetPos(float x, float y) { x_ = x; y_ = y; } //�G�̍��W��ݒ�
	Rect GetRect() const { return { x_, y_, ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT }; } // �G�̋�`���擾	
	//void SetID(int id) { ID_ = id; } //�G��ID��ݒ�
};

