//
//  main.cpp
//  트리의 지름_#1167
//
//  Created by 원현식 on 2020/02/29.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V;
vector<pair<int, int>> tree[100001];
queue<int> q;
bool visited[100001];
int finalDistance[100001];

void bfs(int start) {

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int i = 0; i < tree[currentNode].size(); i++) {
            int child = tree[currentNode][i].first;
            int distance = tree[currentNode][i].second;
            
            if (visited[child] == false) {
                q.push(child);
                visited[child] = true;
                finalDistance[child] = finalDistance[currentNode] + distance;
            }
        }
    }

}



int main(int argc, const char * argv[]) {
    cin >> V;

    // 트리 생성
    for(int i = 0; i < V; i++) {
        int node1, node2, distance;
        cin >> node1;

        while (1) {
            cin >> node2;
            if (node2 == -1) break;

            cin >> distance;
            tree[node1].push_back(make_pair(node2,distance));
            
        }
    }
    
    // 루트 노트 찾기
    bfs(1);
    int root = 1;
    for (int i = 2; i <= V; i++) { // 1부터 가장 먼 곳이 루트.
        if (finalDistance[i] > finalDistance[root]) {
            root = i;
        }
    }
    
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
        finalDistance[i] = 0;
    }
    
    // 루트 노드로 bfs
    bfs(root);
    
    // max값 찾기
    int max = 0;
    for (int i = 1; i <= V; i++) {
        if (finalDistance[i] > max) {
            max = finalDistance[i];
        }
    }
    
    cout << max << '\n';

}



