#include<bits/stdc++.h>

class DirectedDijkstra {
private:
    int v;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    DirectedDijkstra(int numVertices) : v(numVertices), adjList(numVertices) {}

    void addEdge(int start, int end, int weight) {
        adjList[start].push_back({end, weight});
    }

    std::vector<int> Dijkstra(int start) {
        std::vector<int> dist(v,1e9);
        dist[start] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, start});
         std::vector<bool> Vis(v,false);
        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentDistance = pq.top().first;
            pq.pop();
            
              if(currentDistance>dist[currentVertex]) continue;
            for (auto& neighbor : adjList[currentVertex]) {
                
                int nextVertex = neighbor.first;
                int edgeWeight = neighbor.second;
                int newDistance = currentDistance + edgeWeight;

                if (newDistance < dist[nextVertex]) {
                    dist[nextVertex] = newDistance;
                    pq.push({newDistance, nextVertex});
                }
            }
        }

        return dist;
    }
};
