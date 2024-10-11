#pragma once
#include "sgl_goFramework.h"
#include "sgl_vector3.h"
#include "lang_util.h"

namespace sgl {
	class gameObject : public goFramework {
		sgl_Property(sgl::vector3, position, , )
	};
}
