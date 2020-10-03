//
//  main.cpp
//  도시 분할 계획
//
//  Created by 원현식 on 2020/10/03.
//

#include <iostream>
#include <algorithm>
#include <vector>

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

int findRoot(int root[], int x) {
    if (root[x] != x) {
        root[x] = findRoot(root, root[x]);
    }
    return root[x];
}

void unionRoot(int root[], int a, int b) {
    a = findRoot(root, a);
    b = findRoot(root, b);
    if (a < b) {
        root[b] = a;
    } else {
        root[a] = b;
    }
}

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    
    vector<Edge> v;
    int root[N+1];
    for (int i = 1; i <= N; i++) {
        root[i] = i;
    }
    
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        v.push_back(Edge(A, B, C));
    }
    
    sort(v.begin(), v.end());
    
    int max = 0;
    int result = 0;
    for(Edge edge: v) {
        int node1 = edge.node[0];
        int node2 = edge.node[1];
        int distance = edge.distance;
        
        if (findRoot(root, node1) != findRoot(root, node2)) {
            unionRoot(root, node1, node2);
            if (distance > max) {
                max = distance;
            }
            result += distance;
        }
    }
    
    cout << result - max;
}
/*
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4
*/
