//
//  main.cpp
//  바닥 공사_cpp
//
//  Created by 원현식 on 2020/09/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N; // 가로 길이, 세로 길이 = 2
    cin >> N;
    
    // 1X2, 2X1, 2X2 로 2XN 크기의 바닥을 덮는 방법의 수
    // % 796796 값 출력
    
    int dp[1001];
    
    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]*2) % 796796;
    }
    
    cout << dp[N];
    
    
}
