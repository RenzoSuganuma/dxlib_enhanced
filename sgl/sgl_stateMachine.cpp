#include "sgl_StateMachine.h"
#include "sgl_smTransition.h"
// 配列で登録をする
void const StateMachine::ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours) {
	behaviours_ = behaviours;
}
// 遷移を登録する
void const StateMachine::MakeTransition(StateMachineBehaviour from, StateMachineBehaviour to, std::string name) {
	
}
// 指定した遷移名のトランジションを更新してみる
void const StateMachine::UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false) {

}
// 割り込みイベントを更新
void const StateMachine::UpdateEventsYield() {

}
// 現在のビヘイビアを更新
void const StateMachine::JumpTo(StateMachineBehaviour* behaviour) {

}
// イベントを新しく割り込ませる
void const StateMachine::YieldAllBehaviourTo(StateMachineBehaviour* behaviour) {

}
// 有限オートマトンを開始する
void const StateMachine::Start() {

}
// 有限オートマトンを停止する
void const StateMachine::Pause() {

}