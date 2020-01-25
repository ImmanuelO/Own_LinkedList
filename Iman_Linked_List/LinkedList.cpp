#include "pch.h"
#include "LinkedList.h"
#include <iostream>

using std::move;
using std::cout;
using std::endl;


template<class T>
ImanList::LinkedList<T>::LinkedList(LinkedList && list)
{
	this->head = move(list.head);
}

template<class T>
void ImanList::LinkedList<T>::append(T addDataToEndOfList)
{
	unique_ptr<Node<T>> newNode = addDataToNewNode(addDataToEndOfList);

	Node<T>* iterativeNodePtr{nullptr};

	if (head == nullptr) {	
		head = move(newNode);    
	}
	else
	{
		iterativeNodePtr = head.get();
		while (iterativeNodePtr->next != nullptr)
		{
			iterativeNodePtr = iterativeNodePtr->next.get();
		}
		iterativeNodePtr->next = move(newNode);
	}
}

template<class T>
void ImanList::LinkedList<T>::insert(T datalessthan)
{
	unique_ptr<Node<T>> newNode = addDataToNewNode(datalessthan);

	Node<T>* iterativeNodePtr{ nullptr };
	Node<T>* previousNodePtr{ nullptr };

	if (head == nullptr) {
		head = move(newNode);
	}
	else
	{
		iterativeNodePtr = head.get();
		while (iterativeNodePtr != nullptr && newNode->data >= iterativeNodePtr->data)
		{
			previousNodePtr = iterativeNodePtr;
			iterativeNodePtr = iterativeNodePtr->next.get();
		}

		if (previousNodePtr == nullptr ) {
			newNode->next = move(head);
			head = move(newNode);
		}
		else if (newNode->data == previousNodePtr->data) {}
		else {
			newNode->next = move(previousNodePtr->next);
			previousNodePtr->next = move(newNode);
		} 
	}

}

template<class T>
void ImanList::LinkedList<T>::remove(T removeFromList)
{
	Node<T>* iterativeNodePtr{ nullptr };
	Node<T>* previousNodePtr{ nullptr };

	if (head != nullptr) {
		iterativeNodePtr = head.get();
		while (removeFromList != iterativeNodePtr->data && iterativeNodePtr != nullptr)
		{
			previousNodePtr = iterativeNodePtr; 
			iterativeNodePtr = iterativeNodePtr->next.get();
		}

		if (previousNodePtr == nullptr) {
			head = move(head->next);
		}
		else {
			previousNodePtr->next = move(iterativeNodePtr->next);
		}
	}
}

template<class T>
void ImanList::LinkedList<T>::print() const
{
	Node<T>* listIter;
	listIter = head.get();
	while (listIter != nullptr) {
		std::cout << listIter->data << ", ";
		listIter = listIter->next.get();
	}
}



template<class T>
unique_ptr<ImanList::Node<T>> ImanList::LinkedList<T>::addDataToNewNode(T& data)
{
	unique_ptr<Node<T>> newNode = make_unique<Node<T>>();
	newNode->data = data;
	return newNode;
}
