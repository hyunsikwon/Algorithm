//
//  main.cpp
//  팩토리얼 0의 개수_#1676
//
//  Created by 원현식 on 2020/02/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int fiveCount,twoCount;


int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 2; i <= N; i *= 2) {
        twoCount += N / i;
    }
    for (int i = 5; i <= N; i *= 5) {
        fiveCount += N / i;
    }
    
    int result = twoCount < fiveCount ? twoCount : fiveCount;

    cout << result;
    
}

