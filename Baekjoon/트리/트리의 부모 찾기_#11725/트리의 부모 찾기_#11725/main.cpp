//
//  main.cpp
//  트리의 부모 찾기_#11725
//
//  Created by 원현식 on 2020/02/29.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 노드의 개수
vector<int> tree[100001];
queue<int> q;
int myParentIs[100001] = {0,};

void bfs(int start) {
    q.push(start); // 무조건 1
    myParentIs[start] = 1; // 자기 자신
    
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        
        for (int i = 0; i < tree[parent].size(); i++) {
            int child = tree[parent][i];
            
            if (myParentIs[child] == 0) {
                q.push(child);
                myParentIs[child] = parent;
            }
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    bfs(1);
    
    for (int i = 2; i <= N; i++) {
        cout << myParentIs[i] << '\n';
    }
    
}
