//
//  main.cpp
//  토마토_#7576
//
//  Created by 원현식 on 2020/02/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int M,N; //가로 세로
int tomatoHouse[1001][1001];
int lineData;

int main(int argc, const char * argv[]) {
    cin >> M >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lineData;
            tomatoHouse[i][j] = lineData;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << tomatoHouse[i][j] << ' ';
        }
        cout << '\n';
    }

}
