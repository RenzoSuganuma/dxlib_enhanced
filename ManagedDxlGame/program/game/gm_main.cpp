#if 1


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sglライブラリ展開---
#include "../../sgl/sgl_level.h"
// ゲーム変数宣言---
auto level = Level::CreateShared();

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));

	level->MainLoopInitialize();
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
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
