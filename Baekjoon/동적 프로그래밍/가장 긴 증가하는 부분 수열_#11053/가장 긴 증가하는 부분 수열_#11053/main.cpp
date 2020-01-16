//
//  main.cpp
//  가장 긴 증가하는 부분 수열_#11053
//
//  Created by 원현식 on 2020/01/16.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

// 가장 길고, 증가하는 부분 수열의 크기가 정답.
// 10 20 10 30 20 50
// 10 20 30 50 - 정답: 4

#include <iostream>
#include <algorithm>

using namespace std;

int A[1001]; // - 메인 수열
int memo[1001]; // - 처음 ~ 현재 위치까지에서의 증가 부분 수열의 길이

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        A[i] = value;
    }
    
    for (int i = 0; i < N; i++) {
        memo[i] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        int j = i - 1;
        while (j >= 0) {
            if (A[i] > A[j]) {
                memo[i] = max(memo[i],memo[j] + 1);
            }
            j--;
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        if(memo[i] > max) max = memo[i];
    }
    
    cout << max << '\n';
    
}


