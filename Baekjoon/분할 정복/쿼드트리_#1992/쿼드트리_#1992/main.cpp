//
//  main.cpp
//  쿼드트리_#1992
//
//  Created by 원현식 on 2020/03/24.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int a[65][65];

int check(int x, int y, int n, int m) {
    
    int firstValue = a[x][y];

    for (int i = x; i <= n; i++) {
        for (int j = y; j <= m; j++) {
            if (a[i][j] != firstValue) {
                return -1;
            }
        }
    }
    
    return firstValue;
}

void divide(int x, int y, int n, int m) {
    
    int result = check(x, y, n, m);
    if (result != -1) {
        if (result == 1) {
            cout << result;
        } else {
            cout << result;
        }
        return;
    }
    cout << "(";
    
    int move = ((n - x) + 1)/2;
    
    divide(x, y, n - move, m - move);
    
    divide(x, y + move, n - move, m);
    
    divide(x + move, y, n, m - move);
    
    divide(x + move, y + move, n, m);
    
    cout << ")";
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= str.length(); j++) {
            int value =  str[j-1] - '0';
            a[i][j] = value;
        }
    }
    
    divide(1, 1, N, N);

    
}
