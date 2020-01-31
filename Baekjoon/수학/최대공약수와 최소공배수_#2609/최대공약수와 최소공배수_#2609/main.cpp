//
//  main.cpp
//  최대공약수와 최소공배수_#2609
//
//  Created by 원현식 on 2020/01/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int a,b;
int greatestCommonFactor;
int leastCommonMultiple;

int main(int argc, const char * argv[]) {
    cin >> a >> b;
    
    int smaller = a < b ? a : b;
    
    for (int i = 1; i <= smaller; i++) {
        if ((a % i) == 0 && (b % i) == 0) {
            greatestCommonFactor = i;
        }
    }
    
    leastCommonMultiple = (a*b)/greatestCommonFactor;
    
    cout << greatestCommonFactor << '\n';
    cout << leastCommonMultiple << '\n';
    
}
