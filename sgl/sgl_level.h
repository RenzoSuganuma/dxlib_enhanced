#pragma once
#include "list"
#include "memory"
#include "sgl_lang_extention.h"
// 前方定義
class Actor;
// Unityでいうシーン、すべてのアクタが存在するクラス。（構造体でもいいかも）
struct Level final {
private:
	std::list< Actor* > objects_;

public:
	Level();
	~Level();

	static Level* Create() {
		return new Level;
	}

	DEF_Create_shared_ptr(Level)

	void const MainLoopEntry();
	void const MainLoopUpdate(float deltaTime);
	void const MainLoopExit();
	const std::list< Actor* >::iterator
		const AddActor(const Actor * obj);
	void const RemoveActor(const Actor * obj);
	void const RemoveActor(const std::list< Actor* >::iterator place);
};
