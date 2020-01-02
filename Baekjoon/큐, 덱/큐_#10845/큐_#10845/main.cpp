//
//  main.cpp
//  큐_#10845
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
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        if(str == "push") {
            int a;
            cin >> a;
            q.push(a);
            
        } else if (str == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
            
        } else if (str == "size") {
            cout << q.size() << '\n';
            
        } else if (str == "empty") {
            if (q.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
            
        } else if (str == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
            
        } else if (str == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
            
        } else {
            break;
        }
        
    }
    
    
}
