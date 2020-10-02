//
//  main.cpp
//  Kruskal
//
//  Created by 원현식 on 2020/10/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(const Edge &edge) const {
        return this->distance < edge.distance;
    }
};

int findParent(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionParent(int parent[], int a, int b){
    a = findParent(parent, a);
    b = findParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

/*
7 9
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25
*/
int main(int argc, const char * argv[]) {
    vector<Edge> v;
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a,b,distance;
        cin >> a >> b >> distance;
        v.push_back(Edge(a, b, distance));
    }

    int parent[V+1];
    for (int i = 1; i <= V ; i++) {
        parent[i] = i;
    }

    sort(v.begin(), v.end());
    int answer = 0;
    for (Edge edge: v) {
        int node1 = edge.node[0];
        int node2 = edge.node[1];
        int dis = edge.distance;

        if (findParent(parent, node1) != findParent(parent, node2)) {
            answer += dis;
            unionParent(parent, node1, node2);
        }

    }
    cout << answer;

}

