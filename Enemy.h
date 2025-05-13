#pragma once
#include "GameObject.h"


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
	bool isAlive_; //�G�̐���
	int ID_; //�G��ID
	ETYPE type_; //�G�̎��
public:
	Enemy(int id, ETYPE type);
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	void SetPos(float x, float y) { x_ = x; y_ = y; } //�G�̍��W��ݒ�
	//void SetID(int id) { ID_ = id; } //�G��ID��ݒ�
};

