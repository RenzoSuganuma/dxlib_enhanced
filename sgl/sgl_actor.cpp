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
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Begin();
		it++;
	}
	enabled_ = true;
	Begin_();
}

void Actor::Tick(float deltaTime)
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->Tick(deltaTime);
		it++;
	}
	Tick_(deltaTime);
}

void Actor::End()
{
	auto it = components_.begin();
	while (it != components_.end())
	{
		(*it)->End();
		it++;
	}
	components_.clear();
	enabled_ = false;
	placedLevel_ = nullptr;
	End_();
}

void Actor::Draw()
{
	auto it = components_.begin();
	while (it != components_.end())
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
	components_.emplace_back(component);
	auto it = components_.end();
	it--;
	return it;
}

void const Actor::RemoveComponent(const std::list<Component*>::iterator place)
{
	components_.erase(place);
}

void const Actor::SetPlacedLevel(const Level* level)
{
	placedLevel_ = const_cast<Level*>(level);
}

