#if 1


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sglライブラリ展開---
#include "../../sgl/sgl_level.h"
#include "../../sgl/sgl_actor.h"
#include "../../sgl/sgl_component.h"
#include "../../sgl/sgl_stateMachine.h"
#include "../../sgl/sgl_smTransition.h"
#include "../../sgl/sgl_DirectXUtility.h"
#include "../../sgl/sgl_collisionUtility.h"
#include "../../sgl/sgl_stateMachineBehaviour.h"
// 名前空間を省略したい
using sgl::DxUtil;
// ゲーム変数宣言---
auto level = Level::CreateShared();
auto actor = Actor::CreateShared();
auto component = Component::CreateShared();

// 有限オートマトンにつかう宣言
StateMachine stateMachine;
#pragma region Behaviours
class Input_None : public StateMachineBehaviour {
public:
	DEF_Create_shared_ptr(Input_None)

		void Begin() override {

	}
	void Tick() override {
		DrawString(10, 10, "input none", -1);
	}
	void End() override {

	}
};
class Input_W : public StateMachineBehaviour {
public:
	DEF_Create_shared_ptr(Input_W)

		void Begin() override {

	}
	void Tick() override {
		DrawString(10, 20, "input w", -1);
	}
	void End() override {

	}
};
class Input_A : public StateMachineBehaviour {
public:
	DEF_Create_shared_ptr(Input_A)

		void Begin() override {

	}
	void Tick() override {
		DrawString(10, 30, "input a", -1);
	}
	void End() override {

	}
};
class Input_S : public StateMachineBehaviour {
public:
	DEF_Create_shared_ptr(Input_S)

		void Begin() override {

	}
	void Tick() override {
		DrawString(10, 40, "input s", -1);
	}
	void End() override {

	}
};
class Input_D : public StateMachineBehaviour {
public:
	DEF_Create_shared_ptr(Input_D)

		void Begin() override {

	}
	void Tick() override {
		DrawString(10, 50, "input d", -1);
	}
	void End() override {

	}
}

; class Input_Jump : public StateMachineBehaviour {
public:
	DEF_Create_shared_ptr(Input_Jump)

		void Begin() override {

	}
	void Tick() override {
		DrawString(10, 60, "input jump", -1);
	}
	void End() override {

	}
};

#pragma endregion

auto b_none = Input_None::CreateShared();
auto b_w = Input_W::CreateShared();
auto b_a = Input_A::CreateShared();
auto b_s = Input_S::CreateShared();
auto b_d = Input_D::CreateShared();
auto b_jump = Input_Jump::CreateShared();


DxOBB obbA =
DirectX::BoundingOrientedBox(
	DxUtil::xm_Float3(0),
	DxUtil::xm_Float3(1),
	DxUtil::xm_Float4(0)
);
DxOBB obbB =
DirectX::BoundingOrientedBox(
	DxUtil::xm_Float3(3, 0, 0),
	DxUtil::xm_Float3(1),
	DxUtil::xm_Float4(0)
);

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	// ゲーム変数セットアップ---
	actor->AddComponent(component.get());
	level->AddActor(actor.get());
	level->MainLoopEntry();

	stateMachine.ResistBehaviours({ b_none.get() , b_w.get(),b_a.get(),b_s.get(),b_d.get(), b_jump.get() });

	stateMachine.MakeTransition(b_none.get(), b_w.get(), "W");
	stateMachine.MakeTransition(b_w.get(), b_none.get(), "WCanceled");
	stateMachine.MakeTransition(b_none.get(), b_a.get(), "A");
	stateMachine.MakeTransition(b_a.get(), b_none.get(), "ACanceled");
	stateMachine.MakeTransition(b_none.get(), b_s.get(), "S");
	stateMachine.MakeTransition(b_s.get(), b_none.get(), "SCanceled");
	stateMachine.MakeTransition(b_none.get(), b_d.get(), "D");
	stateMachine.MakeTransition(b_d.get(), b_none.get(), "DCanceled");
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	level->MainLoopUpdate(delta_time);
	{
		/*if (sgl::Overlaps::CheckOBBOverlapDX(obbA, obbB)) {
			DrawString(10, 10, "yes", -1);
		}
		else {
			DrawString(10, 10, "no", -1);
		}*/
	}
	bool input_w, input_a, input_s, input_d;

	input_w = tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_W);
	input_a = tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_A);
	input_s = tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_S);
	input_d = tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_D);

	stateMachine.UpdateTransition("W", input_w);
	stateMachine.UpdateTransition("WCanceled", input_w, false);
	stateMachine.UpdateTransition("A", input_a);
	stateMachine.UpdateTransition("ACanceled", input_a, false);
	stateMachine.UpdateTransition("S", input_s);
	stateMachine.UpdateTransition("SCanceled", input_s, false);
	stateMachine.UpdateTransition("D", input_d);
	stateMachine.UpdateTransition("DCanceled", input_d, false);

	if (tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_SPACE)) {
		stateMachine.JumpTo(b_jump.get());
	}
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	level->MainLoopExit();
	stateMachine.Dispose();
}


#endif
