//
//  main.cpp
//  8진수 2진수_#1212
//
//  Created by 원현식 on 2020/02/01.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string octalNumber; // 8진수
vector<int> v;
stack<int> s;

int main(int argc, const char * argv[]) {
    cin >> octalNumber;
    
    for (int i = 0; i < octalNumber.length(); i++) {
        int a = octalNumber[i] - '0';

        while (a > 0) {
            s.push(a%2);
            a /= 2;
        }

        if(i > 0){
            if (s.size() == 2) {
                s.push(0);
            } else if (s.size() == 1){
                s.push(0);
                s.push(0);
            } else if (s.size() == 0){ // 중간이 0일때 101 -> 1000001
                s.push(0);
                s.push(0);
                s.push(0);
            }
        }

        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

    }
    
    
    if (v.empty()) {
        cout << 0;
        
    } else {
        int j = 0;
        while (v[j] == 0) { // 01 -> 001 --> 1
            j++;
        }
        
        for (int i = j; i < v.size(); i++) {
            cout << v[i];
        }
        
    }
}
