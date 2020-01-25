// Iman_Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace ImanList;

int main()
{
	//ImanList::LinkedList<std::string> practiceAppending;

	//practiceAppending.append("Jennifer");
	//practiceAppending.append("Immanuel");


	ImanList::LinkedList<int> practiceInserting;
	
	practiceInserting.insert(4); //4
	practiceInserting.insert(2); //2,4
	practiceInserting.remove(2); //4
	practiceInserting.insert(3); //3,4 
	practiceInserting.remove(4); //3
	practiceInserting.append(5); 
	practiceInserting.append(5); //3,5, 5

	LinkedList<int> movePracticeInserting{ move(practiceInserting )};

	practiceInserting.insert(2);
	practiceInserting.insert(2);
	practiceInserting.insert(3);
	practiceInserting.insert(6);
	practiceInserting.insert(1); //1,2,3,6
	movePracticeInserting.insert(2);
	//movePracticeInserting.remove(2);
	practiceInserting.print();
	cout << endl;
	movePracticeInserting.print();


	//unique_ptr<int> iman{ make_unique<int>(5) };
	//unique_ptr<int> jennifer{ make_unique<int>(3) };
	//unique_ptr<int> Temp{ make_unique<int>()};
	//int* ptr;


	//ptr = iman.get();


	//std::cout << " Unique value: " << *iman << std::endl;
	//std::cout << " Ptr value: " << *ptr << " Ptr address: "
	//	      << ptr << std::endl;

	//Temp = move(iman);
	//iman = move(jennifer);

	//std::cout << " Unique value: " << *iman << std::endl;
	//std::cout << " Ptr value: " << *ptr << " Ptr address: "
	//		  << ptr << std::endl;


}
