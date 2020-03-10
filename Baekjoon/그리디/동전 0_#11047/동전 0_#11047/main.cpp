//
//  main.cpp
//  동전 0_#11047
//
//  Created by 원현식 on 2020/03/10.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> A;

int main(int argc, const char * argv[]) {
    int N,K;

    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        A.push(a);
    }
    
    int count = 0;
    while (K != 0 && !A.empty()) {
        int top = A.top();
        A.pop();
        while (K >= top) {
            K -= top;
            count++;
        }
        
    }

    cout << count << '\n';
    
}
