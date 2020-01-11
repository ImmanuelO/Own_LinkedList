#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

namespace ImanList {
	
	template<typename T>
	struct Node
	{
		T data;
		unique_ptr<Node> next = make_unique<Node>();
	};
	
	template<typename T>
	class LinkedList
	{
		public:
			LinkedList();
			append(T addToEndOfList);
			insert(T dataLessThan);
			remove(T removeFromList);
		
		private:
			unique_ptr<Node> head;
	};
}
