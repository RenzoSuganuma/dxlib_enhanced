#pragma once
#include "functional"
#include "../dxe/dxe.h"
#include "tnl_vector3.h"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"

// FPS�J����
class FPSCamera : public dxe::Camera {
public:
	DEF_Create_shared_ptr(FPSCamera)
public:
	FPSCamera() {};
	FPSCamera(float screen_w, float screen_h) : dxe::Camera(screen_w, screen_h) {}

	// ���W���[���̏�����
	void Initialize() override {

	}
	// ���W���[���̍X�V
	void Update(float delta_time) override {
		// �p�����X�V
		tnl::Input::RunIndexKeyDown(
			[&](uint32_t ind) {
				tnl::Vector3 v[4] = {
					left(),
					right(),
					forward().xz(),
					back().xz()
				};
				addPosition(v[ind] * 3.0f);
			}, eKeys::KB_A, eKeys::KB_D, eKeys::KB_W, eKeys::KB_S);
		auto vlook = tnl::Input::GetMouseVelocity();
		m_rotation *= tnl::Quaternion::RotationAxis({ 0,1,0 }, tnl::ToRadian(vlook.x * 0.1f));
		m_rotation *= tnl::Quaternion::RotationAxis(right(), tnl::ToRadian(vlook.y * 0.1f));
		// �p���p�����[�^����^�[�Q�b�g���W�ƃA�b�p�[�x�N�g�����v�Z
		target_ = m_position + tnl::Vector3::TransformCoord({ 0, 0, 1 }, m_rotation);
		up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, m_rotation);
		dxe::Camera::update();
	}
	// ���W���[���̕`��
	void Draw() override {}
	// ���W���[���̓��ł̉��
	void Release() override {}
	// ���W���[���̔j��
	void Finalize() override {}


	inline tnl::Vector3 up() {
		up_ = tnl::Vector3::TransformCoord({ 0, 1, 0 }, m_rotation);
		return up_;
	}
	inline tnl::Vector3 down() { return -up(); }

	inline tnl::Vector3 forward() override {
		target_ = m_position + tnl::Vector3::TransformCoord({ 0, 0, 1 }, m_rotation);
		return tnl::Vector3::Normalize(target_ - m_position);
	}
	inline tnl::Vector3 back() override { return -forward(); }
	inline tnl::Vector3 left() override { return tnl::Vector3::Cross(forward(), up()); }
	inline tnl::Vector3 right() override { return tnl::Vector3::Cross(up(), forward()); }

};


