//
//  main.cpp
//  대회 or 인턴_#2875
//
//  Created by 원현식 on 2020/03/16.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N,M,K;
    cin >> N >> M >> K; // 여 남 인턴쉽
    
    int team = 0;
    while (1) {
        if (N - 2 >= 0 && M - 1 >= 0) {
            N -= 2;
            M -= 1;
            team++;
        } else {
            break;
        }
    }

    if (K - (M+N) <= 0) {
        cout << team;
        
    } else {
        int a = K - (M+N); // team에서 a명이 빠져야 함
        // a명을 뺐을 때 구성되는 팀의 수.
        if (a % 3 == 0) {
            team -= (a / 3);
        } else {
            team -= (a/3)+1;
        }
        
        cout << team;
    }

}
