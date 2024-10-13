#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_level.h"
#include "sgl_actorUtilities.h"

Level::Level() {}
Level::~Level() {}

void const Level::MainLoopEntry()
{
	auto itr = objects_.begin();

	while (itr != objects_.end())
	{
		(*itr)->Begin();
		itr++;
	}
}

void const Level::MainLoopUpdate(float deltaTime)
{
	auto itr = objects_.begin();

	while (itr != objects_.end())
	{
		(*itr)->Tick(deltaTime);
		(*itr)->Draw();
		itr++;
	}
}

void const Level::MainLoopExit()
{
	auto it = objects_.begin();

	while (it != objects_.end())
	{
		delete (*it);
		++it;
	}

	objects_.clear();
}

const std::list< Actor* >::iterator
const Level::AddObject(const Actor* newObject)
{
	objects_.emplace_back(const_cast<Actor*>(newObject));
	auto it = objects_.end();
	it--;
	return it;
}

void const Level::RemoveObject(const Actor* obj)
{
	objects_.remove(const_cast<Actor*>(obj));
}

void const Level::RemoveObject(const std::list< Actor* >::iterator place)
{
	objects_.erase(place);
}
