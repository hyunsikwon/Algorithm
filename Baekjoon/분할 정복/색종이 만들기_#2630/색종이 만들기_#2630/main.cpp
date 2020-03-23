//
//  main.cpp
//  색종이 만들기_#2630
//
//  Created by 원현식 on 2020/03/23.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int a[129][129];
int blue, white;


// MARK: 모두 같은색인지 체크
int check(int x, int y, int n, int m) {
        
    int firstValue = a[x][y];
    
    for (int i = x; i <= n; i++) {
        for (int j = y; j <= m; j++) {
            if (a[i][j] != firstValue) {
                return -1;
            }
        }
    }
    return firstValue; // 0이면 white, 1이면 blue
}

// MARK: 분할 정복
void divide(int x, int y, int n, int m) {
    int result = check(x, y, n, m);
    if (result != -1) {
        if (result == 1) {
            blue++;
        } else {
            white++;
        }
        return;
    }
    

    int move = ((n - x) + 1)/2;
    
    
    divide(x, y, n - move, m - move);
    
    divide(x, y + move, n - move, m);
    
    divide(x + move, y, n, m - move);
    
    divide(x + move, y + move, n, m);
    
    
}

// MARK: 메인
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    
    divide(1, 1, N, N);
    
    cout << white << '\n' << blue;
}
