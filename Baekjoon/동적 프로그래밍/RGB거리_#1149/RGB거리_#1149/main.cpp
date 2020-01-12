//
//  main.cpp
//  RGB거리_#1149
//
//  Created by 원현식 on 2020/01/12.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int cost[1002][3] = {0,};
    int result[1002][3] = {0,}; // 누적 비용..
    
    //편의상 1부터 시작.
    for (int i = 1 ; i <= N ; i++ ) {
        int red,green,blue;
        cin >> red >> green >> blue;
        cost[i][0] = red;
        cost[i][1] = green;
        cost[i][2] = blue;
    }
    
    result[0][0] = 0; result[0][1] = 0; result[0][2] = 0;
    
    for (int i = 1; i <= N; i++) {
        result[i][0] = min(result[i-1][1], result[i-1][2]) + cost[i][0];
        result[i][1] = min(result[i-1][0], result[i-1][2]) + cost[i][1];
        result[i][2] = min(result[i-1][0], result[i-1][1]) + cost[i][2];
    }
    
    cout << min(min(result[N][0],result[N][1]),result[N][2]) << '\n';
    
}
