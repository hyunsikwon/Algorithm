//
//  main.cpp
//  특정 거리의 도시 찾기_cpp
//
//  Created by 원현식 on 2020/10/11.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[300001];
vector<int> graph[300001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int front = q.front(); q.pop();
        
        for (int i = 0; i < graph[front].size(); i++) {
            int child = graph[front][i];
            
            if (dist[child] == -1) {
                dist[child] = dist[front] + 1;
                q.push(child);
            }
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    
    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }
    
    bfs(X);
    
    bool check = true;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << '\n';
            check = false;
        }
    }
    
    if (check) {
        cout << -1;
    }
    
}
