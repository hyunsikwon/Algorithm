//
//  main.cpp
//  행렬_#1080
//
//  Created by 원현식 on 2020/03/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int A[50][50];
int B[50][50];
int N,M;
int cnt = 0;

void operate(int n, int m) {
    cnt++;
    int x = n+3;
    int y = m+3;
    
    for (int i = n; i < x; i++) {
        for (int j = m; j < y; j++) {
            if (A[i][j] == 1) {
                A[i][j] = 0;
            } else {
                A[i][j] = 1;
            }
        }
    }
}

bool isSame() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) return false;
            
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    // A
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < a.length(); j++) {
            A[i][j] = a[j] - '0';
        }
    }
    
    // B
    for (int i = 0; i < N; i++) {
        string b;
        cin >> b;
        for (int j = 0; j < b.length(); j++) {
            B[i][j] = b[j] - '0';
        }
    }
    
    for (int i = 0; i <= N-3; i++) {
        for (int j = 0; j <= M-3; j++) {
            if (A[i][j] != B[i][j]) {
                operate(i, j);
            }
        }
    }
    
    if (isSame()) {
        cout << cnt;
    } else {
        cout << -1;
    }
}
