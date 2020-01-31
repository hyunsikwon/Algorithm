//
//  main.cpp
//  최소공배수_#1934
//
//  Created by 원현식 on 2020/01/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int A,B,T;
int leastCommonMultiple;

int greatestCommonFactor(int a, int b) {
    int smaller = a < b ? a : b;
    int gcf;
    
    for (int i = smaller; i >= 1; i--) {
        if ((a % i) == 0 && (b % i) == 0) {
            gcf = i;
            break;
        }
    }
    return gcf;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        cout << (A*B)/greatestCommonFactor(A, B) << '\n';
    }
}
