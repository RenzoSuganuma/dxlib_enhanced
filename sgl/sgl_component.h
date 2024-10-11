#pragma once
#include "memory"
#include "sgl_gameObject.h"
class component {
	gameObject* gameObject_;
public:
	static std::shared_ptr<component> create() {
		auto instance = std::make_shared<component>();
		return instance;
	}
	void setup(const gameObject* obj) {
		gameObject_ = const_cast<gameObject*>(obj);
	}
	void init() {}
	void update() {}
	void draw() {}
	void clean() {}
};

