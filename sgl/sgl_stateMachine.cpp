#include "sgl_StateMachine.h"
#include "sgl_smTransition.h"
// �z��œo�^������
void const StateMachine::ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours) {
	behaviours_ = behaviours;
}
// �J�ڂ�o�^����
void const StateMachine::MakeTransition(StateMachineBehaviour from, StateMachineBehaviour to, std::string name) {
	
}
// �w�肵���J�ږ��̃g�����W�V�������X�V���Ă݂�
void const StateMachine::UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false) {

}
// ���荞�݃C�x���g���X�V
void const StateMachine::UpdateEventsYield() {

}
// ���݂̃r�w�C�r�A���X�V
void const StateMachine::JumpTo(StateMachineBehaviour* behaviour) {

}
// �C�x���g��V�������荞�܂���
void const StateMachine::YieldAllBehaviourTo(StateMachineBehaviour* behaviour) {

}
// �L���I�[�g�}�g�����J�n����
void const StateMachine::Start() {

}
// �L���I�[�g�}�g�����~����
void const StateMachine::Pause() {

}