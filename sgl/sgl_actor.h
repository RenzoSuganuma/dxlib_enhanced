﻿#pragma once
#include "list"
#include "memory"
#include "string"
#include "DxLib.h"
#include "sgl_vector3.h"
#include "sgl_lang_extention.h"
class Level;
class Component;
// ゲーム内のオブジェクトとして扱うクラスの基底クラスインスタンスはスマートポインタで
class Actor {
protected:
	std::list< Component* > components_;
	sgl::Vector3 position_{ 0 };
	sgl::Vector3 rotation_{ 0 };
	Level* placedLevel_ = nullptr;
	std::string name_ = "";
	bool enabled_ = true;
	/* virtual functions FOR override */
	// モジュールの初期化
	virtual void Initialize();
	// モジュールの更新
	virtual void Update(float delta_time);
	// モジュールの描画
	virtual void Draw();
	// モジュールの内での解放
	virtual void Release();
	// モジュールの破棄
	virtual void Finalize();
	/* auto properties */
public:
	AutoProperty(sgl::Vector3, Position, position_)
		AutoProperty(sgl::Vector3, Rotation, rotation_)
		Getter(std::string, Name, name_)
		DEF_Create_shared_ptr(Actor)
public:

	Actor();
	~Actor();

	// モジュールの初期化
	void __initialize();
	// モジュールの更新
	void __update(float delta_time);
	// モジュールの描画
	void __draw();
	// モジュール内での解放
	void __release();
	// モジュールの破棄
	void __finalize();

	/* statics */
	//
	static Actor* Create() {
		return new Actor;
	}

	std::list< Component* >::iterator
	const AddComponent(Component* component);
	void const RemoveComponent(const std::list<Component*>::iterator place);
	void const SetPlacedLevel(const Level* level);
	/* templates */
	//
	template<typename T>
	static T GetComponent(const Actor* getComponentFrom)
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
