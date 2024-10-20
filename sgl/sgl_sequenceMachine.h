#pragma once

#include "sgl_sequenceMachineNode.h"
#include "unordered_map"
#include "iostream"

namespace sgl::SequenceMachine
{
	class SequenceMachine final
	{
	private:
		std::unordered_map< int, SequenceMachineNode* > nodes_;
		std::unordered_map< int, bool > transitions_;
		int currentNodeId_;
		bool isRunning_;

	public:
		template < typename T >
		void const ResistNode(T* node)
		{
			int id = nodes_.size();
			SequenceMachineNode* casted = static_cast<SequenceMachineNode*> (node);
			if (casted != nullptr) {
				casted->SetId(id);
				nodes_.insert(std::make_pair(casted->GetId(), casted));
			}
		}

		template < typename T1, typename T2 >
		void const ApplyTransition(T1* node1, T2* node2)
		{
			SequenceMachineNode* casted_node1 = static_cast<SequenceMachineNode*> (node1);
			SequenceMachineNode* casted_node2 = static_cast<SequenceMachineNode*> (node2);

			if (casted_node1 != nullptr && casted_node2 != nullptr) {
				casted_node1->SetNextNode(casted_node2);
				casted_node2->SetNextNode(nullptr);

				transitions_.insert(std::make_pair(casted_node1->GetId(), false));
			}
		}

		void const UpdateTransition(int id, bool condition)
		{
			transitions_[id] = condition;
		}

		void const SetCurrentNodeAs(int id)
		{
			currentNodeId_ = id;
		}

		template < typename T >
		void const SetCurrentNodeAs(T* node1)
		{
			SequenceMachineNode* casted_node = static_cast<SequenceMachineNode*>(node1);
			if (casted_node != nullptr) {
				currentNodeId_ = casted_node->GetId();
			}
		}

		void const StartMachine()
		{
			isRunning_ = true;
			currentNodeId_ = 0;
			nodes_[currentNodeId_]->StartNode();
		}

		void const UpdateMachine()
		{
			if (!isRunning_) return;

			nodes_[currentNodeId_]->UpdateNode();

			for (int i = 0; i < nodes_.size(); ++i) {
				if (
					(transitions_.find(i) != transitions_.end())
					&&
					(nodes_[currentNodeId_]->GetNextNode() != nullptr
						&& nodes_[i]->GetNextNode() != nullptr)
					&&
					(nodes_[currentNodeId_]->GetNextNode()->GetId()
						== nodes_[i]->GetNextNode()->GetId())
					) {
					nodes_[currentNodeId_]->EndNode();

					currentNodeId_ = nodes_[currentNodeId_]->GetNextNode()->GetId();

					nodes_[currentNodeId_]->StartNode();
				}
			}
		}

		void const EndMachine()
		{
			isRunning_ = false;

			nodes_[currentNodeId_]->EndNode();
		}
	};
}
