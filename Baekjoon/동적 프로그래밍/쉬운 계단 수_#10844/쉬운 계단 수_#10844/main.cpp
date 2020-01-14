//
//  main.cpp
//  쉬운 계단 수_#10844
//
//  Created by 원현식 on 2020/01/14.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N; // 1 <= N <= 100
    cin >> N;
    
    long long a[101][11];
    
    for (int i = 1; i <= 9; i++) {
        a[1][i] = 1;
    }
    
    for (int i = 2; i <= N ; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                a[i][0] = (a[i - 1][1])% 1000000000;
            } else if (j == 9) {
                a[i][9] = (a[i-1][8]) % 1000000000;
            } else {
                a[i][j] = (a[i-1][j-1] + a[i-1][j+1]) % 1000000000;
            }
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += a[N][i];
    }
    
    cout << sum % 1000000000 << '\n';
    
    
    
}
