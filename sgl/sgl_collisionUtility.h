#pragma once
#include "vector"
#include "math.h"
#include "limits.h"
#include "DirectXMath.h"
#include "sgl_vector3.h"
#include "sgl_component.h"
#include "DirectXCollision.h" // DirectX::BoundingSphere , DirectX::BoundingOrientedBox
#include "sgl_lang_extention.h"
namespace sgl::intersection {
	// ２円または球の当たり判定
	const bool CheckSphereOverlap(sgl::Vector3& pos1, sgl::Vector3& pos2, float r1, float r2) {
		float center_distance = (pos1 - pos2).magnitude();
		return center_distance <= (r1 + r2);
	}
	// ２円または球の当たり判定
	const bool CheckSphereOverlapDX(const DirectX::BoundingSphere& a, const DirectX::BoundingSphere& b) {
		return a.Intersects(b);
	}
	// OBBどうしの当たり判定
	const bool CheckOBBOverlapDX(const DirectX::BoundingOrientedBox& a, const DirectX::BoundingOrientedBox& b) {
		return a.Intersects(b);
	}
}
