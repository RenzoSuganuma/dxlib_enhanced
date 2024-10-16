#pragma once

#include "sgl_actor.h"
#include "sgl_component.h"

// アクタークラスのユーティリティクラス。煩雑な操作を吸収した機能を提供する。
class ActorUtilities final {
public:
	template<typename T>
	static T GetComponent(const Actor * getComponentFrom)
	{
		auto it = getComponentFrom->components_.begin();

		while (it != getComponentFrom->components_.end())
		{
			auto r = static_cast<T>(*it);
			if (r != nullptr)
			{
				return r;
				break;
			}
			it++;
		}
		return nullptr;
	}
};

