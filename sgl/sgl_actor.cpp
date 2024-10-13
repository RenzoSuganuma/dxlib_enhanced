#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_component.h"
#include "sgl_level.h"

Actor::Actor() {}
Actor::~Actor() {}

#pragma region virtual-funcitons
void Actor::Begin_() {}
void Actor::Tick_(float deltaTime) {}
void Actor::End_() {}
void Actor::Draw_() {}
#pragma endregion

void Actor::Begin()
{
	auto it = attachedComponents_.begin();
	while (it != attachedComponents_.end())
	{
		(*it)->Begin();
		it++;
	}

	enabled_ = true;

	Begin_();
}

void Actor::Tick(float deltaTime)
{
	auto it = attachedComponents_.begin();
	while (it != attachedComponents_.end())
	{
		(*it)->Tick(deltaTime);
		it++;
	}

	Tick_(deltaTime);
}

void Actor::End()
{
	auto it = attachedComponents_.begin();
	while (it != attachedComponents_.end())
	{
		(*it)->End();
		it++;
	}

	attachedComponents_.clear();
	enabled_ = false;
	placedLevel_ = nullptr;

	End_();
}

void Actor::Draw()
{
	auto it = attachedComponents_.begin();
	while (it != attachedComponents_.end())
	{
		(*it)->Draw();
		it++;
	}

	Draw_();
}

std::list< Component* >::iterator
const Actor::AddComponent(Component* component)
{
	component->SetActor(this);
	attachedComponents_.emplace_back(component);
	auto it = attachedComponents_.end();
	it--;

	return it;
}

void const Actor::RemoveComponent(const std::list<Component*>::iterator place)
{
	attachedComponents_.erase(place);
}

void const Actor::SetPosition(sgl::Vector3 newPos)
{
	position_ = newPos;
}

const sgl::Vector3 const Actor::GetPosition()
{
	return position_;
}

void const Actor::SetRotation(sgl::Vector3 newRot)
{
	rotation_ = newRot;
}

const sgl::Vector3 const Actor::GetRotation()
{
	return rotation_;
}

void const Actor::SetPlacedLevel(const Level* level)
{
	placedLevel_ = const_cast<Level*>(level);
}

