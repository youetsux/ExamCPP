#pragma once
#include <vector>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

extern std::vector<GameObject*> gameObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
extern std::vector<GameObject*> newObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[

inline void AddGameObject(GameObject* obj)
{
	newObjects.push_back(obj); // �Q�[���I�u�W�F�N�g���x�N�^�[�ɒǉ�
}