#if 1


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// エンジンヘッダ展開---
#include "../../sgl/sgl_scene.h"
#include "../../sgl/sgl_component.h"
#include "../../sgl/sgl_gameObject.h"

Scene scene;
auto comp = Component::create();
auto go = GameObject::create("test_object");
//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	// シーン初期化前処理---
	go.get()->addComponent(comp);
	go.get()->removeComponent(comp);
	scene.addSceneObject(go);
	//scene.removeSceneObject(go);
	// シーン初期化
	scene.init();
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	scene.update();
}


//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	scene.dispose();
}


#endif
