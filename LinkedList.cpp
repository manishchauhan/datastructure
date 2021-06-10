
#include <iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
template<typename T>
/*
node class which can hold data and nextNode
*/
class Node
{
	private:
		T data;
		Node<T> *nextNode=nullptr;
	public:
		Node(const T _data){
			data=_data;
		};
		~Node()
		{
			
		}
	    const int &getData() const
	    {
	    	return data;
		}
		void setData(const T _data)
		{
			data=_data;
		}
	   Node<T> *getNextNode()
	   {
	   	  return nextNode;
	   }
	   void setNextNode(Node<T> *node)
	   {
	   	  nextNode=node;
	   }
};
/*
create a linked list 
*/
template<typename T>
class LinkedList
{
	private:	
   		Node<T> *head=nullptr;
   		Node<T> *tail=nullptr;
   		int length;
    public:
    	LinkedList(){
		}
		~LinkedList()
		{
			
		}
		int getLength()
		{
			return length;
		}
    	/*
    	  append a linked list
    	*/
		addNode(const int &data)
		{
			Node<T> *node=new Node<T>(data);
			if(head==nullptr)
			{
				head=node;
				tail=node;
			}else
			{
				tail->setNextNode(node);
				tail=node;
			}
			length++;
		}
		/*
		  display linked list
		*/
		void displayList(Node<T> *refNode=nullptr)
		{
			
			Node<T> *currentNode=nullptr;
			if(refNode==nullptr)
			{
				currentNode=head;
			}else
			{
				currentNode=refNode;
			}
			while(currentNode!=nullptr)
			{
				cout<<currentNode->getData()<<endl;
				currentNode=currentNode->getNextNode();
			}
		}
		/*
		   remove item from linked list based on value data
		*/
		Node<T> *removeNode(T data)
		{
			    while(head->getData()==data)
			    {
			    	head=head->getNextNode();
				}
				Node<T> *currentNode=head;
				while(currentNode->getNextNode()!=nullptr)
				{
					if(currentNode->getNextNode()->getData()==data)
					{
						currentNode->setNextNode(currentNode->getNextNode()->getNextNode());
					}else
					{
						currentNode=currentNode->getNextNode();
					}
				}
				return head;
		}
		/*
			reverse a Linked list loop
		*/
		void reverse()
		{
			Node<T> *currentNode=head;
			Node<T> *next=nullptr;
			Node<T> *prev=nullptr;
			while(currentNode!=nullptr)
			{
				next=currentNode->getNextNode();
				currentNode->setNextNode(prev);
				prev=currentNode;
				currentNode=next;
			}
			head=prev;
			displayList();
			
		}
		/*
		  get head node
		*/
		Node<T> *getHead()
		{
			return head;
		}
		/*
		https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
		intersection of two linked list
*/
		 Node<T> *intersection(LinkedList<T> *listA,LinkedList<T> *listB) 
		{
			 Node<T> *small=listA->getLength()<listB->getLength()?listA->getHead():listB->getHead();
			 Node<T> *big=listA->getLength()>listB->getLength()?listA->getHead():listB->getHead();
			if(small==nullptr || big==nullptr)
			{
				return nullptr;
			}
			Node<T> *tempA=small;
			Node<T> *tempB=big;
			while(tempA->getData()!=tempB->getData())
			{
			
				if(tempA==nullptr)
				{
					tempA=big;
				}else
				{
					tempA=tempA->getNextNode();
				}
				if(tempB==nullptr)
				{
					tempB=small;
				}else
				{
					tempB=tempB->getNextNode();
				}
			
			}
			return tempA;
			
		}
		/*
			fast slow pointer (get loop in a linked list)
		*/
		bool getLoopNode()
		{
			Node<T> *slow=head;
			Node<T> *fast=head->getNextNode();
			while(fast->getNextNode()!=nullptr && fast!=nullptr)
			{
				if(slow->getData()==fast->getData())
				{
					return true;
				}
				slow=slow->getNextNode();
				fast=fast->getNextNode()->getNextNode();
			}
			return false;
		}
		/*
		  	merge two sorted linked list (linked list would be sorted) 
		*/
		void mergeList(LinkedList<T> *firstList,LinkedList<T> *secondList)
		{
		
			 LinkedList<T> *mergedList=new LinkedList<T>();
			 Node<T> *firstNode=firstList->getHead();
			 Node<T> *secondNode=secondList->getHead();
			 while(firstNode!=nullptr && secondNode!=nullptr)
			 {
			 		
			 	 if(firstNode->getData()<secondNode->getData())
			 	 {
			 	    
			 	     mergedList->addNode(firstNode->getData());
			 	      firstNode=firstNode->getNextNode();
				 }else
				 {
				 	
				 	mergedList->addNode(secondNode->getData());
				 	secondNode=secondNode->getNextNode();
				 }
			 }
			 
			 while(firstNode!=nullptr)
			 {
			 	 mergedList->addNode(firstNode->getData());
			 	   firstNode=firstNode->getNextNode();
			 }
			 while(secondNode!=nullptr)
			 {
			 	 mergedList->addNode(secondNode->getData());
			 	 	secondNode=secondNode->getNextNode();
			 }
			 displayList(mergedList->getHead());
			
		}
		
		
	
};



int main()
{
	LinkedList<int> *linkedList=new LinkedList<int>();
	LinkedList<int> *linkedList1= new LinkedList<int>();
	
	vector<int> data={1,2,5,6,7,8,9};
	for(auto d: data)
	{
		linkedList->addNode(d);
	 } 
	 linkedList->displayList();
	 cout<<"------------------"<<endl;
	 vector<int> data1={4,5,6,7,8};
	 for(auto d1:data1)
	 {
	 	linkedList1->addNode(d1);
	 }
	
	//linkedList->removeNode(30);
	cout<<"---------------------"<<linkedList->getLength()<<endl;
	
	//linkedList->reverse();
	
	/*
	Node<int> *intersectNode=linkedList->merge(linkedList1,linkedList);
	cout<<"data with node is---"<<intersectNode->getData()<<endl;
	*/
	linkedList->mergeList(linkedList1,linkedList);
	return 0;
}
