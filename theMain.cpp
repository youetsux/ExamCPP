#include "DxLib.h"
#include "globals.h"
#include "input.h"
#include <vector>
#include "Stage.h"


namespace
{
	const int BGCOLOR[3] = {0, 0, 0}; // �w�i�F{ 255, 250, 205 }; // �w�i�F
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
std::vector<GameObject*> newObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[


float gDeltaTime = 0.0f; // �t���[���Ԃ̎��ԍ�

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "�E�B���h�E�̃e�X�g");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();
	
	Stage* stage = new Stage(); // �X�e�[�W�I�u�W�F�N�g�̐���


	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate(); // �L�[���͂̏�Ԃ��X�V

		crrTime = GetNowCount(); // ���݂̎��Ԃ��擾
		// �O��̎��ԂƂ̍������v�Z
		float deltaTime = (crrTime - prevTime) / 1000.0f; // �b�P�ʂɕϊ�
		gDeltaTime = deltaTime; // �O���[�o���ϐ��ɕۑ�

		//�����ɂ�肽������������(��������j
		//�Q�[���I�u�W�F�N�g�̒ǉ�
		if (newObjects.size() > 0) {
			for (auto& obj : newObjects) {
				gameObjects.push_back(obj); // �V�����Q�[���I�u�W�F�N�g��ǉ�	
			}
			newObjects.clear(); // �V�����Q�[���I�u�W�F�N�g�̃x�N�^�[���N���A
		}
		//gameObjects�̍X�V
		for (auto& obj : gameObjects) {
			obj->Update(); // �Q�[���I�u�W�F�N�g�̍X�V
		}
		//gameObjects�̕`��
		for (auto& obj : gameObjects) {
			obj->Draw(); // �Q�[���I�u�W�F�N�g�̕`��
		}
		
		for (auto it = gameObjects.begin(); it != gameObjects.end();) {
			if (!(*it)->IsAlive()) {
				delete* it; // �Q�[���I�u�W�F�N�g���폜
				it = gameObjects.erase(it); // �x�N�^�[����폜
			}
			else {
				++it; // ���̗v�f��
			}
		}
		//�����ɂ�肽�������������i�����܂Łj


		//����ʂ̕`��
		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime; // ���݂̎��Ԃ�O��̎��ԂƂ��ĕۑ�

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}