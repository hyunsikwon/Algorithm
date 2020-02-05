//
//  main.cpp
//  소수_#2581
//
//  Created by 원현식 on 2020/02/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int M,N;
int sum = 0;
int minValue = 10001;

bool isPrimeNum(int a) {
    if (a == 1) return false;
    
    for (int i = 2; i < a ; i++) {
        if ((a % i) == 0) return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (isPrimeNum(i)) {
            if (i < minValue) {
                minValue = i;
            }
            sum += i;
        }
    }

    if (sum == 0) cout << -1 << '\n';
    else cout << sum << '\n' << minValue << '\n';
    
}
