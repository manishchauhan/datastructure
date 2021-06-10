#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<math.h>
using namespace std;
//node class
template<typename T>
/*
  add a node at start
  add a node at end
  delete node from start
  delete node from end
  delete a node by value
  search a value in list
  print in forward order
  print in backward order
*/
class Node
{
	private:
		T data;
		Node<T> *prev=nullptr;
		Node<T> *next=nullptr;
	public:
		Node(T _data){
			data=_data;
		};
		~Node()
		{
		 
		}
		//set get node
		Node<T> *getPrevNode()
		{
			return prev;
		}
		Node<T>* getNextNode()
		{
			return next;
		}
		void setPrevNode(Node<T> *node)
		{
			prev=node;
		}
		void setNextNode(Node<T> *node)
		{
			next=node;
		}
		//set get data
		const int &getData() const
		{
			return data;	
		}	
		void setData(T _data)
		{
		   data=_data;	
		}	
};

template<typename T>
class DoublyLinkedList
{
   private:
   		 /*
   		 	head and tail would be always nullptr
   		 */
   	     int size=0;
   	     Node<T> *head=nullptr;
   	     Node<T> *tail=nullptr;
	public:
		DoublyLinkedList(){
		  
		};
		~DoublyLinkedList(){
			delete head;
			delete tail;
		};
		/*
			add data at front
			1->2->3->4
			(new Node) 5->1->2->3->4
		*/
		pushFront(const T &data)
		{
			Node<T> *node=new Node<T>(data);
			if(head==nullptr)
			{
			   head=node;
			   tail=node;
			}else
			{
			  head->setPrevNode(node);
			  node->setNextNode(head);
			  head=node;
			}
			size+=1;
		}
		/*
			add data at end
			1->2->3->4
			(new Node) 1->2->3->4->5
		*/
		pushBack(const T &data)
		{
			Node<T> *node=new Node<T>(data);
			if(head==nullptr)
			{
			   head=node;
			   tail=node;
			}else
			{
			  	tail->setNextNode(node);
			  	node->setPrevNode(tail);
			  	tail=node;
			}
			size+=1;
		}
		eraseWhole()
		{
			tail=nullptr;
			head=nullptr;
		}
		/*
			pop data from front
			1->2->3->4
			(new Node) 2-3-4
		*/
		 bool popFront()
		{
			Node<T> *frontNode=head;
			if(frontNode==nullptr)
			{
				return false;	
			}else
			{
				if(size==1)
				{
					eraseWhole();	
				}else
				{
				   head=frontNode->getNextNode();
			       head->setPrevNode(nullptr);
				   size-=1;
				}
			}
			
			return true;
		}
		/*
			add data at end
			1->2->3->4
			(new Node) 1->2->3
		*/
		bool popBack()
		{
			Node<T> *backNode=tail;
			if(backNode==nullptr)
			{
				return false;
			}
			else
			{
				if(size==1)
				{
					eraseWhole();
				}else
				{
				   tail=backNode->getPrevNode();
				   tail->setNextNode(nullptr);
				   size-=1;
				}
			}
			
			return true;
		}
		/*
		  get size
		*/
		const int &getSize() const
		{
			return size;
		}
		/*
		   search by value
		*/
		bool searchByValue(const T &data)
		{
			Node<T> *currentNode=head;
			while(currentNode!=nullptr)
			{
				if(currentNode->getData()==data)
				{
					return true;
				}
				currentNode=currentNode->getNextNode();
			}
			return false;
		}
		/*
		   erase by value
		*/
		bool erase(const int &data)
		{
			  while(head->getData()==data)
			    {
			    	head=head->getNextNode();
			  	   size-=1;
				}
				Node<T> *currentNode=head;
				while(currentNode->getNextNode()!=nullptr)
				{
					if(currentNode->getNextNode()->getData()==data)
					{
						currentNode->setNextNode(currentNode->getNextNode()->getNextNode());
							size-=1;
					
					}else
					{
						currentNode=currentNode->getNextNode();
					}
				
				}
				Node<T> *tailNode=tail;
				while(tailNode->getPrevNode()!=nullptr)
				{
					if(tailNode->getPrevNode()->getData()==data)
					{
						tailNode->setPrevNode(tailNode->getPrevNode()->getPrevNode());
					
					}else
					{
						tailNode=tailNode->getPrevNode();
					}
				}
		}
		/*
		  display forward
		*/
	    void displayForward()
	    {
	    	Node<T> *currentNode=head;
	    	while(currentNode!=nullptr)
	    	{
	    		cout<<currentNode->getData()<<endl;
	    		currentNode=currentNode->getNextNode();
			}
		}
		/*
		   display backwards
		*/
	    void displayBackward()
	    {
	    	Node<T> *currentNode=tail;
	    	while(currentNode!=nullptr)
	    	{
	    		cout<<currentNode->getData()<<endl;
	    		currentNode=currentNode->getPrevNode();
			}
		}
};
void display(const list<int> &list)
{
	for(auto const d: list)
	{
		cout<<d<<endl;
	}
}
int main()
{
	/*
		for testing purpose
	
	vector<int> data={1,2,3,4,5};
    list<int> myList;
    for(auto d: data)
    {
    	myList.push_back(d);
	}
	myList.pop_front();
	display(myList);
	*/
	vector<int> data={1,1,1,2,3,4,5,1,1,6,7,8,9};
	DoublyLinkedList<int> *DlinkedList=new DoublyLinkedList<int>();
	for(auto d:data)
	{
		DlinkedList->pushBack(d);	
	}
	/*
	DlinkedLit-s>displayForward();
	cout<<"-----------------------"<<endl;
	DlinkedList->displayBackward();
	*/
	DlinkedList->erase(1);
	DlinkedList->displayForward();
	cout<<"-----------------------"<<endl;
	DlinkedList->popBack();
		DlinkedList->popFront();
	
		DlinkedList->displayForward();
		
		cout<<"---------------------"<<endl;
		DlinkedList->displayBackward();
		
			cout<<"---->>>>>"<<DlinkedList->getSize()<<endl;
	return 0;
}
