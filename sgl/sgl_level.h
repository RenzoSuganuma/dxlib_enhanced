#pragma once

#include "list"

// 前方定義
class Actor;

// Unityでいうシーン、すべてのアクタが存在するクラス。（構造体でもいいかも）
class Level final {
private:
	std::list< Actor* > objects_;

public:
	Level();
	~Level();

	static Level* Create() {
		return new Level;
	}

	void const MainLoopEntry();
	void const MainLoopUpdate(float deltaTime);
	void const MainLoopExit();
	const std::list< Actor* >::iterator
		const AddActor(const Actor * newObject);
	void const RemoveObject(const Actor * obj);
	void const RemoveObject(const std::list< Actor* >::iterator place);
};
