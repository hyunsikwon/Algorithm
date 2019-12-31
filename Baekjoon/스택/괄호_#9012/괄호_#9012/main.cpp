//
//  main.cpp
//  괄호_#9012
//
//  Created by 원현식 on 2019/12/26.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>


using namespace std;


bool isVPS(string str) {
    stack<char> s;
    
    for (int i = 0; i < str.length(); i++) {
        char a = str[i];
        
        if(a == '(') {
            s.push(a);
            
        } else if (a == ')' && !s.empty()) {
            s.pop();
            
        } else { return false; }
        
    }
    
    return s.empty();
}

int main(void) {
    
    int n;
    cin >> n;

    string parenthesisString;

    for (int i = 0; i < n; i++) {
        cin >> parenthesisString;
        bool result = isVPS(parenthesisString);

        if(result) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    
}

