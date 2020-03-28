//
//  main.cpp
//  곱셈_#1629
//
//  Created by 원현식 on 2020/03/28.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

long long int multiply(int a, int b, int c) {
    if (b == 0) return 1;
    
    long long int n = multiply(a, b/2, c);
    long long temp = (n * n) % c;

    if (b % 2 == 0) {
        return temp;
    } else {
        return (a*temp) % c;
    }

}

int main(int argc, const char * argv[]) {
    int A, B, C;
    cin >> A >> B >> C;

    cout << multiply(A, B, C) << '\n';
  
}
