//
//  main.cpp
//  GCD 합_#9613
//
//  Created by 원현식 on 2020/01/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int T,n;

int greatestCommonDivsor(int a, int b) {
    int smaller = a < b ? a : b;
    int gcd = 0;
    for (int i = smaller; i >= 1; i--) {
        if ((a % i) == 0 && (b % i) == 0) {
            gcd = i;
            break;
        }
    }
    
    return gcd;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> n;
        int a[n];
        long sum = 0;
        
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        for (int k = 0; k < n - 1; k++) {
            for (int l = k + 1; l < n; l++) {
                sum += greatestCommonDivsor(a[k], a[l]);
            }
        }
        
        cout << sum << '\n';
    }
    
}
