//
//  main.cpp
//  DFS와 BFS_#1260
//
//  Created by 원현식 on 2020/02/15.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[1001];
queue<int> q;
bool visited[1001];
int N,M,V; // 정점의 갯수, 간선의 갯수, 탐색 시작 번호

//MARK: - DFS
void dfs(int start) { // depth first. stack 사용 -> 재귀 함수 이용
    
    cout << start << ' ';
    visited[start] = true;
    for (int i = 0; i < a[start].size(); i++) {
        int child = a[start][i];
        if (!visited[child]) {
            dfs(child);
        }
    }
}

//MARK: - BFS
void bfs(int start) { // breadth first. queue 사용
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int front = q.front();
        cout << front << ' ';
        q.pop();
        
        for (int i = 0; i < a[front].size(); i++) {
            int child = a[front][i];
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
        
        
    }
}

//MARK: - MAIN
int main(int argc, const char * argv[]) {
    cin >> N >> M >> V;
    
    for (int i = 0; i < M; i++) {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        
    }
    
    for (int i = 0; i < N; i++) {
        sort(a[i].begin(), a[i].end());
    }
  
    
    dfs(V);
    cout << '\n';
    fill(visited, visited + N + 1, false);
    bfs(V);
    
}
