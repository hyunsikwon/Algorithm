//
//  main.cpp
//  카드2_#2164
//
//  Created by 원현식 on 2020/01/02.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    queue<int> q;
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    while (q.size() > 1) {
        q.pop();
        int a = q.front();
        q.pop();
        q.push(a);
    }
    
    cout << q.front() << '\n';
    
}
