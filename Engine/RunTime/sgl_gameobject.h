#pragma once
#include "sgl_vector3.h"
#include "lang_util.h"

namespace sgl {
	class gameObject {
		sgl_Property(sgl::vector3, position, , )

	public:
		void init() ;
		void draw() ;
		void update()  {
			DrawString(100, 100, "update", -1);
		}
		void cleanup() ;
	};
}
