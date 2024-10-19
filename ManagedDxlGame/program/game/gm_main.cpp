#if 1


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sglライブラリ展開---
#include "../../sgl/sgl_level.h"
#include "../../sgl/sgl_actor.h"
#include "../../sgl/sgl_component.h"
#include "../../sgl/sgl_collisionUtility.h"
// ゲーム変数宣言---
auto level = Level::Create();
auto actor = Actor::Create();
auto component = Component::Create();
DirectX::BoundingOrientedBox obbA =
DirectX::BoundingOrientedBox(DirectX::XMFLOAT3::XMFLOAT3(0, 0, 0), DirectX::XMFLOAT3::XMFLOAT3(1, 1, 1), DirectX::XMFLOAT4::XMFLOAT4(0, 0, 0, 1));
DirectX::BoundingOrientedBox obbB =
DirectX::BoundingOrientedBox(DirectX::XMFLOAT3::XMFLOAT3(0, 0, 0), DirectX::XMFLOAT3::XMFLOAT3(1, 1, 1), DirectX::XMFLOAT4::XMFLOAT4(0, 0, 0, 1));
//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	// ゲーム変数セットアップ---
	actor->AddComponent(component);
	level->AddActor(actor);
	level->MainLoopEntry();
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	level->MainLoopUpdate(delta_time);
	if (sgl::intersection::CheckOBBOverlapDX(obbA, obbB)) {
		DrawString(10, 10, "yes", -1);
	}
	else {
		DrawString(10, 10, "no", -1);
	}
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	level->MainLoopExit();
	delete level;
}


#endif
