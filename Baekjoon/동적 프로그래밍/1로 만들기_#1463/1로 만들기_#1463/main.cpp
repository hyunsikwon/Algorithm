//
//  main.cpp
//  1로 만들기_#1463
//
//  Created by 원현식 on 2020/01/14.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//
// 1. N이 3으로 나누어 떨어지면 3으로 나눈다.
// 2. N이 2로 나누어 떨어지면, 2로 나눈다
// 3. 1을 뺀다.

// 출력: 1로 만드는데 사용하는 연산의 횟수의 최솟값.
// Hint: 10 -> 9 -> 3 -> 1

#include <iostream>
#include <algorithm>

using namespace std;

int a[1000002] = {0,};

int dp(int i) {
    if (i < 4) return a[i];
    if (a[i] > 0) return a[i];
    
    if((i % 3 == 0) && (i % 2 == 0)) { // case4
        a[i] = min(1 + dp(i/3),1 + dp(i/2));
        
    } else if(i % 3 == 0) { // case1
        a[i] = min(1 +dp(i/3),1 + dp(i-1));
        
    } else if(i % 2 == 0) { // case2
        a[i] = min(1 + dp(i/2),1 + dp(i-1));
        
    } else { // case3
        a[i] = 1 + dp(i-1);
    }
    
    return a[i];
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    //    a[4] = min(1 + a[3], 1 + a[2]);
    //    a[5] = 1 + a[4];
    //    a[6] = min(1 + a[2], 1 + a[3]);
    
    cout << dp(N) << '\n';
    
}


