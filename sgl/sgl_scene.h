#pragma once
#include "list"
#include "memory"
#include "sgl_gameObject.h"
class scene final {
	std::list< std::shared_ptr< gameObject > > objects_;
public:
	void init() {}
	void update() {}
	void draw() {}
	void clean() {}
};

