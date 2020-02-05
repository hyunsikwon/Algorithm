//
//  main.cpp
//  소수 찾기_#1978
//
//  Created by 원현식 on 2020/02/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int N,v;
int count_primeNum;

bool isPrimeNum(int a) {
    if (a == 1) return false;
    
    for (int i = 2; i < a ; i++) { // 1과 자기 자신은 제외.
        if ((a % i) == 0) return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> v;
        if (isPrimeNum(v)) count_primeNum++;
    }
    
    cout << count_primeNum;
    
}
