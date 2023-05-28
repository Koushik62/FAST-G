#include<bits/stdc++.h>

class BFS
{
    
    std::vector<std::vector<int>> adj_list;
    public:
    BFS(int numvertices) : adj_list(numvertices){}
    void addEdge(int st, int en){
        adj_list[st].push_back(en);
        
    }
        void bfs(int st){
        std::vector<bool> visited(adj_list.size(),false);
        std::vector<int> final;
        std::queue<int> q;

        visited[st]=true;
        q.push(st);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            std::cout<<cur<<" ";
            
            for(int neigh :adj_list[cur]){
                if(!visited[neigh]){
                    visited[neigh]=true;
                    q.push(neigh);
                }
            } 
            
         }
           
    }
}; 
