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
	// 【参考文献】http://marupeke296.com/COL_3D_No13_OBBvsOBB.html
	const bool CheckOBBOverlap(OBBCollider* obb1, OBBCollider* obb2) {
		return false;
	}
}
