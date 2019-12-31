//
//  main.cpp
//  곱셉_#2588
//
//  Created by 원현식 on 2019/12/26.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//
#include <iostream>

using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    int a,b;
    cin >> a;
    cin >> b;
    
    // b = 385
    int c1 = b % 10; // 5
    int c2 = (b - c1) / 10 ; //38
    int c3 = (c2 - (c2 % 10)) / 10; // 3
    
    
    cout << a * c1 << '\n';
    cout << a * (c2 % 10) << '\n';
    cout << a * c3 << '\n';
    cout << a * b << '\n';

    
}
