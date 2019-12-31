//
//  main.cpp
//  A-B
//
//  Created by 원현식 on 2019/12/25.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
// 1008

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    double a,b;
    
    cin >> a >> b;
    
    cout.fixed; // 소수점 고정
    cout.precision(15); //15번째 자리까지 출력
    cout << a/b << endl;
    
}
