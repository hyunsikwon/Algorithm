//
//  main.cpp
//  덱_#10866
//
//  Created by 원현식 on 2020/01/04.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

int main(void){
    
    deque<int> dq;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string cmd;
        
        cin >> cmd;
        
        if (cmd == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
            
        } else if (cmd == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
            
        } else if(cmd == "pop_front") {
            if (dq.empty()){
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            
        } else if(cmd == "pop_back") {
            if (dq.empty()){
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            
        } else if(cmd == "size") {
            cout << dq.size() << '\n';
            
        } else if(cmd == "empty") {
            if (dq.empty()){
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
                
            }
            
        } else if (cmd == "front") {
            if (dq.empty()){
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
            }
        } else if (cmd == "back") {
            if (dq.empty()){
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
            }
        }
    }
    
    
    
}
