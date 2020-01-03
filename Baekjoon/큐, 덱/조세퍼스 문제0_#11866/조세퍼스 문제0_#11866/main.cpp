//
//  main.cpp
//  조세퍼스 문제0_#11866
//
//  Created by 원현식 on 2020/01/03.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    int josephus[n];
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    int a;
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            int a = q.front();
            q.pop();
            q.push(a);
        }
        josephus[a++] = q.front();
        q.pop();
    }
    
    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            cout << josephus[i];
        } else {
            cout << josephus[i] << ", ";
        }
    }
    cout << ">" << '\n';
    
    
    
    
}
