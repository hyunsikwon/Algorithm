//
//  main.cpp
//  피보나치 함수_#1003
//
//  Created by 원현식 on 2020/01/10.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int a[42] = {0,};

int fibonacci(int n) {
    if (a[n] != 0) return a[n];
    if (n == 0) {
        a[n] = 0;
    } else if(n == 1) {
        a[n] = 1;
    } else {
        a[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return a[n];
}

int main(int argc, const char * argv[]) {
    int T,N;
    
    cin >> T;
    //
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N == 0) {
            cout << 1 << ' ' << 0 << '\n';
        } else {
            cout << fibonacci(N-1) << ' ' << fibonacci(N) << '\n';
        }
        
    }
    
}
