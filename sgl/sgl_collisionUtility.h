#pragma once
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
		sgl::Vector3 direction_{ 0,0,1 };
		// 中心点から面までの距離
		sgl::Vector3 extents_;
	public:
		AutoProperty( sgl::Vector3 , Center , center_ )
		AutoProperty( sgl::Vector3 , Direction , direction_ )
		AutoProperty( sgl::Vector3 , Extents , extents_ )

		static OBBCollider* Create() {
			return new OBBCollider;
		}

		static OBBCollider* Create(sgl::Vector3 center, sgl::Vector3 direction, sgl::Vector3 extents) {
			auto instance = new OBBCollider;
			instance->setCenter(center);
			instance->setDirection(direction);
			instance->setExtents(extents);
			return instance;
		}
	};

	// ２円または球の当たり判定
	const bool CircleIntersection(sgl::Vector3 pos1, sgl::Vector3 pos2, float r1, float r2) {
		float center_distance = (pos1 - pos2).magnitude();
		return center_distance <= (r1 + r2);
	}
	// 【開発中】OBBどうしの当たり判定
	const bool OBBIntersection(sgl::Vector3 pos1, sgl::Vector3 pos2,
		const OBBCollider* obb1, const OBBCollider* obb2) {
		return false;
	}
}
