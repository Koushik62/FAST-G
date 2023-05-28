#include<bits/stdc++.h>

class undir {    // undirected graph class
  std::vector<int> nodes;
  std::vector<std::vector<int>> adj_list;
  std::map<int,int> degree;

  public:

   // adding nodes
    void addnode(int node)
    {
         nodes.push_back(node);
         adj_list.push_back(std::vector<int> ());
         // adj_list[node].assign(vector<int>());
    }

    //adding edges
    void addedge(int st, int en)  // int start, int end
     {
        adj_list[st].push_back(en);
        degree[st]++;

        adj_list[en].push_back(st);
        degree[en]++;
     }

     //removing edges
     void removeedge(int st,int en)
     {
      // you have remove it from st adjlist and en adjlist

      //1st removing from st list 
       if(st>=0 && st<adj_list.size())
       {
        std::vector<int>& neighbours= adj_list[st];
          for(auto it= neighbours.begin();it!=neighbours.end();it++){
            if(*it = en)
            {
            neighbours.erase(it);
            break;
           }
        }
       }

       // 2nd removing from en
       if(en>=0 && en<adj_list.size())
       {
        std::vector<int>& neighbours= adj_list[en];
        for(auto it= neighbours.begin();it!=neighbours.end();it++){
          if(*it = st){
            neighbours.erase(it);
            break;
          }
        }
       
      }

     } 
     bool areadjacent(int st, int en){
      if(st>=0 && st<adj_list.size()){
         for(auto neigh: adj_list[st]){
          if(neigh==en){
            return true;
          }
         }
      }
      return false;
     } 

     void printgraph(){
      for(int i=0;i<adj_list.size();i++){
        std::cout<<"Node "<<nodes[i]<<":";
        for(int neigh:adj_list[nodes[i]]){
          std::cout<<neigh<<" ";
        }
        std::cout<<std::endl;
      }
     }
};

     // directed graph
     class dir {  
  std::vector<int> nodes;
  std::vector<std::vector<int>> adj_list;
  std::map<int,int> indegree;
  std::map<int,int> outdegree;

  public:

   // adding nodes
    void addnode(int node)
    {
         nodes.push_back(node);
         adj_list.push_back(std::vector<int> ());
    }

    //adding edges
    void addedge(int st, int en)  // int start, int end
     {
        adj_list[st].push_back(en);
        outdegree[st]++;
        indegree[en]++;

     }

     //removing edges
     void removeedge(int st,int en)
     {
       
       if(st>=0 && st<adj_list.size())
       {
        std::vector<int>& neighbours= adj_list[st];
          for(auto it= neighbours.begin();it!=neighbours.end();it++){
            if(*it = en)
            {
            neighbours.erase(it);
            outdegree[st]--;
            indegree[en]--;
            break;
           }
        }
       }

      

     } 
     bool areadjacent(int st, int en){
      if(st>=0 && st<adj_list.size()){
         for(auto neigh: adj_list[st]){
          if(neigh==en){
            return true;
          }
         }
      }
      return false;
     } 

     void printgraph(){
      for(int i=0;i<adj_list.size();i++){
        std::cout<<"Node "<<nodes[i]<<":";
        for(int neigh:adj_list[nodes[i]]){
          std::cout<<neigh<<" ";
          
        }
        std::cout<<std::endl;
      }
     }
     };
