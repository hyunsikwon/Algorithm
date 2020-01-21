//
//  main.cpp
//  LCS_#9251
//
//  Created by 원현식 on 2020/01/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str1;
    string str2;
    int dp[1001][1001];
    
    cin >> str1 >> str2;
    
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[str1.size()][str2.size()] << '\n';
}
