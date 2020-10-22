//
//  main.cpp
//  올바른 괄호_cpp
//
//  Created by 원현식 on 2020/10/22.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    stack<char> stk;
    
    for(char c: s) {
        if(c == '(') {
            stk.push(c);
        } else {
            if(stk.empty()) return false;
            stk.pop();
        }
        
    }
    
    return stk.empty() ? true : false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
