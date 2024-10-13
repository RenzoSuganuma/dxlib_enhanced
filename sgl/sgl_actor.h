#pragma once

#include "list"
#include "string"
#include "DxLib.h"
#include "sgl_vector3.h"

// 前方定義
class Level;
class Component;
class CircleCollider;

// ゲーム内のオブジェクトとして扱うクラスの基底クラス
class Actor {
protected:
	sgl::Vector3 position_{ 0 };
	sgl::Vector3 rotation_{ 0 };
	Level* placedLevel_;

	virtual void Begin_();
	virtual void Tick_(float deltaTime);
	virtual void End_();
	virtual void Draw_();
public:
	std::list< Component* > attachedComponents_;
	std::string name_ = "";
	bool enabled_ = true;

	Actor();
	~Actor();
	void Begin();
	void Tick(float deltaTime);
	void End();
	void Draw();

	static Actor* Create() {
		return new Actor;
	}

	std::list< Component* >::iterator
		const AddComponent(Component* component);
	void const RemoveComponent(const std::list<Component*>::iterator place);
	void const SetPosition(sgl::Vector3 newPos);
	const sgl::Vector3 const GetPosition();
	void const SetRotation(sgl::Vector3 newRot);
	const sgl::Vector3 const GetRotation();
	void const SetPlacedLevel(const Level* level);
};
