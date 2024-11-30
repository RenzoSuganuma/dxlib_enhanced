#include "sgl_StateMachine.h"
#include "sgl_smTransition.h"

// �z��œo�^������
void const StateMachine::ResistBehaviours(std::list<StateMachineBehaviour*> behaviours) {
	behaviours_ = behaviours;
	if (currentBehaviour_ == nullptr) currentBehaviour_ = (*behaviours_.begin());
}
// �r�w�C�r�A��o�^����
void const StateMachine::ResistBehaviour(StateMachineBehaviour* behaviours) {
	behaviours_.emplace_back(behaviours);
}
// �J�ڂ�o�^����
void const StateMachine::MakeTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, std::string name) {
	if (!transitionsName_Id_.contains(name)) {
		transitionsName_Id_.insert(std::make_pair(name, transitionsName_Id_.size()));
	}

	transitions_.emplace_back(new SMTransition(from, to, transitionsName_Id_[name]));
}
// �w�肵���J�ږ��̃g�����W�V�������X�V���Ă݂�
void const StateMachine::UpdateTransition(std::string name, bool& condition, bool equalsTo, bool isTrigger) {
	if (isPausing_ || isYieldToEvent_) { return; }

	for (auto transition : transitions_) {
		if ((condition == equalsTo) && transition->id_ == transitionsName_Id_[name]) {
			if (transition->from_ == currentBehaviour_) {
				currentBehaviour_->End();
				if (isTrigger) { condition = !equalsTo; }
				currentBehaviour_ = transition->to_;
				currentBehaviour_->Begin();
			}
		}
		else {
			currentBehaviour_->Update();
		}
	}
}
// ���荞�݃C�x���g���X�V
void const StateMachine::UpdateEventsYield() {
	if (isPausing_) return;

	if (isYieldToEvent_) {
		currentYieldedBehaviour_->Update();
		if (!currentYieldedBehaviour_->yieldManually()) {
			isYieldToEvent_ = false;
		}
	}
}
// ���݂̃r�w�C�r�A���X�V
void const StateMachine::JumpTo(StateMachineBehaviour* behaviour) {
	auto it = behaviours_.begin();
	while (it != behaviours_.end()) {
		if (*it == behaviour) {
			currentBehaviour_ = behaviour;
			break;
		}
		it++;
	}
}
// �C�x���g��V�������荞�܂���
void const StateMachine::YieldAllBehaviourTo(StateMachineBehaviour* behaviour) {
	auto it = behaviours_.begin();
	while (it != behaviours_.end()) {
		if (*it == behaviour) {
			isYieldToEvent_ = true;
			currentYieldedBehaviour_ = behaviour;
			currentYieldedBehaviour_->Begin();
			break;
		}
		it++;
	}
}
// ���荞��ł��C�x���g���甲����
void const StateMachine::EndYieldAllBehaviourFrom(StateMachineBehaviour* behaviour) {
	auto it = behaviours_.begin();
	while (it != behaviours_.end()) {
		if (*it == behaviour) {
			isYieldToEvent_ = false;
			currentYieldedBehaviour_->End();
			break;
		}
		it++;
	}
}
// �L���I�[�g�}�g�����J�n����
void const StateMachine::Start() {
	isPausing_ = false;
	currentBehaviour_->Begin();
}
// �L���I�[�g�}�g�����~����
void const StateMachine::Pause() {
	isPausing_ = true;
}