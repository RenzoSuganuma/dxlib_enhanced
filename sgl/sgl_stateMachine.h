#pragma once

#include "map"
#include "set"
#include "list"
#include "string"
#include "sgl_smTransition.h"
#include "sgl_lang_extention.h"
#include "sgl_stateMachineBehaviour.h"

// �L���I�[�g�}�g���̋@�\��񋟂���
class StateMachine {
	std::map< std::string, int > transitions_;
	std::set< StateMachineBehaviour* > behaviours_;
	std::set< SMTransition* > transitions_;
	StateMachineBehaviour* currentBehaviour_;
	StateMachineBehaviour* currentYieldedBehaviour_;
	bool isPausing_;
	bool isYieldToEvent_;

	Getter(bool, IsPaused, isPausing_)
		Getter(StateMachineBehaviour*, CurrentBehaviour, currentBehaviour_)
		Getter(StateMachineBehaviour*, CurrentYieldedBehaviour, currentYieldedBehaviour_)

public:
	// �z��œo�^������
	void const ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours);
	// �J�ڂ�o�^����
	void const MakeTransition(StateMachineBehaviour from, StateMachineBehaviour to, std::string name);
	// �w�肵���J�ږ��̃g�����W�V�������X�V���Ă݂�
	void const UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false);
	// ���荞�݃C�x���g���X�V
	void const UpdateEventsYield();
	// ���݂̃r�w�C�r�A���X�V
	void const JumpTo(StateMachineBehaviour* behaviour);
	// �C�x���g��V�������荞�܂���
	void const YieldAllBehaviourTo(StateMachineBehaviour* behaviour);
	// �L���I�[�g�}�g�����J�n����
	void const Start();
	// �L���I�[�g�}�g�����~����
	void const Pause();
};

