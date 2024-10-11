#pragma once
#include "list"
#include "string"
#include "sgl_component.h"
class gameObject {
protected:
	std::list< std::shared_ptr< component > > components_;
public:
	std::string name_ = "";
	static std::shared_ptr<gameObject> create(std::string name) {
		auto instance = std::make_shared<gameObject>();
		instance.get()->name_ = name;
		return instance;
	}
	void addComponent(std::shared_ptr< component > component) {
		components_.emplace_back(component);
	}
	void removeComponent(std::shared_ptr< component > component) {
		auto itr = components_.begin();
		while (itr != components_.end()) {
			if ((*itr).get() == component.get()) {
				components_.erase(itr);
			}
		}
	}
	void init() {
		for (auto item : components_) {
			item.get()->init();
		}
	}
	void update() {
		for (auto item : components_) {
			item.get()->update();
		}
	}
	void draw() {
		for (auto item : components_) {
			item.get()->draw();
		}
	}
	void clean() {
		for (auto item : components_) {
			item.get()->clean();
		}
	}
};

