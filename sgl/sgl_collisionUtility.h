#pragma once
#include "vector"
#include "math.h"
#include "limits.h"
#include "DirectXMath.h"
#include "sgl_vector3.h"
#include "sgl_component.h"
#include "sgl_lang_extention.h"
namespace sgl::intersection {
	// OBBのコライダーのクラス
	class OBBCollider : public Component {
	protected:
		// 中心点の座標
		sgl::Vector3 center_;
		// 方向ベクトル。各軸の傾きZ軸正の向きが正面
		std::vector<sgl::Vector3> direction_;
		// 中心点から面までの距離
		sgl::Vector3 extents_;
	public:
		AutoProperty(sgl::Vector3, Center, center_)
			AutoProperty(sgl::Vector3, Extents, extents_)
			AutoProperty(std::vector<sgl::Vector3>, Direction, direction_)
	public:
		// 範囲のサイズを返す
		sgl::Vector3 getSize() {
			return extents_ * 2;
		}
		// extentsを配列として返す。
		const float* getExtentsAsArray() {
			float e[3]{ extents_.x , extents_.y , extents_.z };
			return e;
		}

		static OBBCollider* Create() {
			return new OBBCollider;
		}

		static OBBCollider* Create(sgl::Vector3 center, const std::vector<sgl::Vector3>& direction, sgl::Vector3 extents) {
			auto instance = new OBBCollider;
			instance->setCenter(center);
			instance->setDirection(direction);
			instance->setExtents(extents);
			return instance;
		}
	};
	// ２円または球の当たり判定
	const bool CheckSphereOverlap(sgl::Vector3 pos1, sgl::Vector3 pos2, float r1, float r2) {
		float center_distance = (pos1 - pos2).magnitude();
		return center_distance <= (r1 + r2);
	}
	// 【開発中】OBBどうしの当たり判定
	// 【参考文献】http://distancevector.web.fc2.com/collision.html#OBBOBB
	const bool CheckOBBOverlap(OBBCollider* obb1, OBBCollider* obb2) {
		float R[3][3], AbsR[3][3];
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				R[i][j] = DirectX::XMVector3Dot(
					sgl::Vector3::ToDXVector(obb1->getDirection()[i]),
					sgl::Vector3::ToDXVector(obb2->getDirection()[j])
				).m128_f32[0];
				AbsR[i][j] = fabsf(R[i][j]) + std::numeric_limits<float>::epsilon();
			}
		}
		auto c1 = obb1->getCenter();
		auto c2 = obb2->getCenter();
		auto d = c2 - c1;
		DirectX::XMVECTOR t = sgl::Vector3::ToDXVector(c2 - c1);
		float dX, dY, dZ;
		dX = DirectX::XMVector3Dot(t, sgl::Vector3::ToDXVector(obb1->getDirection()[0])).m128_f32[0];
		dY = DirectX::XMVector3Dot(t, sgl::Vector3::ToDXVector(obb1->getDirection()[1])).m128_f32[0];
		dZ = DirectX::XMVector3Dot(t, sgl::Vector3::ToDXVector(obb1->getDirection()[2])).m128_f32[0];
		t = DirectX::XMVectorSet(dX, dY, dZ, 1.0f);

		float ra, rb;
		// 軸L=A0, L=A1, L=A2判定
		for (size_t i = 0; i < 3; i++) {
			ra = obb1->getExtentsAsArray()[i];
			rb = obb2->getExtentsAsArray()[0] * AbsR[i][0]
				+ obb2->getExtentsAsArray()[1] * AbsR[i][1]
				+ obb2->getExtentsAsArray()[2] * AbsR[i][2];
			if (fabsf(t.m128_f32[i]) > ra + rb)
				return false;
		}

		// 軸L=B0, L=B1, L=B2判定
		for (int i = 0; i < 3; i++)
		{
			ra = obb1->getExtentsAsArray()[0] * AbsR[0][i]
				+ obb1->getExtentsAsArray()[1] * AbsR[1][i]
				+ obb1->getExtentsAsArray()[2] * AbsR[2][i];
			rb = obb2->getExtentsAsArray()[i];
			if (fabsf(t.m128_f32[0] * R[0][i] + t.m128_f32[1] * R[1][i] + t.m128_f32[2] * R[2][i]) > ra + rb)
				return false;
		}

		//軸L=A0 X B0判定
		ra = obb1->getExtentsAsArray()[1] * AbsR[2][0] + obb1->getExtentsAsArray()[2] * AbsR[1][0];
		rb = obb2->getExtentsAsArray()[1] * AbsR[0][2] + obb2->getExtentsAsArray()[2] * AbsR[0][1];
		if (fabsf(t.m128_f32[2] * R[1][0] - t.m128_f32[1] * R[2][0]) > ra + rb)
			return false;

		//軸L=A0 X B1判定
		ra = obb1->getExtentsAsArray()[1] * AbsR[2][1] + obb1->getExtentsAsArray()[2] * AbsR[1][1];
		rb = obb2->getExtentsAsArray()[0] * AbsR[0][2] + obb2->getExtentsAsArray()[2] * AbsR[0][0];
		if (fabsf(t.m128_f32[2] * R[1][1] - t.m128_f32[1] * R[2][1]) > ra + rb)
			return false;

		//軸L=A0 X B2判定
		ra = obb1->getExtentsAsArray()[1] * AbsR[2][2] + obb1->getExtentsAsArray()[2] * AbsR[1][2];
		rb = obb2->getExtentsAsArray()[0] * AbsR[0][1] + obb2->getExtentsAsArray()[1] * AbsR[0][0];
		if (fabsf(t.m128_f32[2] * R[1][2] - t.m128_f32[1] * R[2][2]) > ra + rb)
			return false;

		//軸L=A1 X B0判定
		ra = obb1->getExtentsAsArray()[0] * AbsR[2][0] + obb1->getExtentsAsArray()[2] * AbsR[0][0];
		rb = obb2->getExtentsAsArray()[1] * AbsR[1][2] + obb2->getExtentsAsArray()[2] * AbsR[1][1];
		if (fabsf(t.m128_f32[0] * R[2][0] - t.m128_f32[2] * R[0][0]) > ra + rb)
			return false;

		//軸L=A1 X B1判定
		ra = obb1->getExtentsAsArray()[0] * AbsR[2][1] + obb1->getExtentsAsArray()[2] * AbsR[0][1];
		rb = obb2->getExtentsAsArray()[0] * AbsR[1][2] + obb2->getExtentsAsArray()[2] * AbsR[1][0];
		if (fabsf(t.m128_f32[0] * R[2][1] - t.m128_f32[2] * R[0][1]) > ra + rb)
			return false;

		//軸L=A1 X B2判定
		ra = obb1->getExtentsAsArray()[0] * AbsR[2][2] + obb1->getExtentsAsArray()[2] * AbsR[0][2];
		rb = obb2->getExtentsAsArray()[0] * AbsR[1][1] + obb2->getExtentsAsArray()[1] * AbsR[1][0];
		if (fabsf(t.m128_f32[0] * R[2][2] - t.m128_f32[2] * R[0][2]) > ra + rb)
			return false;

		//軸L=A2 X B0判定
		ra = obb1->getExtentsAsArray()[0] * AbsR[1][0] + obb1->getExtentsAsArray()[1] * AbsR[0][0];
		rb = obb2->getExtentsAsArray()[1] * AbsR[2][2] + obb2->getExtentsAsArray()[2] * AbsR[2][1];
		if (fabsf(t.m128_f32[1] * R[0][0] - t.m128_f32[0] * R[1][0]) > ra + rb)
			return false;

		//軸L=A2 X B1判定
		ra = obb1->getExtentsAsArray()[0] * AbsR[1][1] + obb1->getExtentsAsArray()[1] * AbsR[0][1];
		rb = obb2->getExtentsAsArray()[0] * AbsR[2][2] + obb2->getExtentsAsArray()[2] * AbsR[2][0];
		if (fabsf(t.m128_f32[1] * R[0][1] - t.m128_f32[0] * R[1][1]) > ra + rb)
			return false;

		//軸L=A2 X B2判定
		ra = obb1->getExtentsAsArray()[0] * AbsR[1][2] + obb1->getExtentsAsArray()[1] * AbsR[0][2];
		rb = obb2->getExtentsAsArray()[0] * AbsR[2][1] + obb2->getExtentsAsArray()[1] * AbsR[2][0];
		if (fabsf(t.m128_f32[1] * R[0][2] - t.m128_f32[0] * R[1][2]) > ra + rb)
			return false;

		return true;
	}
}
