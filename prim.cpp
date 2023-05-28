#include<bits/stdc++.h>
#define MP std::make_pair

class prim {

    private:
       int v;
       std::vector<std::vector<std::pair<int,int>>> adj_list;
    public:
    prim(int vertices) : v(vertices){
        adj_list.resize(v);
    }

    void addEdge(int u, int v, int weight){
            adj_list[u].push_back(MP(v,weight));
            adj_list[v].push_back(MP(u,weight));
    }


    // function to find minimum spanning tree using prim's algo
    void primMST(){
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;  
        // greater function enhances ascending order.
        std::vector<int> dist(v,1e9);
        std::vector<int> par(v,-1); // parent
        std::vector<bool> Vis(v,false);

        int st=0;
        pq.push(MP(0,st));
        dist[st]=0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            Vis[u]=true;

            // Iterate through the neighbours
            for(auto &neigh : adj_list[u]){
                int v = neigh.first;
                int weight = neigh.second;

                if(!Vis[v] && weight<dist[v]){
                    dist[v]=weight;
                    pq.push(MP(dist[v],v));
                    par[v]=u;
                }
            }
        }

        // print the minimum spanning tree
        for(int i=1;i<v;i++){
            std::cout<<par[i]<<"-"<<i<< std::endl;
        }
    }

};