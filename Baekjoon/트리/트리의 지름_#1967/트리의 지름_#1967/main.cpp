//
//  main.cpp
//  트리의 지름_#1967
//
//  Created by 원현식 on 2020/03/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int, int>> tree[10001];
bool visited[10001];
int finalDistance[10001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int parentNode = q.front();
        q.pop();
        
        for (int i = 0; i < tree[parentNode].size(); i++) {
            int child = tree[parentNode][i].first;
            int distance = tree[parentNode][i].second;
            
            if (visited[child] == false) {
                visited[child] = true;
                q.push(child);
                
                finalDistance[child] = finalDistance[parentNode] + distance;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for (int i = 1; i < n ; i++) {
        int parent, child, distance;
        cin >> parent >> child >> distance;
        
        tree[parent].push_back(make_pair(child, distance));
        tree[child].push_back(make_pair(parent, distance));
    }
    
    bfs(1);

    int max = 0;
    int newRoot = 0;
    for (int i = 1; i <= n; i++) {
        if (finalDistance[i] > max) {
            newRoot = i;
            max = finalDistance[i];
        }
        
        finalDistance[i] = 0;
        visited[i] = false;
    }

    bfs(newRoot);
    
    max = 0;
    for (int i = 1; i <= n; i++) {
        if (finalDistance[i] > max) {
            max = finalDistance[i];
        }
    }
    
    cout << max;
}
