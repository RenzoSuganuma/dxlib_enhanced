#if 1


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sglライブラリ展開---
#include "../../sgl/sgl_level.h"
#include "../../sgl/sgl_fpsCamera.h"
// ゲーム変数宣言---
auto level = Level::CreateShared();
std::shared_ptr<FPSCamera> camera;

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	camera = std::make_shared<FPSCamera>(DXE_WINDOW_WIDTH_F, DXE_WINDOW_HEIGHT_F);

	level->MainLoopInitialize();
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	camera.get()->Update(delta_time);
	dxe::DrawGridGround(camera, 50, 20, -1);
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	level->MainLoopUpdate(delta_time);
	level->MainLoopDraw();
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	level->MainLoopFinalize();
	level->MainLoopRelease();
}


#endif
