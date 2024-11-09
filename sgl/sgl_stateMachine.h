#pragma once

#include "map"
#include "list"
#include "string"
#include "sgl_smTransition.h"
#include "sgl_lang_extention.h"
#include "sgl_stateMachineBehaviour.h"

// �L���I�[�g�}�g���̋@�\��񋟂���
class StateMachine {
	std::map< std::string, int > transitionsName_Id_;
	std::list< StateMachineBehaviour* > behaviours_;
	std::list< SMTransition* > transitions_;
	StateMachineBehaviour* currentBehaviour_ = nullptr;
	StateMachineBehaviour* currentYieldedBehaviour_ = nullptr;
	bool isPausing_;
	bool isYieldToEvent_;

public:
	bool IsPaused() { return isPausing_; }
	StateMachineBehaviour* CurrentBehaviour() { return currentBehaviour_; }
	StateMachineBehaviour* CurrentYieldedEvent() { return currentYieldedBehaviour_; }


	// �z��œo�^������
	void const ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours);
	// �J�ڂ�o�^����
	void const MakeTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, std::string name);
	// �w�肵���J�ږ��̃g�����W�V�������X�V���Ă݂�
	void const UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false);
	// ���荞�݃C�x���g���X�V
	void const UpdateEventsYield();
	// ���݂̃r�w�C�r�A���X�V
	void const JumpTo(StateMachineBehaviour* behaviour);
	// �C�x���g��V�������荞�܂���
	void const YieldAllBehaviourTo(StateMachineBehaviour* behaviour);
	// ���荞��ł��C�x���g���甲����
	void const EndYieldAllBehaviourFrom(StateMachineBehaviour* behaviour);
	// �L���I�[�g�}�g�����J�n����
	void const Start();
	// �L���I�[�g�}�g�����~����
	void const Pause();
};

