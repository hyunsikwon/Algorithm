//
//  main.cpp
//  1로 만들기_cpp
//
//  Created by 원현식 on 2020/09/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int X;
    cin >> X;
    int dp[X+1];
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 1;
    
    for(int i = 6; i <= X; i++) {
        dp[i] = dp[i-1] + 1;
        
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        
        if (i % 5 == 0) {
            dp[i] = min(dp[i], dp[i/5] + 1);
        }
        
        
    }

    cout << dp[X];
}
