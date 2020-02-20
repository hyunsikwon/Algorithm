//
//  main.cpp
//  미로 탐색_#2178
//
//  Created by 원현식 on 2020/02/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int N,M; // N × M 배열
int route[101][101];
string data;
queue<pair<int, int>> q;


void bfs(int i,int j,int m, int n) {
    q.push(make_pair(i, j));

    while (!q.empty()) {
        int qI = q.front().first;
        int qJ = q.front().second;
        q.pop();
        
        if (qI == (n-1) && qJ == (m-1)) break;

        if (qI > 0 && route[qI-1][qJ] == 1 ) {
            q.push(make_pair(qI-1, qJ));
            route[qI-1][qJ] = route[qI][qJ] + 1;
        }
        
        if (qI < n - 1 && route[qI+1][qJ] == 1 ) {
            q.push(make_pair(qI+1, qJ));
            route[qI+1][qJ] = route[qI][qJ] + 1;

        }

        if (qJ > 0 && route[qI][qJ-1] == 1 ) {
            q.push(make_pair(qI, j-1));
            route[qI][qJ-1] = route[qI][qJ] + 1;

        }

        if (qJ < m - 1 && route[qI][qJ+1] == 1 ) {
            q.push(make_pair(qI, qJ+1));
            route[qI][qJ+1] = route[qI][qJ] + 1;

        }

    }
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> data;
        for (int j = 0; j < data.length(); j++) {
            route[i][j] = data[j] - '0';
        }
    }
    
    bfs(0,0,M,N);
    
    cout << route[N-1][M-1] << '\n';
    
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cout << route[i][j];
//        }
//        cout << '\n';
//    }
}

