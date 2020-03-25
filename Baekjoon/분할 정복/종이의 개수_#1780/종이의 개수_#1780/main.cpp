//
//  main.cpp
//  종이의 개수_#1780
//
//  Created by 원현식 on 2020/03/25.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int a[2188][2188];
int countNumber[3]; // -1 0 1

bool check(int x,int y, int n) {
    int firstValue = a[x][y];
    
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (a[i][j] != firstValue) return false;
        }
    }
    
    return true;
}

void divide(int x, int y, int n) {
    if (check(x, y, n) == true) {
        countNumber[a[x][y]+1]++;
        return;
    }
    
    int M = n/3;
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            divide(x + M*i, y + M*j, M);
        }
    }
    
}


int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    
    divide(1, 1, N);
    
    for (int i = 0; i < 3; i++) {
        cout << countNumber[i] << '\n';
    }
    
}
