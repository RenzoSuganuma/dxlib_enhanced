#pragma once
#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_lang_extention.h"
class BlankTestModule : public Actor
{
public:
	DEF_Create_shared_ptr(BlankTestModule)
protected:
	// ���W���[���̏�����
	void Initialize() override;
	// ���W���[���̍X�V
	void Update(float delta_time) override;
	// ���W���[���̕`��
	void Draw() override;
	// ���W���[���̓��ł̉��
	void Release() override;
	// ���W���[���̔j��
	void Finalize() override;
};

// ���W���[���̏�����
void BlankTestModule::Initialize() {}
// ���W���[���̍X�V
void BlankTestModule::Update(float delta_time) {
	DrawString(10, 10, "test__", -1);
}
// ���W���[���̕`��
void BlankTestModule::Draw() {}
// ���W���[���̓��ł̉��
void BlankTestModule::Release() {}
// ���W���[���̔j��
void BlankTestModule::Finalize() {}
