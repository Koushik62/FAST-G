#include<bits/stdc++.h>

class DFS{

  std:: vector<std::vector<int>> adj_list;
  std::vector<bool> visited;

  public:
    DFS(int num_vertices) : adj_list(num_vertices),visited(num_vertices,false){}

    void add_edge(int st ,int en){
        adj_list[st].push_back(en);

    }

    void traverse(int st){
        visited[st]=true;
        print(st);

        for(int v: adj_list[st]){
            if(!visited[v]){
                traverse(v);
            }
        }

    }

    void print(int x){
        std::cout<<x<<" ";
    }
};