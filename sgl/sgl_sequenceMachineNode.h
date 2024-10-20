#pragma once

#include "functional"
#include "list"

namespace sgl::SequenceMachine
{
	class SequenceMachineNode
	{
	protected:
		std::list< std::function< void() > > OnNextNodeChanged;
		SequenceMachineNode* next_;
		int id_;

	public:
		void const SetNextNode(SequenceMachineNode* node)
		{
			next_ = node;
		};

		const SequenceMachineNode* const GetNextNode() const
		{
			return next_;
		}

		void const SetId(int id)
		{
			id_ = id;
		}

		int const GetId() const
		{
			return id_;
		}

		virtual void StartNode() = 0;

		virtual void UpdateNode() = 0;

		virtual void EndNode() = 0;
	};
}
