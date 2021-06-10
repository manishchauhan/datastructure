#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include<iterator> 
#include <utility>
#include <algorithm>
using namespace std;

//EACH Edge contain three variable
//@src=====>source (Vertex start point);
//@dest=====>dest (Vertex end Point)
struct Edge {
    unsigned int src, dest, weight;
};

typedef pair<unsigned int, unsigned int> Pair;

//@your Graph class
class Graph
{
    private:
       //take a vector which store all vertex starting and ending 
       //like  {0,1,4) where first point is vertex index and second point is destination index and thrid point is weight
       vector< vector<Pair>> adjList;
       //for only DFS
      
    public:
     
     
     //CREATE A Graph
     Graph(std::vector<Edge> &edges)
        {
            
            //size of Graph
            unsigned int graph_size = edges.size();
            //resize the adjList
            adjList.resize(graph_size);
            for(unsigned int i=0;i<graph_size;i++)
            {
                unsigned int start=edges[i].src;
                unsigned int dest=edges[i].dest;
                unsigned int weight=edges[i].weight;
                adjList.at(start).push_back(make_pair(dest,weight));
            }
        }
        ~Graph()
        {
            //display whole Graph
           cout<<"CALLED WHEN FINISHED HAPPY I AM CALLED NO MEMORY LEAK";
        }  
        //remove a Edge from a weighted Graph
        //add a edges
        void addEdge(Edge &edge)
        {
             unsigned int graph_size = adjList.size();
             ++graph_size;
             adjList.resize(graph_size);
              unsigned int start=edge.src;
                unsigned int dest=edge.dest;
                unsigned int weight=edge.weight;
             adjList.at(start).push_back(make_pair(dest,weight));
        }
        //display Graph
        void showGraph()
        {
             unsigned int graph_size = adjList.size();
               for (int i = 0; i < graph_size; i++)
           {
              for (Pair v: adjList[i])
            {
                cout << "(" << i << ", " << v.first <<
                        ", " << v.second << ") ";
            } 
           }
            
            cout << endl;
        }
        //BFS FOR Graph
        void BFS(int unsigned startPoint)
        {
            unsigned int graph_size = adjList.size();
            vector<bool> visited(graph_size,false);
            //declare a Queue
            
            queue<int> Queue;
            visited.at(startPoint)=true;
            Queue.push(startPoint);
             vector<Pair>::iterator it;
             
            while(!Queue.empty())
            {
                unsigned int startPoint=Queue.front();
                cout<<startPoint<<"  ";
                Queue.pop();
                for(it = adjList.at(startPoint).begin();it!=adjList.at(startPoint).end();++it)
                {
                   Pair endPointAndWeight=*it;
                   unsigned int currentindex=endPointAndWeight.first;
                  if(!visited.at(currentindex))
                   {
                       visited.at(currentindex)=true;
                       Queue.push(currentindex);
                   }
                   
                }
            }
            cout<<endl;
        }
        //remove a connection in Graph
        void removeConnection(unsigned int u,unsigned int v )
        {
            vector<Pair> &allConnectedNodes=adjList.at(u);
        
              auto it = remove_if(
                allConnectedNodes.begin(),
                allConnectedNodes.end(),
                [=](pair<unsigned int, unsigned int> const& pair) {
                    if(pair.first == v) return true;
                    else return false;
                }
            );
            allConnectedNodes.erase(it, allConnectedNodes.end()); 
            cout<<"----"<<allConnectedNodes.size()<<endl;
        }
        void DFS(int unsigned startPoint)
        {
   
           vector<bool> visited(adjList.size(),false);
           DFSRecursion(startPoint,visited);
   
        }
    void DFSRecursion(unsigned int startPoint,vector<bool> &visited)
    {
            visited.at(startPoint)=true;
            cout<<startPoint<<"  ";
            vector<Pair>::iterator it;
            for(it = adjList.at(startPoint).begin();it!=adjList.at(startPoint).end();++it)
            {
                
                  Pair endPointAndWeight=*it;
                  unsigned int currentindex=endPointAndWeight.first;
                  if(!visited.at(currentindex))
                  {
                          DFSRecursion(currentindex,visited);
                  }
               
            }
    }
};

int main()
{
       vector<Edge> edges =
    {
        // `(x, y, w)` —> edge from `x` to `y` having weight `w`
        { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, { 5, 4, 1 }, { 4, 5, 999 } 
        
    };
    Graph graph(edges);
    //add a new branch
    Edge edge;
    edge.src=2;
    edge.dest=6;
    edge.weight=99;
    graph.addEdge(edge);
    //add e
    graph.removeConnection(4,5);
    graph.showGraph();
    cout<<"THE BELOW CODE YOU SEEN ITS BFS"<<endl;
    graph.BFS(2);
    cout<<"THE BELOW CODE YOU SEEN ITS DFS"<<endl;
    graph.DFS(2);
    return 0;
}

//some comman operation on graph BFS and DFS
