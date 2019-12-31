//
//  main.cpp
//  균형잡힌 세상_#4949
//
//  Created by 원현식 on 2019/12/30.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    int length = str.length();
    
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[') { // 무조건 스택에
            s.push(str[i]);
            
        } else if ((str[i] == ')'|| str[i] == ']') && !s.empty()) { // 스택이 비어있지 않고 str[i]가 ) or ]
            if(s.top() == '(' && str[i] == ')') { // 합이 맞으면 s.pop
                s.pop();
            } else if (s.top() == '[' && str[i] == ']') { // 합이 맞으면 s.pop
                s.pop();
            } else { // 합이 안맞을때.
                return false; //짝이 안맞을때 (], [)
            }
        } else if ((str[i] == ')'|| str[i] == ']') && s.empty()) {
            return false;
        }
    }
    
    return s.empty();
}


int main(void) {
    
    string n;
    
    while(n != ".") {
        getline(cin,n);
        
        if (n == ".") break;
        
        bool result = isBalanced(n);
    
        if (result) cout << "yes" << endl;
        else cout << "no" << endl;

    }
    
}
// ---------------------------
//cin을 사용한 연속된 문자열 입력시 공백 처리
//cin 을 연속으로 사용하여 2번의 문자열을 받을 때 공백을 만나면 다음 cin의 변수로 데이터가 넘어간다.
//예를들어, I'm Hyunsik 을 입력하면,  I'm 은 첫번째 변수에 Hyunsik은 두번째 변수에 들어간다.
//공백처리를 하지 못하게 된다.
//이러한 문제를 해결하기 위하여, 문자열을 입력받을 때 getline() 함수를 사용한다.
