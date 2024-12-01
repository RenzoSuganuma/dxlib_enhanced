﻿#pragma once
#include "list"
#include "memory"
#include "sgl_fpsCamera.h"
#include "sgl_lang_extention.h"
#include "sgl_managableModules.h"
// 前方定義
class Actor;
// Unityでいうシーン、すべてのアクタが存在するクラス。（構造体でもいいかも）
struct Level final : IManagableModule {
private:
	std::list< Actor* > m_actors;
	std::shared_ptr<FPSCamera> m_camera;
public:
	Level();
	~Level();

	std::shared_ptr<FPSCamera> mainCamera() { return m_camera; }

	static Level* Create() {
		return new Level;
	}

	DEF_Create_shared_ptr(Level)
public:
	void  Initialize();
	void  Update(float deltaTime);
	void  Draw();
	void  Finalize();
	void  Release();

	void DrawActorList();
	const std::list< Actor* >::iterator
		const AddActor(const Actor* obj);
	void const RemoveActor(const Actor* obj);
	void const RemoveActor(const std::list< Actor* >::iterator place);
};
