//
//  main.cpp
//  전깃줄_#2565
//
//  Created by 원현식 on 2020/01/19.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//
// 나의 생각: 부분 수열이 증가 수열이면 교차하지 않는다. 전체 수열 크기에서 가장 큰 증가 수열의 크기를 빼면 된다.

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int wires;
    cin >> wires;
    
    int A[501];
    int dp[501];
    
    int lastNum = 0;
    
    for (int i = 1; i <= wires; i++) {
        int a,b;
        cin >> a >> b;
        if (a > lastNum) { // 연결이 있는 위치 중 가장 끝 번호.
            lastNum = a;
        }
        A[a] = b;
    }
    
    for (int i = 1; i <= lastNum; i++) {
        if (A[i] == 0) { // 연결이 없는 위치
            dp[i] = 0;
        } else { // 연결이 존재하는 위치
            dp[i] = 1;
        }
    }
    
    int maxValue = dp[1];
    for (int i = 2; i <= lastNum; i++) {
        int j = i - 1;
        while (j >= 1) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            j--;
        }
        
        // 최대 크기의 부분 증가 수열 찾기
        if (dp[i] > maxValue) {
            maxValue = dp[i];
        }
    }
    
    cout << wires - maxValue << '\n';
    
}
