#pragma once
#include "DxLib.h"
#include "sgl_actor.h"
#include "sgl_lang_extention.h"
class BlankTestModule : public Actor
{
public:
	DEF_Create_shared_ptr(BlankTestModule)
protected:
	// モジュールの初期化
	void Initialize() override;
	// モジュールの更新
	void Update(float delta_time) override;
	// モジュールの描画
	void Draw() override;
	// モジュールの内での解放
	void Release() override;
	// モジュールの破棄
	void Finalize() override;
};

// モジュールの初期化
void BlankTestModule::Initialize() {}
// モジュールの更新
void BlankTestModule::Update(float delta_time) {
	DrawString(10, 10, "test__", -1);
}
// モジュールの描画
void BlankTestModule::Draw() {}
// モジュールの内での解放
void BlankTestModule::Release() {}
// モジュールの破棄
void BlankTestModule::Finalize() {}
