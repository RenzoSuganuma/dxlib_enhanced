#pragma once

// 有限オートマトンのトランジション
class SMTransition {
	StateMachineBehaviour* from_;
	StateMachineBehaviour* to_;
	int id_;

public:
	SMTransition(StateMachineBehaviour* from, StateMachineBehaviour* to, int id)
		: from_(from), to_(to), id_(id) {}
};

