#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_level.h"

Level::Level() {}
Level::~Level() {}

void const Level::MainLoopInitialize()
{
	auto itr = objects_.begin();
	while (itr != objects_.end())
	{
		(*itr)->__initialize();
		itr++;
	}
}

void const Level::MainLoopUpdate(float deltaTime)
{
	auto itr = objects_.begin();
	while (itr != objects_.end())
	{
		(*itr)->__update(deltaTime);
		(*itr)->__draw();
		itr++;
	}
}

void const Level::MainLoopDraw()
{
	auto itr = objects_.begin();
	while (itr != objects_.end())
	{
		(*itr)->__draw();
		itr++;
	}
}

void const Level::MainLoopFinalize()
{
	auto it = objects_.begin();
	while (it != objects_.end())
	{
		(*it)->__finalize();
		++it;
	}
}

void const Level::MainLoopRelease()
{
	auto it = objects_.begin();
	while (it != objects_.end())
	{
		(*it)->__release();
		++it;
	}
	objects_.clear();
}

const std::list< Actor* >::iterator
const Level::AddActor(const Actor * obj)
{
	const_cast<Actor*>(obj)->SetPlacedLevel(this);
	objects_.emplace_back(const_cast<Actor*>(obj));
	auto it = objects_.end();
	it--;
	return it;
}

void const Level::RemoveActor(const Actor* obj)
{
	objects_.remove(const_cast<Actor*>(obj));
}

void const Level::RemoveActor(const std::list< Actor* >::iterator place)
{
	objects_.erase(place);
}
