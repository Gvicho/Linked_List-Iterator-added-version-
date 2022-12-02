//Linked list with basic functionality & Builtin Iterator with basic functions

#ifndef linked_list
#define linked_list
#include<cstddef>
#include<iostream>
template<typename T>class list{
	private:
	template<typename t>struct node{
		t NodeVal;
		node<t> *next=NULL,*last=NULL;
	};
	node<T> *Begin,*End,*head;
	int List_size=0;
	public:
	struct Iterator{
		node<T> *iterator;
		//constructor;
		Iterator(){};
		Iterator(node<T> *new_node){
			iterator=new_node;
		}
		
		Iterator& operator++(int){
			if(this->iterator->next==NULL)return *this;
			this->iterator=this->iterator->next;
			return *this;
		}
		Iterator& operator--(int){
			if(this->iterator->last==NULL)return *this;
			this->iterator=this->iterator->last;
			return *this;
		}
		friend bool operator==(const Iterator&a ,const Iterator&b){
			return (a.iterator)==(b.iterator);
		}
		friend bool operator!=(const Iterator&a ,const Iterator&b){
			return (a.iterator)!=(b.iterator);
		}
	};
	//constructor
	list(){
		head=new node<T>;
		Begin=head; End=head;
	}
	//destructor
	~list(){
		node<T> *temporary_node;
		while(Begin->next!=NULL){
			temporary_node=Begin->next;
			delete Begin;
			Begin=temporary_node;
		}
		delete Begin;
	}
	int Size(){
		return List_size;
	}
	void Add_Back(T element){
		head->NodeVal=element;
		node<T> *NewNode=new node<T>;
		head->next=NewNode;
		NewNode->last=head;
		head=NewNode; End=head;
		++List_size;
	}
	void Erase_Back(){
		if(End->last==NULL)return;
		node<T> *temporary_node=End->last;
		if(temporary_node->last==NULL){
			End->last=NULL;
			delete temporary_node;
			return;
		}
		End->last=temporary_node->last;
		(temporary_node->last)->next=End;
		delete temporary_node;
		head = End;
		--List_size;
	}
	void Add(T element,Iterator it){
		node<T>*temporary_node = it.iterator;
		node<T>*New_Node = new node<T>;
		New_Node->NodeVal=element;
		New_Node->last=temporary_node;
		New_Node->next=temporary_node->next;
		(temporary_node->next)->last=New_Node;
		temporary_node->next=New_Node;
	}
	void PrintLists(){
		node<T> *temporary_node=Begin;
		while(temporary_node->next!=NULL){
			std::cout<<temporary_node->NodeVal<<' ';
			temporary_node=temporary_node->next;
		}
		std::cout<<'\n';
	}
	Iterator begin(){
		Iterator temporary_it(Begin);
		return temporary_it;
	}
	Iterator end(){
		Iterator temporary_it(End);
		return temporary_it;
	}
};
#endif
