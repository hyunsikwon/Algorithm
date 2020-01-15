//
//  main.cpp
//  포도주 시식_#2156
//
//  Created by 원현식 on 2020/01/15.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int wine[10001];
int memo[10001][3] = {0,};

int dp(int i, int j) {
    if (memo[i][j] > 0) return memo[i][j];

    if (i == 1) return wine[1];

    if (i == 2) {
        if (j == 0) return wine[1];
        if (j == 1) return wine[2];
        else return wine[1] + wine[2];
    }

    if (j == 2) {
        return memo[i][2] = dp(i-1,1) + wine[i];
    }

    if (j == 1) {
        return memo[i][1] = dp(i - 1, 0) + wine[i];
    }

    return memo[i][0] = max(max(dp(i-1, 2),dp(i-1, 1)),dp(i-1,0));

}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int q;
        cin >> q;
        wine[i] = q;
    }
    
    cout << max(max(dp(n, 2),dp(n, 1)),dp(n,0)) << '\n';
    
}
