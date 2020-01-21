//
//  main.cpp
//  연속합_#1912
//
//  Created by 원현식 on 2020/01/21.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int a[100001];
    int dp[100001];
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        a[i] = value;
    }
    
    dp[0] = a[0];
    int maxValue = a[0];
    
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1] ) {
            dp[i] = dp[i-1] + a[i];
        } else {
            dp[i] = max(dp[i-1] + a[i], a[i]);
        }
        if (dp[i] > maxValue) {
            maxValue = dp[i];
        }
        
    }
    
    cout << maxValue << '\n';
    
}
