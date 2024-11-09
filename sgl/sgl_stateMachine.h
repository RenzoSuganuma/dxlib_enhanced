#pragma once

#include "map"
#include "list"
#include "string"
#include "sgl_smTransition.h"
#include "sgl_lang_extention.h"
#include "sgl_stateMachineBehaviour.h"

// 有限オートマトンの機能を提供する
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


	// 配列で登録をする
	void const ResistBehaviours(std::list<StateMachineBehaviour*>  behaviours);
	// 遷移を登録する
	void const MakeTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, std::string name);
	// 指定した遷移名のトランジションを更新してみる
	void const UpdateTransition(std::string name, bool& condition, bool equalsTo = true, bool isTrigger = false);
	// 割り込みイベントを更新
	void const UpdateEventsYield();
	// 現在のビヘイビアを更新
	void const JumpTo(StateMachineBehaviour* behaviour);
	// イベントを新しく割り込ませる
	void const YieldAllBehaviourTo(StateMachineBehaviour* behaviour);
	// 割り込んでたイベントから抜ける
	void const EndYieldAllBehaviourFrom(StateMachineBehaviour* behaviour);
	// 有限オートマトンを開始する
	void const Start();
	// 有限オートマトンを停止する
	void const Pause();
};

