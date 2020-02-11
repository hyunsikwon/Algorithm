//
//  main.cpp
//  팩토리얼_#10872
//
//  Created by 원현식 on 2020/02/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int N;

int factorial(int n) {
    if (n <= 1) return 1;
    return n*factorial(n-1);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    cout << factorial(N) << '\n';
    
}
