#pragma once

#include "map"
#include "set"
#include "list"
#include "string"
#include "sgl_smTransition.h"
#include "sgl_lang_extention.h"
#include "sgl_stateMachineBehaviour.h"

// 有限オートマトンの機能を提供する
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
	// 配列で登録をする
	void const ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours);
	// 遷移を登録する
	void const MakeTransition(StateMachineBehaviour from, StateMachineBehaviour to, std::string name);
	// 指定した遷移名のトランジションを更新してみる
	void const UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false);
	// 割り込みイベントを更新
	void const UpdateEventsYield();
	// 現在のビヘイビアを更新
	void const JumpTo(StateMachineBehaviour* behaviour);
	// イベントを新しく割り込ませる
	void const YieldAllBehaviourTo(StateMachineBehaviour* behaviour);
	// 有限オートマトンを開始する
	void const Start();
	// 有限オートマトンを停止する
	void const Pause();
};

