//
//  main.cpp
//  피보나치 수2_#2748
//
//  Created by 원현식 on 2020/01/10.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

//fibonacci(90) 의 값이 int형의 범위를 넘기 때문에 long 혹은 long long타입을 써줘야 한다.

long long a[92] = {0,};


long long fibonacci(int n) {
    if (n == 1 || n == 2) return 1;

    if (a[n] != 0) return a[n];
    else a[n] = fibonacci(n-1) + fibonacci(n-2);

    return a[n];
}

int main(void) {
    int n;
    
    cin >> n;
    cout << fibonacci(n) << '\n';

}
