﻿#pragma once
#include "memory"
#include "sgl_lang_extention.h"
// 前方定義
class Actor;
// アクターへ機能を追加する際にこれに機能の実装をしてアクタへアタッチする
// コンポーネントクラスの基底クラス
class Component {
protected:
	const Actor* attachedActor_ = nullptr;

	virtual void Begin_();
	virtual void Tick_(float deltaTime);
	virtual void End_();
	virtual void Draw_();
public:
	bool enabled_ = true;

	Component();
	~Component();

	static Component* Create() {
		return new Component;
	}
	
	DEF_Create_shared_ptr(Component)

	void Begin();
	void Tick(float deltaTime);
	void End();
	void Draw();
	const Actor* const GetActor() const;
	void const SetActor(const Actor* actor);
};
