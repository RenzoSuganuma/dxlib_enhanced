#if 1

//---------------------------------------------------------------------------------------------------------------
//
//
// [ 入門 ] hello world
// 
// ※ 画面に hello world の文字が出力されるだけのサンプルです
//
//---------------------------------------------------------------------------------------------------------------


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"

#include "../../Engine/RunTime/sgl_scene.h"
#include "../../Engine/RunTime/sgl_gameobject.h"

auto scene = std::make_shared<sgl::scene>();
auto obj = std::make_shared<sgl::gameObject>();

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));

	scene.get()->addObject(obj);
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });

	scene.get()->update();
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
}


#endif
