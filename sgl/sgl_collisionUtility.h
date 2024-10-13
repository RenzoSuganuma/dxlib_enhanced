#pragma once
#include "sgl_vector3.h"
namespace sgl::intersection {
	// ２円または球の当たり判定
	const bool CircleIntersection2D(sgl::Vector3 c1, sgl::Vector3 c2, float r1, float r2) {
		float center_distance = (c1 - c2).magnitude();
		return center_distance <= (r1 + r2);
	}
}
