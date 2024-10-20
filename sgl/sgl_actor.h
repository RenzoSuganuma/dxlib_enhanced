#pragma once
#include "list"
#include "string"
#include "DxLib.h"
#include "sgl_vector3.h"
#include "sgl_lang_extention.h"
class Level;
class Component;
// ゲーム内のオブジェクトとして扱うクラスの基底クラス
class Actor {
protected:
	std::list< Component* > components_;
	sgl::Vector3 position_{ 0 };
	sgl::Vector3 rotation_{ 0 };
	Level* placedLevel_ = nullptr;
	std::string name_ = "";
	bool enabled_ = true;
	/* virtual functions FOR override */
	virtual void Begin_();
	virtual void Tick_(float deltaTime);
	virtual void End_();
	virtual void Draw_();
	/* auto properties */
	AutoProperty(sgl::Vector3, Position, position_)
		AutoProperty(sgl::Vector3, Rotation, rotation_)
		Getter(std::string, Name, name_)
public:

	Actor();
	~Actor();
	void Begin();
	void Tick(float deltaTime);
	void End();
	void Draw();

	/* statics */
	static Actor* Create() {
		return new Actor;
	}
	/*  */
	std::list< Component* >::iterator
		const AddComponent(Component* component);
	void const RemoveComponent(const std::list<Component*>::iterator place);
	void const SetPosition(sgl::Vector3 newPos);
	const sgl::Vector3 const GetPosition();
	void const SetRotation(sgl::Vector3 newRot);
	const sgl::Vector3 const GetRotation();
	void const SetPlacedLevel(const Level* level);
	/* tmplates */
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
