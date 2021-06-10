#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<math.h>
#include<unordered_map>
#include <utility>
using namespace std;
//node class

/*
   1. add a node in trie
   2. delete a node from trie
   3. autocomplete using trie
   4. word in trie find it
*/
class TrieNode
{
	private:
		unordered_map<char,TrieNode*> nodesMap;
		bool isWordEnd=false;
		char data;
	public:
		TrieNode(){
		
		};
		~TrieNode(){};
		//get nodesMap
		unordered_map<char,TrieNode*> getNodesMap()
		{
			return nodesMap;
		}
		//get map size
		int getTrieMapSize()
		{
			return nodesMap.size(); 
		}
		 //get is word end
		const bool &getWordEnd() const
		{
			return isWordEnd;
		}
		//set word end
		void setWordEnd(const bool &_isWordEnd)
		{
			isWordEnd=_isWordEnd;
		}
		//check if a node exits for a key
		bool isNodeExits(const char &key)
		{
			auto it=nodesMap.find(key);
			if(it!=nodesMap.end())
			{
				return true;
			}
			return false;
		}
		//add a new node to trie
		void addNode( char key, TrieNode *node)
		{
			nodesMap[key]=node;
		}
		//set data
		void setData(const char &_data)
		{
			data=_data;
		}
		//get data
		const char &getData() const
		{
			return data;
		}
		
		//get node based on key
		TrieNode *getNodeByKey(const char &key)
		{
			 
			TrieNode *node=nodesMap[key];
			return node;
		}
		//BFS 
		vector<string> BFS(const string &str)
		{
			vector<string> results;
			queue<pair<string,TrieNode*>> Queue;
			Queue.push(make_pair(str,this));
			while(!Queue.empty())
			{
				//get first element from Queue
				pair<string,TrieNode*> nodeWithdata=Queue.front();
				Queue.pop();
				string currentStr=nodeWithdata.first;
				TrieNode *currentNode=nodeWithdata.second;
				if(currentNode->getWordEnd())
				{
					results.push_back(currentStr);
				}
				unordered_map<char,TrieNode*> nodesMap=currentNode->getNodesMap();
				for(auto _nodeWithData:nodesMap)
				{
					pair<string,TrieNode*> nodeWithData;
					nodeWithData.first=currentStr+_nodeWithData.first;
					nodeWithData.second=_nodeWithData.second;
					Queue.push(nodeWithData);
				}
			}
			return results;
		}
};
//contain data and TrieNode

class Trie
{
	private:
		TrieNode *rootNode=nullptr;
	public:
		Trie()
		{
		}
		~Trie()
		{
		
		}
	
		/*
		   add a node in trie
		*/
		TrieNode *getNode()
		{
			TrieNode *trieNode=new TrieNode();
			trieNode->setWordEnd(false);
			
		}
		 void insert(const string &data)
		 {
		 	if(rootNode==nullptr)
		 	{
				rootNode=getNode(); 
			}
			TrieNode *currentNode=rootNode;
		
			for(const char &str: data)
		 	{
		 		if(currentNode->isNodeExits(str)==false)
				{				
					TrieNode *node=getNode();
					node->setData(str);
				    currentNode->addNode(str,node); 	
				}			
				currentNode=currentNode->getNodeByKey(str);
			}
			currentNode->setWordEnd(true);
		 }
		 //search data exits or not
		 bool search(const string &str)
		{
			if(rootNode==nullptr)
			{
				cout<<"nothing to search"<<endl;
				return false;
			}
			
			TrieNode *currentNode=rootNode;
			for(const char &key :str)
			{
				if(currentNode->isNodeExits(key)==false)
					{
						return false;
					}else
					{
						currentNode=currentNode->getNodeByKey(key);
					}
				}
				return currentNode->getWordEnd();
			
		}
		/*
			AUTO COMPLETE :) using prefix search 
		*/
		vector<string> autoComplete(const string &str)
		{
			vector<string> results;
			if(rootNode==nullptr)
			{
				cout<<"nothing to autocomplete"<<endl;
				return results;
			}	
			TrieNode *currentNode=rootNode;
			for(const char &key :str)
			{
					if(currentNode->isNodeExits(key)==false)
					{
						return results;
					}
					currentNode=currentNode->getNodeByKey(key);
			}
			return currentNode->BFS(str);
		}
		/*
			delete a word from trie
		*/
		bool deleteNode(const string &str)
		{
			if(rootNode==nullptr)
			{
				cout<<"nothing to delete"<<endl;
				return false;
			}
			TrieNode *currentNode=rootNode;
			for(const char &key :str)
			{
					if(currentNode->isNodeExits(key)==false)
					{
						return false;
					}
					currentNode=currentNode->getNodeByKey(key);
			}
			//do all operation
			return true;
		}
};
int main()
{
	Trie *trie=new Trie();
	vector<string> data={"manu","manuxyz","manish","deepak","maa","xyz","sachin","sanju","sanjayrawat"};
	for(auto d:data)
	{
	  trie->insert(d);
	}
	//check a string in trie
//	cout<<"the string is in --- "<<trie->search("sanjayrawat2")<<endl;
	 string searchStr="man";
     vector<string> resultvec=trie->autoComplete(searchStr);
     
	for(auto v:resultvec)
	{
		cout<<"----"<<v<<endl;
	}
	return 0;
}
