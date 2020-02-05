//
//  main.cpp
//  Base Conversion_#11576
//
//  Created by 원현식 on 2020/02/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int A,B,m;
int a[26];
stack<int> s;

int main(int argc, const char * argv[]) {
    cin >> A >> B;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    long long num = A*a[0] + a[1];
    for (int i = 2; i < m; i++) {
        num = A*num + a[i];
    }
    
    while (num > 0) {
        s.push(num%B);
        num /= B;
    }
    
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

}
