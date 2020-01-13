//
//  main.cpp
//  정수 삼각형_#1932
//
//  Created by 원현식 on 2020/01/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int value[502][502] = {0,}; // 입력 값
    int accumulated[502][502] = {0,}; // 누적 값
    
    // i는 n번째 줄을 나타냄. 편의상 1부터..
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int a;
            cin >> a;
            value[i][j] = a;
        
        }
    }
    
    accumulated[1][0] = value[1][0];
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0) {
                //맨 앞이면 선택지는 하나 -- 윗줄의 맨 앞
                accumulated[i][0] = value[i][j] + accumulated[i-1][0];
            } else if (j == (i - 1)) {
                // 맨 뒤면 선택지는 하나 -- 윗줄의 맨 뒤
                accumulated[i][j] = value[i][j] + accumulated[i-1][j-1];
            } else {
                // 대각선 위 두개의 값중에 큰 값을 선택해야 함
                accumulated[i][j] = value[i][j] + max(accumulated[i-1][j-1],accumulated[i-1][j]);
            }
        }
    }

    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (accumulated[n][i] > max) {
            max = accumulated[n][i];
        }
    }

    cout << max << '\n';

    // 확인용
    //    for (int i = 1; i <= n; i++) {
    //        for (int j = 0; j < i; j++) {
    //            cout << accumulated[i][j] << ' ';
    //        }
    //        cout << '\n';
    //    }
        

}
