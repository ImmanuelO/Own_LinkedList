#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

namespace ImanList {

	template<class T>
	struct Node
	{
		T data;
		unique_ptr < Node<T>> next;
	};

	template<class T>
	class LinkedList
	{
	public:
		LinkedList(){};
		LinkedList(LinkedList&& list);
		LinkedList(const LinkedList&) = delete;
		
		void append(T addtoendoflist);
		void insert(T datalessthan);
		void remove(T removeFromList);
		void reverse();
		void print() const;

	private:
		unique_ptr<Node<T>> head;

		unique_ptr<Node<T>> addDataToNewNode(T& data);
	};
}