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
	void initialize() override;
	// ���W���[���̍X�V
	void update(float delta_time) override;
	// ���W���[���̕`��
	void draw() override;
	// ���W���[���̓��ł̉��
	void release() override;
	// ���W���[���̔j��
	void finalize() override;
};

// ���W���[���̏�����
void BlankTestModule::initialize() {}
// ���W���[���̍X�V
void BlankTestModule::update(float delta_time) {
	DrawString(10, 10, "test__", -1);
}
// ���W���[���̕`��
void BlankTestModule::draw() {}
// ���W���[���̓��ł̉��
void BlankTestModule::release() {}
// ���W���[���̔j��
void BlankTestModule::finalize() {}
