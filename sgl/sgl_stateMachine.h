#pragma once

#include "map"
#include "list"
#include "string"
#include "sgl_smTransition.h"
#include "sgl_lang_extention.h"
#include "sgl_stateMachineBehaviour.h"

// �L���I�[�g�}�g���̋@�\��񋟂��� ��C++20�̃o�[�W�����ȏ�
class StateMachine {
	std::map< std::string, int > transitionsName_Id_;
	std::list< StateMachineBehaviour* > behaviours_; /* ����͊O������|�C���^�̃R�s�[���n�����B�X�}�[�g�|�C���^�̉\��������̂ŉ�������Ȃ� */
	std::list< SMTransition* > transitions_;
	StateMachineBehaviour* currentBehaviour_ = nullptr; /* ����͊O������|�C���^�̃R�s�[���n�����B�X�}�[�g�|�C���^�̉\��������̂ŉ�������Ȃ� */
	StateMachineBehaviour* currentYieldedBehaviour_ = nullptr; /* ����͊O������|�C���^�̃R�s�[���n�����B�X�}�[�g�|�C���^�̉\��������̂ŉ�������Ȃ� */
	bool isPausing_;
	bool isYieldToEvent_;

public:
	bool isPaused() { return isPausing_; }
	int behaviourCount() { return behaviours_.size(); }
	StateMachineBehaviour* CurrentBehaviour() { return currentBehaviour_; }
	StateMachineBehaviour* CurrentYieldedEvent() { return currentYieldedBehaviour_; }


	// �z��œo�^������
	void const ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours);
	// �r�w�C�r�A��o�^����
	void const ResistBehaviour(StateMachineBehaviour* behaviours);
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
	// �j���i����j����
	void const Dispose() {
		transitionsName_Id_.clear(); // ���
		transitions_.clear(); // ���
		currentBehaviour_ = nullptr;
		currentYieldedBehaviour_ = nullptr;
	}
};

