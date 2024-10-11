#pragma once
#include "list"
#include "sgl_gameobject.h"
namespace sgl {
	class scene final {
		std::list< std::shared_ptr< sgl::gameObject > > gameObjects_;
	public:
		void addObject(std::shared_ptr< sgl::gameObject > obj) {
			gameObjects_.emplace_back(obj);	// 共有ポインタのコピーを追加。
		}

		void disposeObject(std::shared_ptr< sgl::gameObject > obj) {
			auto itr = gameObjects_.begin();
			while (itr != gameObjects_.end()) {
				if ((*itr).get() == obj.get()) {			// 共有ポインタのインスタンスの領域が同じものがあったら
					auto i = gameObjects_.erase(itr);		// ここで参照をやめる。やめればどこかのタイミングで破棄される
					itr = i;
				}

				itr++;
			}
		}

		void init();
		void draw();
		void update();
		void cleanup() {
			auto itr = gameObjects_.begin();
			while (itr != gameObjects_.end()) {
				auto i = gameObjects_.erase(itr);
				itr = i;

				itr++;
			}
		}
	};
}
