//
//  main.cpp
//  가장 긴 바이토닉 부분 수열_#11054
//
//  Created by 원현식 on 2020/01/19.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//
// 나의 생각: 특정 값의 증가 수열, 감소 수열의 원소 갯수를 모두 구해서 합이 최대인 것을 구해보자.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    int A[1001];
    int dp[1001][2]; // [a][0]은 증가 수열 크기 [a][1]은 감소 수열 크기
    
    cin >> N;
    
    dp[0][0] = 1; // 증가 수열의 크기를 구할 때 첫번째 값은 무조건 1
    dp[N-1][1] = 1; // 감소 수열의 크기를 구할 때 마지막 값은 무조건 1
    
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        A[i] = v;
    }
    
    // 증가 수열 계산
    for (int i = 1; i < N; i++) {
        int j = i - 1;
        dp[i][0] = 1;
        while (j >= 0) {
            if (A[i] > A[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            j--;
        }
    }
    
    // 감소 수열 계산. 위의 for문 거꾸로 계산
    for (int i = N - 2; i >= 0; i--) {
        int j = i + 1;
        dp[i][1] = 1;
        while (j < N) {
            if (A[i] > A[j]) {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
            j++;
        }
    }
    
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i][0] + dp[i][1] > max) max = dp[i][0] + dp[i][1];
    }
    
    cout << max - 1 << '\n'; // 증감 수열에서 기준값은 중복되어 계산되므로 -1
    
    // dp값 확인용 출력
    //    for (int i = 0; i < N; i++) {
    //        cout << dp[i][0] << ' ';
    //    }
    //    cout << '\n';
    //
    //    for (int i = 0; i < N; i++) {
    //        cout << dp[i][1] << ' ';
    //    }
    //
    
    
}
