/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

1. Create a BST binary search tree
2. DFS preorder postorder inorder
3. BFS level order 
4. Min Depth and Max Depth- RECURSION
5. Diameter of a Tree- RECURSION
6. Check Tree is Binary Tree- ??
7. Mirror of a Tree- RECURSION
*******************************************************************************/

#include <iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
//a binary search tree in c++

typedef pair<int,int> DiaWithHeight ;
template<typename T>
//save calls

class TreeNode
{
	private:
		T data;
		TreeNode<T> *leftNode=nullptr;
		TreeNode<T> *rightNode=nullptr;
	public:
		TreeNode(const T &_data)
		{
			data=_data;
		}
		~TreeNode()
		{
			delete leftNode;
			delete rightNode;
			//leftNode=nullptr;
			//rightNode=nullptr;
		}
		void setData(const T &_data)
		{
			data=_data;
		}
		T  getData() const
		{
			return data;
		}
		void setLeftNode(TreeNode<T> *node)
		{
			leftNode=node;
		}
		void setRightNode(TreeNode<T> *node)
		{
			rightNode=node;
		}
		TreeNode<T> *getLeftNode()
		{
			return leftNode;
		}
		TreeNode<T> *getRightNode()
		{
			return rightNode;
		}
};
template<typename T>
class Tree
{
	private:
		TreeNode<T> *rootNode=nullptr;
    public:
		Tree()
		{
			
		}
		~Tree()
		{
			delete rootNode;
			//rootNode=nullptr;
			cout<<"delloc Tree";
		}
		//insert node in tree 
		void addNode(const T &data)
		{
			if(rootNode==nullptr)
			{
				TreeNode<T> *treeNode=new TreeNode<T>(data);
				rootNode=treeNode;
			}else
			{
				addNodeAtLeftOrRight(data,rootNode);
			}
		}
		void addNodeAtLeftOrRight(const T &data,TreeNode<T> *treeNode)
		{
			//add data at right node
			if(data<treeNode->getData())
			{
				TreeNode<T> *newNode=new TreeNode<T>(data);
				if(treeNode->getLeftNode()==nullptr)
				{
					treeNode->setLeftNode(newNode);
				}else
				{
					addNodeAtLeftOrRight(data,treeNode->getLeftNode());		
				}
				
			}else if(data>treeNode->getData())
			{
				TreeNode<T> *newNode=new TreeNode<T>(data);
				if(treeNode->getRightNode()==nullptr)
				{
				   treeNode->setRightNode(newNode);
				}else
				{
				  addNodeAtLeftOrRight(data,treeNode->getRightNode());	
				}
			}
		}
		//dfs preorder postorder inorder
		/*
		   inorder left->root->right always sorted data
		*/
		void inOrder(TreeNode<T> *node)
		{
			if(node==nullptr)
			{
			   return;
			}
			inOrder(node->getLeftNode());
			cout<<node->getData()<<endl;
			inOrder(node->getRightNode());
		}
		/*
		   postorder ->left->right->root
		*/
		void postOrder(TreeNode<T> *node)
		{
			
			if(node==nullptr)
			{
			   return;
			}
			postOrder(node->getLeftNode());
			postOrder(node->getRightNode());
			cout<<node->getData()<<endl;
		}
			/*
		   preorder ->root->left->right
		*/
		void preOrder(TreeNode<T> *node)
		{
			
			if(node==nullptr)
			{
			   return;
			}
			cout<<node->getData()<<endl;
			preOrder(node->getLeftNode());
			preOrder(node->getRightNode());
		}
		TreeNode<T> *getRootNode()
		{
			return rootNode;
		}
		
		//BFS
		void BFS()
		{
			queue<TreeNode<T>*> Queue;
			Queue.push(rootNode);
			while(!Queue.empty())
			{
				TreeNode<T> *node=Queue.front();
				Queue.pop();
				cout<<node->getData()<<endl;
				if(node->getLeftNode()!=nullptr)
				{
					Queue.push(node->getLeftNode());
				}
				if(node->getRightNode()!=nullptr)
				{
					Queue.push(node->getRightNode());
				}
			}
			
		}
		/*
			
			1. maximum Depth of Binary Tree
		*/
		int maxDepth(TreeNode<T> *node)
		{
			/*code 1
			if (node == nullptr)
   			     return 0;
		    else
		    {
		        int rightDepth = maxDepth(node->getLeftNode());
		        int leftDepth = maxDepth(node->getRightNode());
		        if (leftDepth < rightDepth)
		            return(rightDepth + 1);
		        else return(leftDepth + 1);
		    }*/
		    if (node == nullptr)
   			     return 0;
			return 1+max(maxDepth(node->getLeftNode()),maxDepth(node->getRightNode()));
		}
		/*
		2. minimum Depth of Binary Tree 
		*/
		int minDepth(TreeNode<T> *node)
		{
			
			if(node==nullptr)
			 return 0;
			/* code1
				if(node==nullptr)
			 return 0;
			if(node->getLeftNode()==nullptr && node->getRightNode()==nullptr)
			return 1;
			 int leftDepth; int rightDepth;
			 if(node->getLeftNode()!=nullptr)
			 {
			 	leftDepth=minDepth(node->getLeftNode());
			 }
			 if(node->getRightNode()!=nullptr)
			 {
			 	rightDepth=minDepth(node->getRightNode());
			 }
            return 1+min(leftDepth,rightDepth);
            */
            return 1+min(minDepth(node->getLeftNode()),minDepth(node->getRightNode()));
		}
		//get min and max in a pair
		pair<int,int> minMax(TreeNode<T> *node)
		{
			int min=minDepth(node);
			int max=maxDepth(node);
			pair<int,int> minMax=make_pair(min,max);
			return minMax;
		}
		/*
		Diameter of a tree optimize method better to you tuple :) my mistake use tuple or class or struct or union for better defination
		*/
		DiaWithHeight DiaMeter(TreeNode<T> *node)
		{
			DiaWithHeight diaWithHeight(0,0);
			if(node==nullptr)
			{
				return diaWithHeight;
			}
			DiaWithHeight DiaWithHeightLeftTree=DiaMeter(node->getLeftNode());
			DiaWithHeight DiaWithHeightRightTree=DiaMeter(node->getRightNode());
			int leftDiaMeter=DiaWithHeightLeftTree.first;
			int rightDiaMeter=DiaWithHeightRightTree.first;
			int height=1+max(DiaWithHeightLeftTree.second,DiaWithHeightRightTree.second);
			//fill values
			diaWithHeight.second=height;
			diaWithHeight.first=max(height,max(leftDiaMeter,rightDiaMeter));
			
			return diaWithHeight;
		}
		/*
		Mirror of a binary search tree
		*/
		void Mirror(TreeNode<T> *node)
		{
			if(node==nullptr)
			{
				return;
			}
			Mirror(node->getLeftNode());
			Mirror(node->getRightNode());
			TreeNode<T> *leftNode=node->getLeftNode();
			TreeNode<T> *rightNode=node->getRightNode();
		    swap(leftNode, rightNode);
		}
		/*
		get minimum left node
		*/
	     TreeNode<T> *getMinNode(TreeNode<T> *node)
	     {
	     	if(node==nullptr)
		 	{
		 		return node;
			 }
	     	 while(node->getLeftNode()!=nullptr)
	     	 {
	     	 	node=node->getLeftNode();
			  }
			  return node;
		 }
		 /*
		  get maximum Right node 
		 */
		 TreeNode<T> *getMaxNode(TreeNode<T> *node)
		 {
		 	if(node==nullptr)
		 	{
		 		return node;
			 }
		 	while(node->getRightNode()!=nullptr)
		 	{
		 	  node=node->getRightNode();	
			}
			return node;
		 }
		/*
		  Delete a node from tree by value 
		  https://www.youtube.com/watch?v=gcULXE7ViZw
		  return true if tree is deleted else false
		*/
		TreeNode<T>  *DeleteNode(TreeNode<T> *node,T data)
		{
		
			if(node==nullptr)
			{
			  return node;	
			}else if(data<node->getData())
			{
				node->setLeftNode(DeleteNode(node->getLeftNode(),data));
			}		
			else if(data>node->getData())
			{
				node->setRightNode(DeleteNode(node->getRightNode(),data));
			}else
			{
				if(node->getLeftNode()==nullptr && node->getRightNode()==nullptr)
				{
					 delete node;
					 node=nullptr;	
				}else if(node->getLeftNode()!=nullptr && node->getRightNode()==nullptr)
				{
					//TreeNode<T> *tempNode=node;
					node=node->getLeftNode();			
				}
				else if(node->getLeftNode()==nullptr && node->getRightNode()!=nullptr)
				{
					//TreeNode<T> *tempNode=node;
					node=node->getRightNode();
				}else
				{
					TreeNode<T> *tempNode=getMaxNode(node);
					node->setData(tempNode->getData());
					node=DeleteNode(node->getRightNode(),data);
				}	
			}	
			return node;
		}
		//https://www.youtube.com/watch?v=kR5AxWHa9nc check if a tree is binary tree or not so below tree would always return true
		/*
		  check a tree is a binary tree or not 
		*/
		bool isBinaryTree(TreeNode<T> *node)
		{
			if(node==nullptr)
			{
				return true;
			}
			return isBST(node,INT_MAX,INT_MIN);
		}
		bool isBST(TreeNode<T> *node,int min,int max)
		{
			if(node==nullptr)
			{
				return true;
			}
			if(min!=INT_MAX && min<=node->getData() && max!=INT_MIN && node->getData()>=max)
			{
				return false;
			}
			return isBST(node->getLeftNode(),min,node->getData()) && isBST(node->getRightNode(),node->getData(),max);
		}
		//https://www.youtube.com/watch?v=VVSnM5DGvjg LeetCode 108. Convert Sorted Array to Binary Search Tree - Interview Prep Ep 71
		/*
			create binary tree from a sorted vector
		*/
		void createTreeFromSortedData(vector<T> &data)
		{
		     fillTree(data,0,data.size()-1);
		}
		TreeNode<T> *fillTree(vector<T> &data,int start,int end)
		{
			 if(start>end)
			 {
			 	return nullptr;
			 }
			 int mid=(start+end)/2;
			 TreeNode<T> *node=new TreeNode<T>(data.at(mid));
			 if(rootNode==nullptr)
			 {
			 	rootNode=node;
			 	rootNode->setLeftNode(fillTree(data,start,mid-1));
		        rootNode->setRightNode(fillTree(data,mid+1,end));
			 	return rootNode;
			 }else
			 {
			   node->setLeftNode(fillTree(data,start,mid-1));
			   node->setRightNode(fillTree(data,mid+1,end));
			 } 
			 return node;
		}
};
int main()
{ 
	vector<int> vec2={ 1,2,3,4,5,6,7};
//	sort(vec2.begin(),vec2.end(),greater<int>());
 //  random_shuffle(vec2.begin(),vec2.end());
	Tree<int> *tree=new Tree<int>();
	vector<int> sortData={1,2,3,4,5,6,7};
	tree->createTreeFromSortedData(sortData);
    	tree->BFS();
    	cout<<"is bst"<<tree->isBinaryTree(tree->getRootNode())<<endl;
	/*
	for(int i=0;i<vec2.size();i++)
	{
		tree->addNode(vec2.at(i));
	}*/
	/*
	DFS 
	cout<<"--------------------preOrder"<<endl;
	tree->preOrder(tree->getRootNode());
	cout<<"------------------inOrder"<<endl;
	tree->inOrder(tree->getRootNode());
	cout<<"----------------------postOrder"<<endl;
	tree->postOrder(tree->getRootNode());*/
	//tree->BFS();
	//	cout<<"Min Depth of a tree-->"<<tree->minDepth(tree->getRootNode())<<endl;
	
	//	cout<<"Max Depth of a tree-->"<<tree->maxDepth(tree->getRootNode())<<endl;
	/**/
	/*
	DiaWithHeight minMaxPair=tree->DiaMeter(tree->getRootNode());
	cout<<minMaxPair.first<<endl;
	cout<<minMaxPair.second<<endl;
	*/
	
	/*
	tree->Mirror(tree->getRootNode());
	cout<<"--------------------postOrder"<<endl;
	tree->postOrder(tree->getRootNode());
	*/
	//cout<<"data is "<<tree->getMinNode(tree->getRootNode())->getData();
	
	//delete
//	tree->DeleteNode(tree->getRootNode(),7);
//	tree->BFS();
delete tree;
    return 0;
}
