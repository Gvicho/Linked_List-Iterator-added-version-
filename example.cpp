#include<iostream> //here iostrem can be deleted,because it's olready in list header file
#include"linked_list.h"

int main(){
	list<char> ls; // declearing list
	list<char>::Iterator it;
	
	int number_of_elements;
	std::cin>>number_of_elements;
	while(number_of_elements--) {
		char element; 
		std::cin>>element;
		ls.Add_Back(element); //adding element to the end of the list
	}
	
	
	ls.Erase_Back(); //erasing element from the end of the list
	
	
	ls.Add_Back('a'); //adding 'a' to the and of the list
	
	
	ls.PrintLists(); //printing hole list on console
	
	// adding element on pointed position ('b' will be added before end buffer node)
	it=ls.end();
	it--;
	ls.Add('b',it);
	
	// iterating through the list with the inbuilt iterator
	for(it=ls.begin();it!=ls.end();it++){
		std::cout<<it.iterator->NodeVal<<' ';
	}
	
	std::cout<<ls.Size()<<'\n'; //printing the number of elements in the list
}
