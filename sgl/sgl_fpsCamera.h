#pragma once
#include "../dxe/dxe.h"
#include "sgl_component.h"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"

// FPS�J����
class FPSCamera : public dxe::Camera, IManagableModule {
public:
	DEF_Create_shared_ptr(FPSCamera)
public:

	tnl::Quaternion rot_;

	FPSCamera() {};
	FPSCamera(float screen_w, float screen_h) : dxe::Camera(screen_w, screen_h) {}

	// ���W���[���̏�����
	void Initialize() override {}
	// ���W���[���̍X�V
	void Update(float delta_time) override {
		// �p���p�����[�^����^�[�Q�b�g���W�ƃA�b�p�[�x�N�g�����v�Z
		target_ = position_ + tnl::Vector3::TransformCoord({ 0, 0, 1 }, rot_);
		up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, rot_);
		dxe::Camera::update();
	}
	// ���W���[���̕`��
	void Draw() override {}
	// ���W���[���̓��ł̉��
	void Release() override {}
	// ���W���[���̔j��
	void Finalize() override {}


	inline tnl::Vector3 up() {
		up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, rot_);
		return up_;
	}
	inline tnl::Vector3 down() { return -up(); }

	inline tnl::Vector3 forward() override {
		target_ = position_ + tnl::Vector3::TransformCoord({ 0, 0, 1 }, rot_);
		return tnl::Vector3::Normalize(target_ - position_);
	}
	inline tnl::Vector3 back() override { return -forward(); }
	inline tnl::Vector3 left() override { return tnl::Vector3::Cross(forward(), up()); }
	inline tnl::Vector3 right() override { return tnl::Vector3::Cross(up(), forward()); }

};


