#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<math.h>
#include<algorithm>
#include<string>
#include <typeinfo>

using namespace std;
template<typename U,typename T>
class HashNode
{
	//public
	private:
		T data;
		U key;
	public:
		HashNode(){
		};
		~HashNode()
		{
			//cout<<"node deleted"<<endl;	
		}
		//set data in a hashnode
		void setData(T _data)
		{
			data=_data;
		}
		//get data from a hashnode
		T getData()
		{
			return data;	
		}
		//set key of a hashnode
		void setKey(U _key)
		{
			key=_key;
		}
		//get key of a hashnode
		U getKey()
		{
			return key;
		}
				
};
using namespace std;
template<typename U,typename T>
class HashMap
{
	private:
		unsigned int __size=0;
	    const unsigned int TABLE_SIZE = 256;
	    vector<HashNode<U,T>*> Table;
	public:
		HashMap(){
			Table.resize(TABLE_SIZE,nullptr);
		}
		
		
		~HashMap()
		{
			for(auto p: Table)
			{
				delete p;
			}
			Table.clear();
			cout<<"finish hash map"<<endl;
		}
		bool isString(U key)
		{
		  if(*(typeid(key).name())=='i')
		    {
		        return false;
		    }
		    return true;
		}
		//new hash key
		unsigned int getHashKey(int key)
		{
			unsigned int keyValue=0;
			 keyValue=key%TABLE_SIZE;	   
			return keyValue;
		}
		unsigned int getHashKey(string &key)
		{
			
			unsigned int keyValue=0;
			unsigned int hash=0;
		    for(auto c:key)
			  {
			  	hash+=int(c);
			  }
		    keyValue=hash%TABLE_SIZE;	   
			return keyValue;
		}
		//insert data in hashmap
		void  insert(U key,T data)
		{
			//if key is number
			unsigned int keyValue=getHashKey(key);
			while(Table.at(keyValue)!=nullptr )
			{		
				  keyValue=(keyValue+1)%TABLE_SIZE;
			}
			if(Table[keyValue]!=nullptr)
			{
				delete Table[keyValue];
				Table[keyValue]=nullptr;
			}
			 HashNode<U,T> *hashNode=new HashNode<U,T>(); 
				  hashNode->setData(data);
				  hashNode->setKey(key);
			Table[keyValue]=hashNode;
		}
		//get data or 
		HashNode<U,T> *getData(U key)
		{
	
			unsigned int keyValue=getHashKey(key);
			while(Table.at(keyValue)!=nullptr && Table.at(keyValue)->getKey()!=key)
			{		
				  keyValue=(keyValue+1)%TABLE_SIZE;
			}
		   	if(Table[keyValue]==nullptr)
		   	{
		   		 HashNode<U,T> *hashNode=new HashNode<U,T>(); 
				return hashNode;		
		   }
			return  Table.at(keyValue);
			 
		}
		
		//delete data from a hashmap
		bool deleteNode(U key)
		{
		    unsigned int keyValue=getHashKey(key);
		    
			while(Table.at(keyValue)!=nullptr && Table.at(keyValue)->getKey()!=key)
			{		
				  keyValue=(keyValue+1)%TABLE_SIZE;
				  
			}
		    if(Table.at(keyValue)==nullptr)
			{
			  return false;
			}
			 Table.at(keyValue)=nullptr;
			 return true;
		}
		//check if hashnode in a hashmap or noy
	    bool exits(U key)
		{
		    unsigned int keyValue=getHashKey(key);
		    
			while(Table.at(keyValue)!=nullptr && Table.at(keyValue)->getKey()!=key)
			{		
				  keyValue=(keyValue+1)%TABLE_SIZE;
				  
			}
		    if(Table.at(keyValue)!=nullptr)
			{
			  return true;
			}
			 return false;	
		}
		//get size of map
		const unsigned size() const
		{
			return __size;
		}
};

int main()
{
	
	HashMap<int,string> *hashMap=new HashMap<int,string>();
	hashMap->insert(101,"manish");
	hashMap->insert(102,"sachin");
	hashMap->insert(10223,"deepak");
	cout<<hashMap->getData(10223)->getData()<<endl;
	cout<<hashMap->deleteNode(10223)<<endl;
	cout<<hashMap->getData(10223)->getData()<<endl;
	cout<<"3--->"<<hashMap->getData(102)->getData()<<endl;
	cout<<hashMap->exits(101)<<endl;
	delete hashMap;
	
	
	cout<<"hash map2---------------------"<<endl;
		HashMap<string,string> *hashMap1=new HashMap<string,string>();
	hashMap1->insert("101","manishstr");
	hashMap1->insert("102","sachinstr");
	hashMap1->insert("10223","deepakstr");
	cout<<hashMap1->getData("10223")->getData()<<endl;
	cout<<hashMap1->deleteNode("10223")<<endl;
	cout<<hashMap1->getData("10223")<<endl;
	cout<<"3--->"<<hashMap1->getData("102")->getData()<<endl;
	cout<<hashMap1->exits("101")<<endl;
	delete hashMap1;
	
	return 0;
}


