//
//  main.cpp
//  유기농 배추_#1012
//
//  Created by 원현식 on 2020/02/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int T,M,N,K;
int X,Y;
int a[51][51];
bool visit[51][51];
int earthworms;

// 초기화
void initilize(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
            visit[i][j] = false;
        }
        
    }
}

// 조건 검색
bool check(int i, int j) {
    if (visit[i][j] == false && a[i][j] == 1) {
        return true;
    }
    
    return false;
}

void dfs(int i, int j, int m, int n){
    visit[i][j] = true;
    
    if (i < m - 1 && check(i+1, j)) {
        dfs(i+1, j, m, n);
    }
    
    if (i > 0 && check(i-1, j)) {
        dfs(i-1, j, m, n);
    }
    
    if (j < n - 1 && check(i, j+1)) {
        dfs(i, j+1, m, n);
    }
    
    if (j > 0 && check(i, j-1)) {
        dfs(i, j-1, m, n);
    }
}

int main(int argc, const char * argv[]) {
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K; // 가로, 세로, 배추가 심어진 위치의 수
        
        
        for (int j = 0; j < K; j++) {
            cin >> X >> Y; // 배추가 심어진 위치.
            a[X][Y] = 1;
        }
        
        earthworms = 0;
        for (int k = 0; k < M; k++) {
            for (int l = 0; l < N; l++) {
                if (check(k, l)) {
                    dfs(k,l, M, N);
                    earthworms++;
                }
            }
        }
        
        cout << earthworms << '\n';
        
        // 배열 초기화
        initilize(M, N);
        
    }
    
}
