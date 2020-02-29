//
//  main.cpp
//  이분 그래프_#1707
//
//  Created by 원현식 on 2020/02/28.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define RED  1
#define BLUE 2

using namespace std;

vector<int> graph[20001];
int checkColor[20001] = {0,};
int T,V,E; //test case, 정점, 간선 개수
queue<int> q;

void bfs(int s) {
    int color = RED;
    q.push(s);
    checkColor[s] = color;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
      
        if (checkColor[current] == RED) {
            color = BLUE;
            
        } else if (checkColor[current] == BLUE){
            color = RED;
        }
        
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            
            if (checkColor[next] == 0) {
                checkColor[next] = color;
                q.push(next);
            }
        }
        
    }
    
}

bool checkBipartite() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int c = graph[i][j];
            if (checkColor[i] == checkColor[c]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> V >> E;

        for (int i = 1; i <= E; i++) {
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= V ; i++) {
            if (checkColor[i] == 0) {
                bfs(i);
            }
        }

        // 이분그래프인지 아닌지 확인 후 출력
        if (checkBipartite()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

        //초기화
        for (int i = 0; i <= V; i++) {
            checkColor[i] = 0;
            graph[i].clear();
        }

    }

}
