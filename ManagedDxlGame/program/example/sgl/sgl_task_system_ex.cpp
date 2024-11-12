#if 0


#include <time.h>
#include <string>
#include "../dxe/dxe.h"
#include "gm_main.h"
// sgl���C�u�����W�J---
#include "../../sgl/sgl_level.h"
#include "../../sgl/sgl_actor.h"
#include "../../sgl/sgl_component.h"
// �Q�[���ϐ��錾---
auto level = Level::CreateShared();
auto actor = Actor::CreateShared();
auto component = Component::CreateShared();

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));
	// �Q�[���ϐ��Z�b�g�A�b�v---
	level->AddActor(actor.get());
	level->MainLoopEntry();
}


//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {
	dxe::DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10 });
	level->MainLoopUpdate(delta_time);
}


//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
	level->MainLoopExit();
}


#endif
